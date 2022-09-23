clear all;
close all;
load Identified_system9_extra_data.mat
load ValExtraData_exp2.mat
h = 0.05;

t = CtrlIn.time(5/h:end);

u = squeeze(CtrlIn.signals.values);
Y = squeeze(Meas.signals.values);

y_est = lsim(sysEst_d, u, t);


titles = ["Pendulum angle","Angular velocity"];
figure(1); 
for idx = 1:2
    subplot(3, 1, idx)
    plot(t, y_est(:,idx));hold on
    plot(t, Y(:,idx));
    title(titles(idx))
end
legend("Estimate","Measurement")
subplot(3, 1, 3)
    plot(t, u);
    title("Control input")
% 
% 
% figure(2);
% plot(t, squeeze(Meas.signals.values))