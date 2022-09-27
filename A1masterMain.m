clear all; close all; clc;

hwinit();

%% Identification
% Load data
load Identification\Data\Exp5_fullSweepFinalCropped.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
t = CtrlIn.time(4/h:end);

s = 75;
n = 5;

%%% PI-MOESP
sysPI1 = pi_moesp(u,y(:,1),s,n,h);
sysPI2 = pi_moesp(u,y(:,2),s,n,h);

sysPI = ss(blkdiag(sysPI1.A, sysPI2.A), [sysPI1.B;sysPI2.B],...
    blkdiag(sysPI1.C, sysPI2.C), [sysPI1.D;sysPI2.D], h);

[VAFpi, RMSEpi] = Validation(sysPI, CtrlIn, y, t);

%%% PO-MOESP
sys1PO = po_moesp(t,u,y(:,1),s,"po-moesp", [0 10], n);
sys2PO = po_moesp(t,u,y(:,2),s,"po-moesp", [0 10], n);

sysPO = ss(blkdiag(sys1PO.A, sys2PO.A), [sys1PO.B;sys2PO.B],...
    blkdiag(sys1PO.C, sys2PO.C), [sys1PO.D;sys2PO.D], h);

[VAFpo, RMSEpo] = Validation(sysPO, CtrlIn, y, t);

%%% Comparison --> Go with PO
RelDiff = abs(RMSEpi./RMSEpo*100 - 100);

[val,ind] = max(RelDiff);

if RMSEpi(ind)<=RMSEpo(ind)
    sys = sysPI;
    disp("Chosen method is PI-MOESP");
else 
    sys = sysPO;
    disp("Chosen method is PO-MOESP");
end

%% Controller design

disp("The system is controllable")
rank(ctrb(sys)) == 2*n

disp("The system is observable")
rank(obsv(sys)) == 2*n

K = Synth_LQR(sys);
sysObserver = Synth_Obs(sys);


