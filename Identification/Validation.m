function [VAF, RMSE] = Validation(sys,U, meas, t)
h = 0.05;

u = squeeze(U.signals.values);
Y = squeeze(meas);

y_est = lsim(sys, u, t);


titles = ["Pendulum angle","Angular velocity"];
figure(1); 
for idx = 1:size(sys,1)
    subplot(3, 1, idx)
    plot(t, y_est(:,idx));hold on
    plot(t, Y(:,idx));
    title(titles(idx))
end
legend("Estimate","Measurement")
subplot(3, 1, 3)
    plot(t, u);
    title("Control input")

err = y_est - Y;

normTwoSqErr = 0;
for idx = 1:size(err,2);  normTwoSqErr = normTwoSqErr+ err(:,idx).^2; end
normTwoSq = 0;
for idx = 1:size(err,2);  normTwoSq = normTwoSq+ Y(:,idx).^2; end

VAF = max(0, (1-sum(normTwoSqErr)/sum(normTwoSq))*100);

% VAF_ = (1-(err'*err)/(Y'*Y))*100;
% VAF = max([zeros(size(VAF_)), VAF_]);
RMSE = sqrt(mean((y_est - Y).^2));

end