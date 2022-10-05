function [pendparams, sys] = idPendnl(CtrlIn, Meas, h)

I_init = 0.0338;

data = iddata(Meas.signals.values(:, 1), CtrlIn.signals.values, h);

initParam = {0.05; 1.5; 1e-5; 1/I_init};
ID = idnlgrey('PendDynsNL', [1 1 2], initParam);

% Set bounds
% ID.Structure.Parameters(1).Minimum = 0;
% ID.Structure.Parameters(2).Minimum = 1;
% ID.Structure.Parameters(3).Minimum = 0;
% ID.Structure.Parameters(3).Minimum = 1;
% 
% ID.Structure.Parameters(1).Maximum = 0.1;
% ID.Structure.Parameters(2).Maximum = 3;
% ID.Structure.Parameters(3).Maximum = 0.01;
% ID.Structure.Parameters(3).Maximum = 200;

% Get system
% opt = greyestOptions;
% opt.EnforceStability = 1;
% opt.InitialState = 'backcast'; % 'estimate'
sys = nlgreyest(data, ID);

% Pack estimated parameters
param_ = getpvec(sys);
pendparams.l = param_(1);
pendparams.m = param_(2);
pendparams.c = param_(3);
pendparams.Ip = 1/param_(4);

end