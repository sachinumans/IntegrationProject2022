clear all; close all; clc;
addpath(genpath('Identification'))
addpath(genpath('ControllerDesign'))

Method = "Greybox nonlin"; % Load / Subspace / Greybox / Greybox nonlin


hwinit();

%% Identification
switch Method
    case "Subspace"
% Load data
load Identification\Data\CLunstable_data2.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time; 
s = 75;
n = 3;

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

close all;
[VAFpo, RMSEpo] = Validation(sysPO, CtrlIn, y, t);
set(gcf, "Name", "Training")

%%% Comparison --> Go with PO/PI
RelDiff = abs(RMSEpi./RMSEpo*100 - 100);

[val,ind] = max(RelDiff);

if RMSEpi(ind)<=RMSEpo(ind)
    sys = sysPI;
    disp("Chosen method is PI-MOESP");
else 
    sys = sysPO;
    disp("Chosen method is PO-MOESP");
end

save IdentifiedSystem sys



%%% Validation
% Load data
load Identification\Data\CLunstable_ValData.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time;

[VAFval, RMSEval] = Validation(sys, CtrlIn, y, t);
set(gcf, "Name", "Validation 1")

load Identification\Data\CLunstable_ValData2.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time;

[VAFval2, RMSEval2] = Validation(sys, CtrlIn, y, t);
set(gcf, "Name", "Validation 2")


load Identification\Data\CLunstable_ValData3.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time;

[VAFval3, RMSEval3] = Validation(sys, CtrlIn, y, t);
set(gcf, "Name", "Validation 3")

% Possibly merge double estimated poles

%%
case "Greybox"
%%% Identify motor
% load Identification\Data\grey_MotorID_ramp_cropped.mat
load Identification\Data\grey_chirp_0025_075Hz_cropped.mat

[motorparams, x0] = idMotor(CtrlIn, Meas, h);
[A, B, C, D] = MotorDyns(motorparams.k, motorparams.b, 1/motorparams.Id, h);
motorSys = ss(A, B, C, D, h); clear A B C D;

[motorVAF, motorRMSE] = Validation(motorSys, CtrlIn, Meas.signals.values(:,2), CtrlIn.time, x0);

%%% Identify pendulum
load Identification\Data\greyest_ID_pendulum_small_angle.mat

pendparams = idPend(CtrlIn, Meas, h);
% [A, B, C, D] = PendDyns(pendparams.l, pendparams.m, pendparams.c, 1/pendparams.Ip, h);
% pendSys = ss(A, B, C, D, h); clear A B C D;
% [pendVAF, pendRMSE] = Validation(pendSys, CtrlIn, Meas.signals.values(:,1), CtrlIn.time, x0);

%%% Identify pendulum + motor
load Identification\Data\grey_chirp_0025_075Hz_cropped.mat

[params, combiSys, x0] = idCombi(CtrlIn, Meas, h, motorparams, pendparams);
[combiVAF, combiRMSE] = Validation(combiSys, CtrlIn, Meas.signals.values, CtrlIn.time, x0);

    case "Greybox nonlin"
%%% Identify motor
load Identification\Data\grey_chirp_0025_075Hz_cropped.mat

[motorparams, x0] = idMotor(CtrlIn, Meas, h);
[A, B, C, D] = MotorDyns(motorparams.k, motorparams.b, 1/motorparams.Id, h);
motorSys = ss(A, B, C, D, h); clear A B C D;

[motorVAF, motorRMSE] = Validation(motorSys, CtrlIn, Meas.signals.values(:,2), CtrlIn.time, x0);

load Identification\Data\grey_MotorID_ramp_cropped.mat
[~, ~] = Validation(motorSys, CtrlIn, Meas.signals.values(:,2), CtrlIn.time);

%%% Identify pendulum
load Identification\Data\greyest_ID_pendulum_small_angle.mat

[pendparams, pendSys] = idPendnl(CtrlIn, Meas, h);

%%% Syntesise complete system
sys = getSys_from_Param(motorparams, pendparams);

load Identification\Data\grey_chirp_LowFr_smallAngle_cropped2.mat
data = iddata(Meas.signals.values, CtrlIn.signals.values, h);
figure(); compare(data, sys, compareOptions('InitialCondition', 'e'));



otherwise
    load Identification\IdentifiedSystem
end

return
%% Controller design

disp("The system is controllable")
rank(ctrb(sys)) == 2*n
Rc = rank(ctrb(sys));

disp("The system is observable")
rank(obsv(sys)) == 2*n

nx = size(sys.A, 1);
K = Synth_LQR(sys);
% [Abar,Bbar,Cbar,T,k] = ctrbf(sys.A, sys.B, sys.C);
% Ac = Abar(nx-Rc+1:end, nx-Rc+1:end);
% Bc = Bbar(nx-Rc+1:end);
% Cc = Cbar(:, nx-Rc+1:end);

% K = place(Ac, Bc, 0.7+(1:Rc)*0.001);
% K = [zeros(1, nx-Rc) K];
disp("Controller poles are at: "); disp(abs(eig(sys.A-sys.B*K)));
% sysObserver = Synth_Obs(sys, K);
% disp("Closed loop observer poles are at: "); disp(abs(pole(sysObserver)));


