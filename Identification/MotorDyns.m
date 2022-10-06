function [A, B, C, D] = MotorDyns(k, b, Idi, Ts)
    Ac = -b*Idi;
    Bc = -k*Idi;
    Cc = 1;
    Dc = 0;
    
    sys = ss(Ac,Bc,Cc,Dc);
    dsys = c2d(sys, Ts);
    A = dsys.A;
    B = dsys.B;
    C = dsys.C;
    D = dsys.D;
    
end