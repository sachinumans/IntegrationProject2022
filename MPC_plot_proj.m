function [] = MPC_plot_proj(pred, meas, Np, h)

N = size(pred, 3);
T = 1:h:((N+Np)*h+1);

figure();
for n = 1:N
    t = T(n);
    for s = 1:3
        subplot(3,1,s)
        hold on
        plot(T(n:(n+Np)), pred(:, s, n), 'Color', [1/t^(1/4) 1-1/t^(1/4) 1/t^(1/4) 0.2]);
%         hold off
    end 
end

for s = 1:3
    subplot(3,1,s)
    plot(T(1:N), meas(:, s), 'k')
end 

end

