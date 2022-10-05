function [dx, y] = PendDynsNL(t, x, u, l, m, c, Ipi, varargin)
g = 9.81;

dx(1) = x(2);
dx(2) = m*g*l*Ipi*sin(x(1)) - c*x(2);

y = x(1);
 
end

