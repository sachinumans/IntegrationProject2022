function [Kii] = Synth_LQII(sys, wy, wyI, wu)
meanMagTheta = 0.05;
meanMagThetaDot = 0.5;
meanMagPhi = 50;
meanMagInput = 1;

stateNorm = diag(1./sqrt([meanMagTheta meanMagThetaDot meanMagPhi]));
stateNormII = blkdiag(stateNorm, stateNorm(1,1), stateNorm(3,3));
inputNorm = 1/sqrt(meanMagInput);


nx = size(sys.A, 1);
Qii = stateNormII * diag([wy wyI]) * stateNormII; % State cost
R = inputNorm * wu; % Input cost
Ni = zeros(nx+2,1); % Cross cost

sysII = ss([sys.A, zeros(nx,2); [1*sys.Ts 0 0 1 0; 0 0 1*sys.Ts 0 1]], [sys.B; 0; 0], eye(nx+2), zeros(nx+2, 1), sys.Ts);
[Kii,~,~] = dlqr(sysII.A,sysII.B,Qii,R,Ni);

end