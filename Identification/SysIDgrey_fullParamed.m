clear all
load ExtraData_exp1.mat

% data = iddata(Meas(2:end, :), CtrlIn(2:end), h);
u = squeeze(CtrlIn.signals.values(2:end));
data = iddata(Meas.signals.values(2:end, :), u, h);
Meas = Meas.signals.values(2:end, :);
CtrlIn = CtrlIn.signals.values(2:end);
Id_init = 3.88E-4;
I_init = 0.0338;

initParam = {'p11', 0;'p12', 0;'p13', 0;...
    'p21', 0;'p22', 0;'p23', 0;...
    'p31', 0;'p32', 0; 'p33', 0;...
    'p1', 0; 'p2', 0;'p3', 0};

sys_init = idgrey(@dyns, initParam, 'd', Ts=h);

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
% % sys_init.Structure.Parameters(7).Maximum = 100;
% % sys_init.Structure.Parameters(8).Maximum = 100;

% sys_init.Structure.Parameters(6).Free = false;

% Get system
opt = greyestOptions; opt.EnforceStability = 1;
sysEst_dGrey = greyest(data, sys_init, opt);

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
% param.p21 = param_(1);
% param.p22 = param_(2);
% param.p23 = param_(3);
% param.p33 = param_(4);
% param.p2 = param_(5);
% param.p3 = param_(6);


save Identified_system9_extra_data sysEst_d
% save Identified_system1_data CtrlIn Meas h




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [A, B, C, D] = dyns(p11,p12,p13,p21,p22,p23,p31,p32,p33,p1,p2,p3, Ts)
    g = 9.81;
    thetaStar = 0;
    
    Ac = [p11, p12, p13;...
        p21, p22, p23;...
        p31, p32, p33];
    Bc = [p1; p2; p3];
    Cc = [1, 0, 0;...
        0, 0, 1];
    Dc = [0; 0];
    
    sys = ss(Ac,Bc,Cc,Dc);
    dsys = c2d(sys, Ts);
    A = dsys.A;
    B = dsys.B;
    C = dsys.C;
    D = dsys.D;
    
end

