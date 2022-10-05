function [A, B, C, D] = CombiDyns(k, b, Idi, l_eq, c, m, l, Ts)
    g = 9.81;
    thetaStar = 0;
    
    I = m*l_eq^2;
    
    Ac = [0, 1, 0;...
        -(m*g*l)/I * cos(thetaStar), -c/I, -b/I;...
        0, 0, -b*Idi];
    Bc = [0; -k/I; -k*Idi];
    Cc = [1, 0, 0;...
        0, 0, 1];
    Dc = [0; 0];
    
    sys = ss(Ac,Bc,Cc,Dc);
    dsys = c2d(sys, Ts);
    A = dsys.A;
    B = dsys.B;
    C = dsys.C;
    D = dsys.D;
    
end