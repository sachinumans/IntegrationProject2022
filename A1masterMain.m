clear all; close all; clc;
addpath(genpath('Identification'))
addpath(genpath('ControllerDesign'))
addpath(genpath('Validation'))

Method = "Load"; % Load / Subspace / Greybox / Greybox nonlin


hwinit();

%% Identification
switch Method

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    case "Subspace"
% Load data
load Identification\Data\CLunstable_data2.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time; 
s = 75;
nx = 3;

%%% PI-MOESP
sysPI1 = pi_moesp(u,y(:,1),s,nx,h);
sysPI2 = pi_moesp(u,y(:,2),s,nx,h);

sysPI = ss(blkdiag(sysPI1.A, sysPI2.A), [sysPI1.B;sysPI2.B],...
    blkdiag(sysPI1.C, sysPI2.C), [sysPI1.D;sysPI2.D], h);

[VAFpi, RMSEpi] = Validation(sysPI, CtrlIn, y, t);

%%% PO-MOESP
sys1PO = po_moesp(t,u,y(:,1),s,"po-moesp", [0 10], nx);
sys2PO = po_moesp(t,u,y(:,2),s,"po-moesp", [0 10], nx);

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

data = iddata(y, u, h);
figure(); compare(data, sys, compareOptions('InitialCondition', 'e'));

% save Identification\IdentifiedSystem sys
nx = size(sys.A, 1);


%%% Validation
% Load data
load Identification\Data\CLunstable_ValData.mat
u = CtrlIn.signals.values;
y = Meas.signals.values;
y(:,1) = y(:,1) - pi;
t = CtrlIn.time;

data = iddata(y, u, h);
figure(); compare(data, sys, compareOptions('InitialCondition', 'e'));

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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

nx = 3;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
sysC = getSys_from_Param(motorparams, pendparams);

load Identification\Data\grey_chirp_LowFr_smallAngle_cropped2.mat
data = iddata(Meas.signals.values, CtrlIn.signals.values, h);
figure(); compare(data, sysC, compareOptions('InitialCondition', 'e'));
load Identification\Data\valPRB.mat
data = iddata(MeasFull(:, 1:3), CtrlIn.signals.values, h);
figure(); compare(data, sysC, compareOptions('InitialCondition', 'e'));

sys = c2d(sysC, h);

params = cell2struct([struct2cell(motorparams);struct2cell(pendparams)],[fieldnames(motorparams);fieldnames(pendparams)],1);


save Identification\IdentifiedSystem sys params
nx = 3;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
otherwise
    load Identification\IdentifiedSystem
    if 0==1
        load Identification\Data\grey_chirp_LowFr_smallAngle_cropped2.mat
        data = iddata(Meas.signals.values, CtrlIn.signals.values, h);
        figure(); compare(data, sys, compareOptions('InitialCondition', 'e'));
    end
    nx = size(sys.A, 1);
end

%% Controller design

% Assume full state knowledge
sysReal = sys;
sys = ss(sys.A, sys.B, eye(nx), zeros(nx,1), h);

sysUnst = sys;
sysUnst.A(2,1) = -sys.A(2,1);

sysI = ss([sys.A, zeros(nx,1); [1*sys.Ts 0 0 1]], [sys.B; 0], eye(nx+1), zeros(nx+1, 1), sys.Ts);
sysUnstI = sysI;
sysUnstI.A(2,1) = -sysI.A(2,1);

sysC = d2c(sys);
sysC_Unst = d2c(sysUnst);

disp("The system is controllable"); rank(ctrb(sys)) == nx;
disp("The system is observable"); rank(obsv(sys)) == nx;

nx = size(sys.A, 1); nu = 1; ny = 2;

% LQR controllers
[K, Ki] = Synth_LQR(sys, "Greybox", [100, 10, 0], 1, 50);

[K_Unst, ~] = Synth_LQR(sysUnst, "Greybox", [50, 0, 0], 5, 1);
[~, Ki_Unst] = Synth_LQR(sysUnst, "Greybox", [75, 25, 5], 5, 4e2);
% Kii_Unst = Synth_LQII(sysUnst, [75, 5, 5], [25 5], 400);

% disp("LQR down controller poles are at: "); disp(abs(eig(sys.A-sys.B*K)));
% disp("LQR up controller poles are at: "); disp(abs(eig(sys.A-sys.B*K_Unst)));

% MPC controller
load ControllerDesign\MPC mpcController
mpcController.PredictionHorizon = 20;
mpcController.ControlHorizon = 15;

% mpcController.ManipulatedVariables.Min = -6;
% mpcController.ManipulatedVariables.Max = 6;
mpcController.OutputVariables(1).Min = -0.025;
mpcController.OutputVariables(1).Max = 0.025;
mpcController.OutputVariables(3).Min = -300;
mpcController.OutputVariables(3).Max = 300;

mpcController.Weights.ManipulatedVariablesRate = 0.1;
mpcController.Weights.OutputVariables = [250*20 10*2 15*0.02];
mpcController.Weights.ManipulatedVariables = 5e3*.02;

setEstimator(mpcController, 'custom');

mpcControllerUnst = mpcController;
mpcControllerUnst.Model.Plant.A(2,1) = -sys.A(2,1);
% mpcControllerUnst.Weights.OutputVariables = [100 0 0];

load ControllerDesign\MPCI.mat
mpcI.PredictionHorizon = 20;
mpcI.ControlHorizon = 15;

mpcI.ManipulatedVariables.Min = -4;
mpcI.ManipulatedVariables.Max = 4;
mpcI.OutputVariables(1).Min = -0.1;
mpcI.OutputVariables(1).Max = 0.1;
mpcI.OutputVariables(3).Min = -300;
mpcI.OutputVariables(3).Max = 300;

mpcI.Weights.ManipulatedVariablesRate = 25;
mpcI.Weights.OutputVariables = [250*20 80*2 15*0.02 300*20];
mpcI.Weights.ManipulatedVariables = 5e4*.02;

setEstimator(mpcI, 'custom');

mpcIUnst = mpcI;
mpcIUnst.Model.Plant.A(2,1) = -sysI.A(2,1);
% mpcIUnst.Model.Plant.A(4,1) = mpcIUnst.Model.Plant.A(4,1)*35;
% mpcIUnst.Weights.OutputVariables = [10 0.5 1 100];

% load ControllerDesign\MPCkal.mat
% mpcKalman.ControlHorizon = 5;
% mpcKalman.PredictionHorizon = 10;
% 
% % mpcI.ManipulatedVariables.Min = -6;
% % mpcI.ManipulatedVariables.Max = 6;
% mpcKalman.OutputVariables(1).Min = -0.025;
% mpcKalman.OutputVariables(1).Max = 0.025;
% mpcKalman.OutputVariables(2).Min = -300;
% mpcKalman.OutputVariables(2).Max = 300;
% 
% mpcKalman.Weights.ManipulatedVariablesRate = 0.01;
% mpcKalman.Weights.OutputVariables = [100 20];
% 
% mpcKalmanUnst = mpcKalman;
% mpcKalmanUnst.Model.Plant.A(2,1) = -sys.A(2,1);
% % mpcKalmanUnst.Model.Plant.A(4,1) = mpcKalmanUnst.Model.Plant.A(4,1)*35;
% mpcKalmanUnst.Weights.OutputVariables = [5 1];

% Hinf controller
% [Hinf, ~, ~] = hinfsyn(sys, 3, 1);
% [HinfUnst, ~, ~] = hinfsyn(sysUnst, 3, 1);
% 
% [HinfI, ~, ~] = hinfsyn(sysI, 4, 1);
% [HinfUnstI, ~, ~] = hinfsyn(sysUnstI, 4, 1);

return
%% Validate controllers
folds = ["LQR" "LQI" "MPC" "MPCI"];
names = ["run1" "run2" "run3" "run4"];
maxima = struct();

for F = folds
    figure("Name",F);
    for N = names
        d = strjoin(["load Validation\" F "\" N], '');
        eval(d)
        if any(F == ["LQI" "MPCI"]); s = 4; else s = 3; end
        T = CtrlIn.time;
        for idx = 1:s
            subplot(s+1, 1, idx); hold on
            plot(T, MeasFull(:, idx)); hold off
        end
        subplot(s+1, 1, s+1); hold on
        plot(T, CtrlIn.signals.values); hold off
    end
%     if F == "MPC"; figure("Name",strjoin([F "State Predictions"]))
%         for N = names
%             d = strjoin(["load Validation\" F "\" N], '');
%             eval(d)
%             MPC_plot_proj(MPC_prediction, MeasFull(:, 1:3), h)
%     end; end
%     if F == "MPCI"; figure("Name",strjoin([F "State Predictions"]))
%         for N = names
%             d = strjoin(["load Validation\" F "\" N], '');
%             eval(d)
%             MPC_plot_proj(MPCI_prediction, MeasFull, h)
%     end; end
end


% MPC_plot_proj(MPCI_prediction, MeasFull, h)