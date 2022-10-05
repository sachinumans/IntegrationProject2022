function [A, B, C, D] = PendDyns(l, m, c, Ipi, Ts)
g = 9.81;
Ac = [0 , 1;...
     -m*g*l*Ipi, -c*Ipi];
Bc = [0;0];
Cc = [1, 0];
Dc = 0;

sys = ss(Ac,Bc,Cc,Dc);
dsys = c2d(sys, Ts);
A = dsys.A;
B = dsys.B;
C = dsys.C;
D = dsys.D;

 
end

