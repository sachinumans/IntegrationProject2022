clear all;
load Exp5_fullSweepFinalCropped.mat

% data = iddata(Meas(2:end, :), CtrlIn(2:end), h);
u = squeeze(CtrlIn.signals.values(2:end));
data = iddata(Meas.signals.values(2:end, :), u, h);
Meas = Meas.signals.values(2:end, :);
CtrlIn = CtrlIn.signals.values(2:end);
Id_init = 3.88E-4;
I_init = 0.0338;

initParam = {'MotorConstant', 1; 'PendInertiaInverse', 1/I_init;...
    'DampCoefDisk', 0.002; 'DampCoefPend', 0.002; 'Mass', 1.5;...
    'COMdiv', 0.05; 'DiskInertiaInverse', 1/Id_init;...
    'MotorResistanceInverse', 1e-3};

Parameters = {-1;1/I_init;0.002;0.002;1.5;0.05;1/Id_init};

sys_init = idnlgrey(@dyns, [2 1 3], Parameters);

% sys_init.Structure.Parameters(1).Minimum = 0;
% sys_init.Structure.Parameters(2).Minimum = 0;
% sys_init.Structure.Parameters(3).Minimum = 0;
% sys_init.Structure.Parameters(4).Minimum = 0;
% sys_init.Structure.Parameters(5).Minimum = 1;
% sys_init.Structure.Parameters(6).Minimum = 0;
% sys_init.Structure.Parameters(7).Minimum = 0;
% 
% sys_init.Structure.Parameters(1).Maximum = 10;
% sys_init.Structure.Parameters(2).Maximum = 100;
% sys_init.Structure.Parameters(3).Maximum = 1;
% sys_init.Structure.Parameters(4).Maximum = 1;
% sys_init.Structure.Parameters(5).Maximum = 2;
% sys_init.Structure.Parameters(6).Maximum = 0.1;
% sys_init.Structure.Parameters(7).Maximum = 10;

% sys_init.Structure.Parameters(6).Free = false;

% Get system
sysEst_dGrey = nlgreyest(data, sys_init);

% Make system continuous and define statespace
sysEst_d = ss(sysEst_dGrey.A, sysEst_dGrey.B, sysEst_dGrey.C, sysEst_dGrey.D, h);
sysEst_d.StateName = {'theta'; 'theta_dot'; 'phi_dot'};
sysEst_d.OutputName = {'theta'; 'phi_dot'};
sysEst_d.InputName = {'Voltage'};
sysEst_d.StateUnit = {'rad'; 'rad/s'; 'rad/s'};
sysEst_d.OutputUnit = {'rad'; 'rad/s'};
sysEst_d.InputUnit = {'V'};

% sysEst = d2c(sysEst_d);

% Unpack estimated parameters
param_ = getpvec(sysEst_dGrey);
param.k = param_(1);
param.I = 1/param_(2);
param.b = param_(3);
param.c = param_(4);
param.m = param_(5);
param.l = param_(6);
param.Id = 1/param_(7);


save Identified_system5 sysEst_d param
% save Identified_system1_data CtrlIn Meas h




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [dx, y] = dyns(t, x, u, k, Ii, b, c, m, l, Idi)
    g = 9.81;
    
    dx = [ x(2);...
        -m*g*l*Ii*sin(x(1)) - c*Ii*x(2) - b*Ii*x(3) - k*Ii*u;...
        -b*Idi*x(3) - k*Idi*u];
    
    y = [x(1); x(3)];
    
end

