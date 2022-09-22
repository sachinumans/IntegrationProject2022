clear all;
close all;
load Identified_system2.mat
load Identified_system2_data.mat
h = 0.05;

t = CtrlIn.time;

u = squeeze(CtrlIn.signals.values);
Y = squeeze(Meas.signals.values);

y_est = lsim(sysEst_d, u, t);


titles = ["Pendulum angle","Angular velocity", "Current"];
figure(1); 
for idx = 1:3
    subplot(3, 1, idx)
    plot(t, y_est(:,idx));hold on
    plot(t, Y(:,idx));
    title(titles(idx))
end
legend("Estimate","Measurement")
% 
% 
% figure(2);
% plot(t, squeeze(Meas.signals.values))