clear; clc; close all;
load Identified_system_PO-MOESP

% %% Bring back to known state space
% C = [eye(2), zeros(2)];
% T = sys.C\C;

Q = diag([1, 1, 1, 1]); % State cost
R = 1e-2; % Input cost
N = [0;0;0;0]; % Cross cost

[K,S,e] = dlqr(sys.A,sys.B,Q,R,N);

save Controller_LQR K