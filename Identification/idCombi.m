function [param, sys, x0] = idCombi(CtrlIn, Meas, h, motorparams, pendparams)

data = iddata(Meas.signals.values, CtrlIn.signals.values, h);

initParam = {'MotorConstant', motorparams.k; 'DampCoefDisk', motorparams.b;...
    'DiskInertiaInverse', 1/motorparams.Id; 'InertiaEqLength', pendparams.l_eq_est;...
    'DampCoefPend', -pendparams.c; 'Mass', 2.5; 'dCOM_hinge', 0.05};

ID = idgrey(@CombiDyns, initParam, 'd', Ts=h);

% Set bounds
for idx=1:5; ID.Structure.Parameters(idx).Free = false; end

ID.Structure.Parameters(6).Minimum = 1;
ID.Structure.Parameters(7).Minimum = 0.01;

ID.Structure.Parameters(6).Maximum = 5;
ID.Structure.Parameters(7).Maximum = 0.1;

% Get system
opt = greyestOptions;
opt.EnforceStability = 1;
opt.InitialState = 'estimate';
% opt.InitialState = 'backcast';
[sys, x0] = greyest(data, ID, opt);

% Unpack estimated parameters
param_ = getpvec(sys);
param.k = param_(1);
param.b = param_(2);
param.Id = 1/param_(3);
param.Inert = param_(6)*param_(4)^2;
param.c = param_(5);
param.m = param_(6);
param.l = param_(7);

end