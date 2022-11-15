    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (reaction_pendulum_P)
        ;%
            section.nData     = 118;
            section.data(118)  = dumData; %prealloc

                    ;% reaction_pendulum_P.K
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_P.K_Unst
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% reaction_pendulum_P.SFunction_P2_Size
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% reaction_pendulum_P.h
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 8;

                    ;% reaction_pendulum_P.FilteredDerivative1_A
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 9;

                    ;% reaction_pendulum_P.FilteredDerivative1_B
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 10;

                    ;% reaction_pendulum_P.FilteredDerivative1_K
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 11;

                    ;% reaction_pendulum_P.CheckDiscreteGradient_gradient
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% reaction_pendulum_P.FilteredDerivative1_minRatio
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% reaction_pendulum_P.FilteredDerivative1_x0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% reaction_pendulum_P.Lykyhatkk1_Y0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% reaction_pendulum_P.deltax_Y0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% reaction_pendulum_P.LQIUNSTABLE_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 17;

                    ;% reaction_pendulum_P.Defaultstoponerror_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 21;

                    ;% reaction_pendulum_P.Controllerselection_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 22;

                    ;% reaction_pendulum_P.Ref_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 23;

                    ;% reaction_pendulum_P.Delay1_InitialCondition
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 26;

                    ;% reaction_pendulum_P.Constant_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 27;

                    ;% reaction_pendulum_P.Integrator_gainval
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 28;

                    ;% reaction_pendulum_P.Integrator_UpperSat
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 29;

                    ;% reaction_pendulum_P.Integrator_LowerSat
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 30;

                    ;% reaction_pendulum_P.Saturation_UpperSat
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 31;

                    ;% reaction_pendulum_P.Saturation_LowerSat
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 32;

                    ;% reaction_pendulum_P.DisturbanceState_Value
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 33;

                    ;% reaction_pendulum_P.last_mv_InitialCondition
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 36;

                    ;% reaction_pendulum_P.ym_zero_Value
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 37;

                    ;% reaction_pendulum_P.md_zero_Value
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 40;

                    ;% reaction_pendulum_P.umin_zero_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 41;

                    ;% reaction_pendulum_P.umax_zero_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 42;

                    ;% reaction_pendulum_P.ymin_zero_Value
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 43;

                    ;% reaction_pendulum_P.ymax_zero_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 46;

                    ;% reaction_pendulum_P.E_zero_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 49;

                    ;% reaction_pendulum_P.umin_scale4_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 50;

                    ;% reaction_pendulum_P.F_zero_Value
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 51;

                    ;% reaction_pendulum_P.ymin_scale1_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 54;

                    ;% reaction_pendulum_P.G_zero_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 57;

                    ;% reaction_pendulum_P.S_zero_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 58;

                    ;% reaction_pendulum_P.ymin_scale2_Gain
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 59;

                    ;% reaction_pendulum_P.switch_zero_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 60;

                    ;% reaction_pendulum_P.extmv_zero_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 61;

                    ;% reaction_pendulum_P.extmv_scale_Gain
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 62;

                    ;% reaction_pendulum_P.mvtarget_zero_Value
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 63;

                    ;% reaction_pendulum_P.extmv_scale1_Gain
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 64;

                    ;% reaction_pendulum_P.ywt_zero_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 65;

                    ;% reaction_pendulum_P.uwt_zero_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 68;

                    ;% reaction_pendulum_P.duwt_zero_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 69;

                    ;% reaction_pendulum_P.ecrwt_zero_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 70;

                    ;% reaction_pendulum_P.umin_scale1_Gain
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 71;

                    ;% reaction_pendulum_P.DiscreteTimeIntegrator_gainval
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 72;

                    ;% reaction_pendulum_P.DiscreteTimeIntegrator_IC
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 73;

                    ;% reaction_pendulum_P.DiscreteTimeIntegrator_UpperSat
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 74;

                    ;% reaction_pendulum_P.DiscreteTimeIntegrator_LowerSat
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 75;

                    ;% reaction_pendulum_P.DisturbanceState1_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 76;

                    ;% reaction_pendulum_P.last_mv_InitialCondition_n
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 79;

                    ;% reaction_pendulum_P.ym_zero_Value_c
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 80;

                    ;% reaction_pendulum_P.Constant_Value_b
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 84;

                    ;% reaction_pendulum_P.md_zero_Value_k
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 85;

                    ;% reaction_pendulum_P.umin_zero_Value_m
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 86;

                    ;% reaction_pendulum_P.umax_zero_Value_o
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 87;

                    ;% reaction_pendulum_P.ymin_zero_Value_l
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 88;

                    ;% reaction_pendulum_P.ymax_zero_Value_b
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 92;

                    ;% reaction_pendulum_P.E_zero_Value_e
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 96;

                    ;% reaction_pendulum_P.umin_scale4_Gain_d
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 97;

                    ;% reaction_pendulum_P.F_zero_Value_l
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 98;

                    ;% reaction_pendulum_P.ymin_scale1_Gain_j
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 102;

                    ;% reaction_pendulum_P.G_zero_Value_b
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 106;

                    ;% reaction_pendulum_P.S_zero_Value_o
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 107;

                    ;% reaction_pendulum_P.ymin_scale2_Gain_o
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 108;

                    ;% reaction_pendulum_P.switch_zero_Value_n
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 109;

                    ;% reaction_pendulum_P.extmv_zero_Value_f
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 110;

                    ;% reaction_pendulum_P.extmv_scale_Gain_l
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 111;

                    ;% reaction_pendulum_P.mvtarget_zero_Value_a
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 112;

                    ;% reaction_pendulum_P.extmv_scale1_Gain_h
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 113;

                    ;% reaction_pendulum_P.ywt_zero_Value_c
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 114;

                    ;% reaction_pendulum_P.uwt_zero_Value_e
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 118;

                    ;% reaction_pendulum_P.duwt_zero_Value_p
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 119;

                    ;% reaction_pendulum_P.ecrwt_zero_Value_a
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 120;

                    ;% reaction_pendulum_P.umin_scale1_Gain_a
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 121;

                    ;% reaction_pendulum_P.Step3_Time
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 122;

                    ;% reaction_pendulum_P.Step3_Y0
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 123;

                    ;% reaction_pendulum_P.Step3_YFinal
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 124;

                    ;% reaction_pendulum_P.Step4_Time
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 125;

                    ;% reaction_pendulum_P.Step4_Y0
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 126;

                    ;% reaction_pendulum_P.Step4_YFinal
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 127;

                    ;% reaction_pendulum_P.Gain_Gain
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 128;

                    ;% reaction_pendulum_P.Gain2_Gain
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 129;

                    ;% reaction_pendulum_P.Saturation_UpperSat_h
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 130;

                    ;% reaction_pendulum_P.Saturation_LowerSat_f
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 131;

                    ;% reaction_pendulum_P.Step2_Y0
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 132;

                    ;% reaction_pendulum_P.Step2_YFinal
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 133;

                    ;% reaction_pendulum_P.Gain_Gain_d
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 134;

                    ;% reaction_pendulum_P.Prescaler_Value
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 136;

                    ;% reaction_pendulum_P.ThermFlag_Value
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 137;

                    ;% reaction_pendulum_P.SFunction_P1_Size
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 138;

                    ;% reaction_pendulum_P.SFunction_P1
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 140;

                    ;% reaction_pendulum_P.PendulumConverttorad_Gain
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 141;

                    ;% reaction_pendulum_P.DCConverttorad_Gain
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 142;

                    ;% reaction_pendulum_P.Memory1_InitialCondition
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 143;

                    ;% reaction_pendulum_P.rad2RPM_Gain
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 144;

                    ;% reaction_pendulum_P.Memory_InitialCondition
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 145;

                    ;% reaction_pendulum_P.Gain1_Gain
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 146;

                    ;% reaction_pendulum_P.DCConverttoA1_Gain
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 147;

                    ;% reaction_pendulum_P.memory_InitialCondition
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 148;

                    ;% reaction_pendulum_P.rising_Gain
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 149;

                    ;% reaction_pendulum_P.expander_Gain
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 150;

                    ;% reaction_pendulum_P.falling_Gain
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 152;

                    ;% reaction_pendulum_P.IC_Value
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 153;

                    ;% reaction_pendulum_P.KalmanGainM_Value
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 154;

                    ;% reaction_pendulum_P.C_Value
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 163;

                    ;% reaction_pendulum_P.Constant3_Value
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 172;

                    ;% reaction_pendulum_P.Delay_InitialCondition
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 175;

                    ;% reaction_pendulum_P.A_Value
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 176;

                    ;% reaction_pendulum_P.B_Value
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 185;

                    ;% reaction_pendulum_P.CovarianceZ_Value
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 188;

                    ;% reaction_pendulum_P.KalmanGainL_Value
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 197;

                    ;% reaction_pendulum_P.D_Value
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 206;

                    ;% reaction_pendulum_P.umin_scale5_Gain
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 209;

                    ;% reaction_pendulum_P.umin_scale5_Gain_f
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 293;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% reaction_pendulum_P.Memory_InitialCondition_a
                    section.data(1).logicalSrcIdx = 118;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_P.Memory_InitialCondition_k
                    section.data(2).logicalSrcIdx = 119;
                    section.data(2).dtTransOffset = 80;

                    ;% reaction_pendulum_P.Enable_Value
                    section.data(3).logicalSrcIdx = 120;
                    section.data(3).dtTransOffset = 190;

                    ;% reaction_pendulum_P.isSqrtUsed_Value
                    section.data(4).logicalSrcIdx = 121;
                    section.data(4).dtTransOffset = 191;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (reaction_pendulum_B)
        ;%
            section.nData     = 33;
            section.data(33)  = dumData; %prealloc

                    ;% reaction_pendulum_B.Delay1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_B.Probe
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% reaction_pendulum_B.Constant
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% reaction_pendulum_B.AB
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% reaction_pendulum_B.DiscreteTimeIntegrator
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% reaction_pendulum_B.TmpSignalConversionAtToWorkspac
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% reaction_pendulum_B.Control
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 11;

                    ;% reaction_pendulum_B.Sum
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% reaction_pendulum_B.Saturation
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% reaction_pendulum_B.Gain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% reaction_pendulum_B.Prescaler
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% reaction_pendulum_B.ThermFlag
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% reaction_pendulum_B.SFunction_o1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% reaction_pendulum_B.SFunction_o2
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% reaction_pendulum_B.SFunction_o3
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% reaction_pendulum_B.SFunction_o4
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% reaction_pendulum_B.SFunction_o5
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% reaction_pendulum_B.SFunction_o6
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% reaction_pendulum_B.SFunction_o7
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 24;

                    ;% reaction_pendulum_B.PendulumAnglerad
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 26;

                    ;% reaction_pendulum_B.Periodms
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 27;

                    ;% reaction_pendulum_B.DCVelrads
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 28;

                    ;% reaction_pendulum_B.DCConverttoA1
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 29;

                    ;% reaction_pendulum_B.IC
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 30;

                    ;% reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 31;

                    ;% reaction_pendulum_B.umin_scale5
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 33;

                    ;% reaction_pendulum_B.umin_scale5_g
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 117;

                    ;% reaction_pendulum_B.u
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 180;

                    ;% reaction_pendulum_B.u_g
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 181;

                    ;% reaction_pendulum_B.y
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 182;

                    ;% reaction_pendulum_B.prev_signal
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 183;

                    ;% reaction_pendulum_B.Product2
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 184;

                    ;% reaction_pendulum_B.Product3
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 187;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% reaction_pendulum_B.iAout
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_B.iAout_f
                    section.data(2).logicalSrcIdx = 34;
                    section.data(2).dtTransOffset = 110;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (reaction_pendulum_DW)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Delay1_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.Integrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% reaction_pendulum_DW.last_mv_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% reaction_pendulum_DW.last_mv_DSTATE_p
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% reaction_pendulum_DW.MemoryX_DSTATE
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% reaction_pendulum_DW.Delay_DSTATE
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% reaction_pendulum_DW.Memory1_PreviousInput
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% reaction_pendulum_DW.Memory_PreviousInput
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% reaction_pendulum_DW.memory_PreviousInput
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.PlotState_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 4;

                    ;% reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 5;

                    ;% reaction_pendulum_DW.ToWorkspace1_PWORK_i.LoggedData
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 6;

                    ;% reaction_pendulum_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 7;

                    ;% reaction_pendulum_DW.ToWorkspace2_PWORK_i.LoggedData
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 8;

                    ;% reaction_pendulum_DW.ToWorkspace_PWORK_e.LoggedData
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Integrator_PrevResetState
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.EnabledSubsystem_SubsysRanBC
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% reaction_pendulum_DW.MeasurementUpdate_SubsysRanBC
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Memory_PreviousInput_e
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.Memory_PreviousInput_c
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 80;

                    ;% reaction_pendulum_DW.IC_FirstOutputTime
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 190;

                    ;% reaction_pendulum_DW.icLoad
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 191;

                    ;% reaction_pendulum_DW.EnabledSubsystem_MODE
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 192;

                    ;% reaction_pendulum_DW.MeasurementUpdate_MODE
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 193;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2895288125;
    targMap.checksum1 = 2409429721;
    targMap.checksum2 = 761229482;
    targMap.checksum3 = 1195792861;

