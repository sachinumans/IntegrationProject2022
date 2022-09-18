g = 9.81;
thetaStar = 0;

% (alph, Ii, b, c, m, l, Idi, Rmi, Ts)
alph = 1;
Ii = 1/0.0338;
Idi = 1/3.88E-4;
b = 0.002;
c = 0.002;
m = 1.5;
l = 0.04;
Rmi = 1e-3;

A = [0, 1, 0;...
    -(m*g*l)*Ii * cos(thetaStar), -c*Ii, -b*Ii;...
    0, 0, -b*Idi];
B= [0; -alph*Ii; -alph*Idi];
C = [1, 0, 0;...
    0, 0, 1;...
    0, 0, 0];
D = [0; 0; Rmi];

sys = ss(A,B,C,D);
dsys = c2d(sys, 0.05);