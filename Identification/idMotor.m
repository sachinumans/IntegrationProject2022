function [motorparams, x0] = idMotor(CtrlIn, Meas, h)

Id_init = 3.88E-4;

data = iddata(Meas.signals.values(:, 2), CtrlIn.signals.values, h);

initParam = {'MotorConstant', 414; 'DampCoefDisk', 1e-5; 'DiskInertiaInverse', 1/Id_init};
ID = idgrey(@MotorDyns, initParam, 'd', Ts=h);

% Set bounds
ID.Structure.Parameters(1).Minimum = 300;
ID.Structure.Parameters(2).Minimum = 0;
ID.Structure.Parameters(3).Minimum = 1e9;

ID.Structure.Parameters(1).Maximum = 500;
ID.Structure.Parameters(2).Maximum = 0.01;
ID.Structure.Parameters(3).Maximum = 1e15;


% Get system
opt = greyestOptions; opt.EnforceStability = 1;
[sysEst_dGrey, x0] = greyest(data, ID, opt);

% Pack estimated parameters
param_ = getpvec(sysEst_dGrey);
motorparams.k = param_(1);
motorparams.b = param_(2);
motorparams.Id = 1/param_(3);

end