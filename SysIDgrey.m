data = iddata(Meas(2:end, 1:2), CtrlIn(2:end), h);
Id_init = 3.88E-4;
I_init = 0.0338;

initParam = {'MotorConstant', 4; 'PendInertia', I_init; 'DampCoef', 0.02; 'Mass', 1.5; 'COMdiv', 0.05; 'DiskInertia', Id_init};

sys_init = idgrey(@dyns, initParam, 'cd',Ts=h);

sysEst = greyest(data, sys_init);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [A, B, C, D] = dyns(k, I, b, m, l, Id, Ts)
    g = 9.81;
    thetaStar = 0;
    
    A = [0, 1, 0;...
        (m*g*l)/I * cos(thetaStar), 0, -b/I;...
        0, 0, -b/Id];
    B= [0; k/I; k/Id];
    C = [1, 0, 0;...
        0, 0, 1];...
%         0, 0, 0];
    D = [0; 0];
end

