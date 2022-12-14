function [sysObserver] = Synth_Obs(sys, K)

nx = size(sys.A, 1);

L = place((sys.A - sys.B*K).', sys.C.', 0.3+(1:nx)*0.01)';

At = sys.A-L*sys.C;
Bt = [sys.B,L];
Ct = eye(nx);
sysObserver = ss(At,Bt,Ct,0);

end

