data = iddata(Meas(2:end, :), CtrlIn(2:end), h);
Id_init = 3.88E-4;
I_init = 0.0338;

initParam = {'MotorConstant', 1; 'PendInertiaInverse', 1/I_init; 'DampCoefDisk', 0.002; 'DampCoefPend', 0.002; 'Mass', 1.5; 'COMdiv', 0.05; 'DiskInertiaInverse', 1/Id_init; 'MotorResistanceInverse', 1e-3};

sys_init = idgrey(@dyns, initParam, 'd', Ts=h);

% Get system
opt = greyestOptions; opt.EnforceStability = 1;
sysEst_dGrey = greyest(data, sys_init, opt);

% Make system continuous and define statespace
sysEst_d = ss(sysEst_dGrey.A, sysEst_dGrey.B, sysEst_dGrey.C, sysEst_dGrey.D, h);
sysEst_d.StateName = {'theta'; 'theta_dot'; 'phi_dot'};
sysEst_d.OutputName = {'theta'; 'phi_dot'; 'Current'};
sysEst_d.InputName = {'Voltage'};
sysEst_d.StateUnit = {'rad'; 'rad/s'; 'rad/s'};
sysEst_d.OutputUnit = {'rad'; 'rad/s'; 'A'};
sysEst_d.InputUnit = {'V'};

sysEst = d2c(sysEst_d);

% Unpack estimated parameters
param_ = getpvec(sysEst_dGrey);
param.alph = param_(1);
param.I = 1/param_(2);
param.b = param_(3);
param.c = param_(4);
param.m = param_(5);
param.l = param_(6);
param.Id = 1/param_(7);
param.Rm = 1/param_(8);








%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [A, B, C, D] = dyns(alph, Ii, b, c, m, l, Idi, Rmi, Ts)
    g = 9.81;
    thetaStar = 0;
    
    Ac = [0, 1, 0;...
        -(m*g*l)*Ii * cos(thetaStar), -c*Ii, -b*Ii;...
        0, 0, -b*Idi];
    Bc = [0; -alph*Ii; -alph*Idi];
    Cc = [1, 0, 0;...
        0, 0, 1;...
        0, 0, 0];
    Dc = [0; 0; Rmi];
    
    sys = ss(Ac,Bc,Cc,Dc);
    dsys = c2d(sys, Ts);
    A = dsys.A;
    B = dsys.B;
    C = dsys.C;
    D = dsys.D;
    
end

