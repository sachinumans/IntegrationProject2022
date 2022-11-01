function [K, Ki] = Synth_LQR(sys, meth, wy, wyI, wu)
meanMagTheta = 0.05;
meanMagThetaDot = 0.5;
meanMagPhi = 50;
meanMagInput = 1;

stateNorm = diag(1./sqrt([meanMagTheta meanMagThetaDot meanMagPhi]));
stateNormI = blkdiag(stateNorm, stateNorm(1,1));
inputNorm = 1/sqrt(meanMagInput);

switch meth
    case "Subspace"
nx = size(sys.A, 1);
Q = 1*blkdiag(eye(nx/2), zeros(nx/2)); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

    case "Greybox"
nx = size(sys.A, 1);
Q = stateNorm * diag(wy) * stateNorm; % State cost
Qi = stateNormI * diag([wy wyI]) * stateNormI; % State cost
R = inputNorm * wu; % Input cost
N = zeros(nx,1); % Cross cost
Ni = zeros(nx+1,1); % Cross cost

    otherwise; error("Unknown method passed"); 
end

[K,~,~] = dlqr(sys.A,sys.B,Q,R,N);

sysI = ss([sys.A, zeros(nx,1); [1*sys.Ts 0 0 1]], [sys.B; 0], eye(nx+1), zeros(nx+1, 1), sys.Ts);
[Ki,~,~] = dlqr(sysI.A,sysI.B,Qi,R,Ni);

end