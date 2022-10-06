function [sys] = getSys_from_Param(motorparams, pendparams)
b = motorparams.b;
Ip = pendparams.Ip;
Id = motorparams.Id;
g = 9.81;

nx = 3; ny = 2; nu = 1;
A = zeros(nx);
B = zeros(nx, nu);
C = [1 0 0; 0 0 1];
D = zeros(ny, nu);

A(1,2) = 1;
A(2,1) = -pendparams.m * g * pendparams.l / Ip;
A(2,2) = -pendparams.c / Ip;
A(2,3) = -b/Ip;
A(3,3) = -b/Id;

B(2) = motorparams.k/Ip;
B(3) = -motorparams.k/Id;

sys = ss(A,B,C,D);


end

