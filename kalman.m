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


% % Extended
c = 343; %Speed of sound in meters per second

F = eye(3);
x_hat2 = [0.1 0.1; 0.6 0.6;0 0];
Q = 0.2*[10^-6 0 0;0 10^-6 0;0 0 10^-6];
R = diag(stds);
P_ext = eye(3); 
diagP__extended_tmp = [0 0 0;0 0 0;0 0 0];
for k = 2 : length(y_cal)
%   Time update    
    x_car = x_hat2(1,k);
    y_car = x_hat2(2,k);
    tau = x_hat2(3,k);
    H = eval(Jacobian_f);    
    P_1 = F*P_ext*F' + Q;
%   Measurement update   
    K = P_1 * H'/(H*P_1*H' + R);   
    x_hat2(:,k+1) = x_hat2(:,k) + K*(y(k,:)-f(x_hat2(:,k),mic_locations))';
    P_ext = P_1 - K*H*P_1;   
    diagP__extended_tmp(:,:,k) = diag(diag(P_ext));
end

%Calculate:
th_ekf  =  x_hat2(:,1:end-1);
% 3XN-vector with the estimated trajectory, first row is
%              X-coordinate, second row is Y-coordinate.
P_ekf     = diagP__extended_tmp;

function ftheta = f(theta,mic_locations)
    c = 343; % speed of sound in [m/s]
    for k=1:8
    ftheta(:,k) = (1/c)*(sqrt((theta(1)-mic_locations(k,1))^2+(theta(2)-mic_locations(k,2))^2))+theta(3);
    end
end

function [th_hat, diagP] = nls(y_cal,stds,theta,maxiter,mic_locations,Jacobian_f)
    th_hat=theta;
    x_car = th_hat(1);
    y_car = th_hat(2);
    tau  = th_hat(3);
    th_hat_all = [];
    diagP_all=[];

    for i=1:length(y_cal)
        th_hat_prev=[-Inf;-Inf;0];
        iter=0;
        while (iter<maxiter &&(th_hat(1)~=th_hat_prev(1)||th_hat(2)~=th_hat_prev(2)))
        th_hat_prev=th_hat;
        Jacobian_F = eval(Jacobian_f);
        dtheta = (Jacobian_F'*diag(1./stds)*Jacobian_F)\(Jacobian_F'*diag(1./stds)*(y_cal(i,:) - f(th_hat,mic_locations))');
        th_hat = th_hat+dtheta';
        x_car = th_hat(1);
        y_car = th_hat(2);
        tau  = th_hat(3);
        iter=iter+1;
        end
        th_hat_all = [th_hat_all;th_hat];
        diagP_all(:,:,i)=[inv(Jacobian_F'*diag(1./stds)*Jacobian_F)];
    end
    th_hat = th_hat_all;
    diagP=diagP_all;
end

function dF = Jacobian(theta,f_theta)    
        dF =[];
        for k =1:8
            for r=1:3
              dF_tmp(r) = [diff(f_theta(:,k),theta(r))];
            end
            dF = [dF;dF_tmp];
        end
end