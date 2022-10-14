% Calculate:

pk_tilde = th_hat1(:,1:2);
A = eye(2);
B = 0;
C = eye(2);
D = 0;
Q = [40*10^-6 0;0 30*10^-6];
x_hat= [0.1 0.6;0.1 0.6];
P = zeros(2,2);
K_tmp =[];

diagP_tmp = [0 0;0 0];
    for k = 2:length(y_cal)
       R = diag(diag(diagP(1:2,1:2,k)));
    %     Time update
        x_hat(k+1,:) = A*x_hat(k,:)';
        P_1 = A*P*A'+Q;        
    %     Measurement update
        K = P_1*C'/(C*P_1*C'+R);
        K_tmp = [K_tmp;K];
        x_hat(k,:)= x_hat(k,:) + (K*(pk_tilde(k,:)'-C*x_hat(k,:)'))';
        P = P_1 - P_1*C'/(C*P_1*C'+R)*C*P_1;
        diagP_tmp(:,:,k) = diag(diag(P));
    end
    
p_kf = x_hat(1:end-1,:)';
% 2XN-vector with the estimated trajectory, first row is
%              X-coordinate, second row is Y-coordinate.
P_kf = diagP_tmp;  
% 2X2XN-vector with the covariance matrix of p_kf
