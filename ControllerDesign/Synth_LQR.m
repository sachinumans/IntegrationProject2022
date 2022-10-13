function [K] = Synth_LQR(sys, meth)
meanMagTheta = 0.1;
meanMagThetaDot = pi;
meanMagPhi = 150;
meanMagInput = 3;

stateNorm = diag(1./[meanMagTheta meanMagThetaDot meanMagPhi]);
inputNorm = 1/meanMagInput;

switch meth
    case "Subspace"
nx = size(sys.A, 1);
Q = 1*blkdiag(eye(nx/2), zeros(nx/2)); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

    case "Greybox"
nx = size(sys.A, 1);
% Q = stateNorm * diag([10, 0, 1]) * stateNorm; % State cost %% quite nice
% down, not very good up: no overshoot
Q = stateNorm * diag([100, 0, 100]) * stateNorm; % State cost
R = inputNorm * 50; % Input cost
N = zeros(nx,1); % Cross cost

    otherwise; error("Unknown method passed"); 
end

[K,~,~] = dlqr(sys.A,sys.B,Q,R,N);

end