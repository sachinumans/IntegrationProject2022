function [K] = Synth_LQR(sys, meth)
switch meth
    case "Subspace"
nx = size(sys.A, 1);
Q = 1*blkdiag(eye(nx/2), zeros(nx/2)); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

    case "Greybox down"
nx = size(sys.A, 1);
Q = diag([1e2, 0, 0]); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

    case "Greybox up"
nx = size(sys.A, 1);
Q = diag([1e2, 0, 0]); % State cost
R = 1; % Input cost
N = zeros(nx,1); % Cross cost

sys.A(2,1) = -sys.A(2,1);

    otherwise; error("Unknown method passed"); 
end

[K,~,~] = dlqr(sys.A,sys.B,Q,R,N);

end