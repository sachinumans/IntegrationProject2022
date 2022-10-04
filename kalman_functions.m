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