function [A,B,C,D,x0,sv,Y,Uf] = subspaceID(u,y,s,n,figure_num)

[rows_y,columns_y]=size(y);
[ysize,l]=size(y); % Dimensions of outputs
           
U=hankel(u(1:s),u(s:ysize-s));
Uf=hankel(u(s+1:2*s),u(2*s:end));
Yf=hankel(y(s*l+1:2*s*l),y(2*s*l:end));
[Q,R]=qr([Uf;U;Yf]',0);
L=triu(R)';
L32 = L(2*s+1:3*s,s+1:2*s);
[U_svd,S_svd]=svd(L32);
sv = diag(S_svd);
figure(figure_num)
stairs(sv,'^');
xlim([0 40]);
title("SVD PI-moesp");      

sv = diag(S_svd);
A = U_svd(1:s-1,1:n)\U_svd(2:s,1:n);
C = U_svd(1,1:n);

for i=1:rows_y
    Sum = zeros(1,n);
    for j = 0:i-2
        Sum = Sum + kron(u(j+1,:)',C*(A^(i-2-j)));
    end
    Phi(i,:) = [C*(A^(i-1)) Sum kron(u(i,:)',eye(columns_y))];     
end

tmp = Phi\y;
x0 = tmp(1:n)';
B = tmp(n+1:2*n);
D = tmp(2*n+1:end);     
end

