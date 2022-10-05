function [pendparams] = idPend(CtrlIn, Meas, h)

if 0==1 % Do greyest
I_init = 0.0338;

data = iddata(Meas.signals.values(:, 1), CtrlIn.signals.values, h);

initParam = {'dCOM_hinge', 0.05; 'Mass', 1.5; 'HingeFriction', 1e-5;...
    'PendInertiaInverse', 1/I_init};
ID = idgrey(@PendDyns, initParam, 'd', Ts=h);

% Set bounds
ID.Structure.Parameters(1).Minimum = 0;
ID.Structure.Parameters(2).Minimum = 1;
ID.Structure.Parameters(3).Minimum = 0;
ID.Structure.Parameters(3).Minimum = 1;
% 
% ID.Structure.Parameters(1).Maximum = 0.1;
% ID.Structure.Parameters(2).Maximum = 3;
% ID.Structure.Parameters(3).Maximum = 0.01;
% ID.Structure.Parameters(3).Maximum = 200;

% Get system
opt = greyestOptions;
opt.EnforceStability = 1;
opt.InitialState = 'backcast'; % 'estimate'
[sysEst_dGrey, x0] = greyest(data, ID, opt);

% Pack estimated parameters
param_ = getpvec(sysEst_dGrey);
pendparams.l = param_(1);
pendparams.m = param_(2);
pendparams.c = param_(3);
pendparams.Ip = 1/param_(4);

%%
else % Otherwise do semi-analytical analysis
y = Meas.signals.values(:,1);
t = CtrlIn.time;
y_shift = circshift(y,1);

% Find zero crossings
cross0time = t( (y(2:end).*y_shift(2:end)) <= 0 );

% Estimate dampening
[yPks,locs] = findpeaks(y);

% Fit exponential function to peaks
xPks = CtrlIn.time(locs) - CtrlIn.time(locs(1));
[expFit, expGOF] = fit(xPks,yPks,'exp1');
% [linFit, linGOF] = fit(xPks,yPks,'poly1');

% Estimate period and equivalent length for string and bob pendulum
T = mean(diff(xPks));
pendparams.l_eq_est = 9.81*(T/2/pi)^2;

% plots
figure(); figNum = gcf; hold on
plot(t, y, '--');
plot(cross0time, zeros(size(cross0time)), 'xr');
plot(t, expFit(t-cross0time(1)), 'm');
% plot(t, linFit(t-CtrlIn.time(locs(1))), 'k');
plot(xPks+CtrlIn.time(locs(1)), yPks, 'o');

est = @(x) -expFit((x-cross0time(1))).*sin(2*pi/T * (x-cross0time(1)));
plot(t, est(t));

legend(["Measurement" "Zeros" "Exponential peak fit" "Peaks" "Estimate"]);

pendparams.c = expFit.b;

end