function [pendparams, sys] = idPendnl(CtrlIn, Meas, h)

I_init = 0.0338;

% Botch together angular velocity of pendulum
y = Meas.signals.values(:, 1);
dy = gradient(y, h);
% dy = dy.* max(y)/max(dy);

% figure(); hold on
% plot(y, 'k');% plot(dy, 'b');
% plot(dy.* max(y)/max(dy), 'r--')


% Do estimation
data = iddata([y dy], CtrlIn.signals.values, h);

initParam = {0.05; 1; 1e-8; 1/I_init};
ID = idnlgrey('PendDynsNL', [2 1 2], initParam);

% Set bounds: l, m, c, Ipi
ID.Parameters(1).Minimum = 0;
ID.Parameters(2).Minimum = 1;
ID.Parameters(3).Minimum = 0;
ID.Parameters(4).Minimum = 0.01;

ID.Parameters(1).Maximum = 0.1;
ID.Parameters(2).Maximum = 3;
ID.Parameters(3).Maximum = 10;
ID.Parameters(4).Maximum = 75;

% ID.Parameters(3).Fixed = true;

for i = 1:2; ID.InitialStates(i).Fixed = false; end


% Get system
% opt = nlgreyestOptions('Display', 'on');
sys = nlgreyest(data, ID);

for i = 1:2; sys.InitialStates(i).Fixed = false; end

% Pack estimated parameters
param_ = getpvec(sys);
pendparams.l = param_(1);
pendparams.m = param_(2);
pendparams.c = param_(3);
pendparams.Ip = 1/param_(4);

figure(); compare(data, sys, compareOptions('InitialCondition', 'e'));

end