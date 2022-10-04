clear all;

load Data\grey_MotorID_ramp_cropped.mat

Id_init = 3.88E-4;

u = squeeze(CtrlIn.signals.values(2:end));
data = iddata(Meas.signals.values(2:end, :), u, h);
Meas = Meas.signals.values(2:end, :);
CtrlIn = CtrlIn.signals.values(2:end);

initParam = {'MotorConstant', 1; 'DampCoefDisk', 0.002; 'DiskInertiaInverse', 1/Id_init;...
    'MotorResistanceInverse', 1};

sys_init = idgrey(@dyns, initParam, 'd', Ts=h);

% sys_init.Structure.Parameters(1).Minimum = 0;
sys_init.Structure.Parameters(2).Minimum = 0;
sys_init.Structure.Parameters(3).Minimum = 0;


% Get system
opt = greyestOptions; opt.EnforceStability = 1;
sysEst_dGrey = greyest(data, sys_init, opt);

% Unpack estimated parameters
param_ = getpvec(sysEst_dGrey);
param.k = param_(1);
param.b = param_(2);
param.Id = 1/param_(3);
param.Rm = 1/param_(4);




function [A, B, C, D] = dyns(k, b, Idi, Rmi, Ts)
   
    Ac = -b*Idi;
    Bc = -k*Rmi;
    Cc = [1; 0];
    Dc = [0; Rmi];
    
    sys = ss(Ac,Bc,Cc,Dc);
    dsys = c2d(sys, Ts);
    A = dsys.A;
    B = dsys.B;
    C = dsys.C;
    D = dsys.D;
    
end
