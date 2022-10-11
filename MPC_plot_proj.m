function [] = MPC_plot_proj(pred, meas, Np, h)

N = size(pred, 3);
T = 0:h:N*h;

figure();hold on
for n = 1:N
    t = T(n);
    for s = 1:3
        subplot(3,1,s)
        plot(T(n:n+Np), pred(:, s, n), 'Color', [1/t^(1/4) 1-1/t^(1/4) 1/t^(1/4) 0.2])
    end 
end

for s = 1:3
    subplot(3,1,s)
    plot(T, meas(:, s), 'k')
end 

end

