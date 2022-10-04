function [K] = Synth_LQR(sys)

% %% Bring back to known state space
% C = [eye(2), zeros(2)];
% T = sys.C\C;
nx = size(sys.A, 1);

Q = 100000*blkdiag(eye(nx/2), zeros(nx/2)); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

[K,~,~] = dlqr(sys.A,sys.B,Q,R,N);

end