clear; clc; close all;

load Exp5_fullSweepFinalCropped.mat

[sys, X, VAF, RMSE] = subspaceID(Meas.time(4/h:end),CtrlIn.signals.values,...
    Meas.signals.values,75,"po-moesp",[0 20]);
% [sys, X, VAF, RMSE] = subspaceID(Meas.time(4/h:end),CtrlIn.signals.values,...
%     Meas.signals.values,50,"po-moesp",[0 20], 4);

VAF, RMSE

save Identified_system_PO-MOESP sys


function [sys, X, VAF, RMSE] = subspaceID(t,u,y,s,method,lim,n)
%% SUMMARY:Perform a subspace identification of a system
% Function INPUT 
% t         time array
% u         system input (matrix of size N x m)
% y         system output (matrix of size N x l)
% s         block size (scalar)
% method    method (string e.g. 'moesp')
% n         optional, model order if known
%
% Function OUTPUT
% sys         The estimation of the system, where the particular matrices are encoded within
% X           Estimated states over the training set
% VAF         Variance accounted for wrt the measurements
% RMSE        Root mean square error wrt the measurements
arguments
    t (1,:) {mustBeNumeric}
    u (:,:) {mustBeNumeric}
    y (:,:) {mustBeNumeric}
    s int32 {mustBePositive, mustBeInteger} = 120
    method string = "po-moesp" % When not specified take most extensive algorithm
    lim (1,2) {mustBeNumeric} = [0 10]
    n int32 {mustBeInteger} = -1 % Value of -1 acts as query catch
end

    tic                                     % Start runtime counter
    N=size(y, 1);                           % Number of measurements available
    dT = (circshift(t, -1) - t);            % Determine the
    dt = mean(dT(1:end-1));                 % Average timestep
    l = min(size(y));                       % Number of outputs
    m = min(size(u));                       % Number of inputs
    yOr = y; uOr = u;                       % Save a copy of original u and y
    y = y'; u = u';                         % Vectorise u and y
    y = y(:); u = u(:);

    switch method
        case 'moesp'
            U = hankel(u(1:s*m),u(s*m:end));        % U_0,s,N-s+1 Hankel input matrix
            Y = hankel(y(1:s*l),y(s*l:end));        % Y_0,s,N-s+1 Hankel output matrix

            H = [U' Y'];                        % Create transpose of stacked U and Y
            [~, R] = qr(H, 0);                  % Get R of QR factorisation of stacked U and Y
            Rt = triu(R);                       % Take upper triangular part of R
            L = Rt';                            % L such that H' = L*Q'
            Lpart = L(s*m+1:end, s*m+1:end);        % Retrieve L22
     
        case 'po-moesp'
            U = hankel(u(1:2*s*m),u(2*s*m:end));    %U_0,2s,N-s+1 Hankel input matrix
            Y = hankel(y(1:2*s*l),y(2*s*l:end));    %Y_0,2s,N-s+1 Hankel output matrix
            Up = U(1:s*m, :);                     % Partition U and Y matrices into past and future 
            Uf = U(s*m+1:end, :);
            Yp = Y(1:s*l, :);
            Yf = Y(s*l+1:end, :);
            
            Up_ = [Up,Up]; Up_ = Up_(:, 1:size(Yp, 2));
            
            Z = [Up_; Yp];                       % Create the instrumental variable 

            H = [[Uf'; Uf(:,1:end-1)'] Z' Yf'];                   % Create transpose of stacked U_f, Z and Y_f
            [~, R] = qr(H, 0);                  % Get R of QR factorisation of stacked U_f, Z and Y_f
            Rt = triu(R);                       % Take upper triangular part of R
            L = Rt';                            % L such that H' = L*Q'
            Lpart = L((2*m+l)*s+1:end, m*s+1:(2*m+l)*s);      % Retrieve L32
    end
    [G ,S ,~] = svd(Lpart,'econ');              % Make singular value decomposition of L partition

    figure(); semilogy(diag(S), 'o')            % Plot singular values to determine the model order
    xlim(lim)
    if n == -1
        disp("What order is the system?")
        [n, ~] = ginput(1);     % Either ask for the model order, or implement directly
        close all
        n = round(n);
        disp(strjoin(["You chose a model order of" num2str(n)]))
    end
    if n<1
        error("The system order is less than 1, what are you expecting to happen?")
    end

    A = G(1:(s-1)*l, 1:n)\G(l+1:s*l, 1:n);            % Solve linear least squares to retrieve the A matrix
    C = G(1:l, 1:n);                              % Retrieve the C matrix

    if l == 1
        phi = zeros(N, n*m+m+n);                      % Initialise phi such that all phi_k are stacked

        parfor k=0:N-1                              % Fill phi (using as many cores as possible)
            SUM = zeros(l,m*n);
            CApow = C;
            for j = k-1:-1:0
                SUM = SUM + kron(uOr(j+1, :), CApow);
                CApow = CApow*A;
            end
            phi(k+1, :) = [C*A^k,  SUM,  kron(uOr(k+1, :)', eye(l))'];
        end
else
        phiStacked = zeros(N, l, n*m+m*l+n);                      % Initialise phi such that all phi_k are stacked

        parfor k=0:N-1                              % Fill phi (using as many cores as possible)
            SUM = zeros(l,m*n);
            CApow = C;
            for j = k-1:-1:0
                SUM = SUM + kron(uOr(j+1, :), CApow);
                CApow = CApow*A;
            end
            phiStacked(k+1, :, :) = [C*A^k,  SUM,  kron(uOr(k+1, :)', eye(l))'];
        end
        
        phi = reshape(permute(phiStacked, [3 2 1]), n*m+m*l+n, [])'; % Reshape into correct shape
    end
    xBD = phi\y;                                % Solve a linear least squares to retrieve the vectorised x0, B and D matrix

    x0 = xBD(1:n);                              % Initial state estimate
    B = reshape(xBD(n+1:(m+1)*n), [n, m]);                           % B matrix estimate
    D = reshape(xBD((m+1)*n+1:end), [l, m]);                               % D matrix estimate
    
    sys = ss(A,B,C,D,dt);                       % Create state space system
    [yhat, T, X] = lsim(sys, uOr, t, x0);         % Simulate estimate

    err = yhat - yOr;                             % error wrt measurements
    VAF = max([0, (1-(err(:)'*err(:))/(y(:)'*y(:)))*100]);  % Variance Accounted For wrt measurements
    RMSE = rms(err);           % Root Mean Square Error wrt measurements
    
    for i=1:l
        figure();hold on;                           % Plot the measurements and estimate
        title(strjoin([method "output-" num2str(i)]))
        plot(t, yOr(:, i), 'b');
        plot(T, yhat(:, i), 'r'); 
        legend("Measurement", "Estimate")
    end
    hold off;
    disp(strjoin(["Subspace identification took", num2str(toc, 3), "seconds"]));
    beep
end

function [VAF, RMSE] = performance(yhat, y)
    err = yhat - y;
    VAF = max([0, (1-(err'*err)/(y'*y))*100]);
    RMSE = sqrt(mean((yhat - y).^2));
end