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
            section.nData     = 96;
            section.data(96)  = dumData; %prealloc

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

                    ;% reaction_pendulum_P.FilteredDerivative_A
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 10;

                    ;% reaction_pendulum_P.FilteredDerivative1_B
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 11;

                    ;% reaction_pendulum_P.FilteredDerivative_B
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% reaction_pendulum_P.FilteredDerivative1_K
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% reaction_pendulum_P.FilteredDerivative_K
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% reaction_pendulum_P.FilteredDerivative1_minRatio
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% reaction_pendulum_P.FilteredDerivative_minRatio
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% reaction_pendulum_P.FilteredDerivative1_x0
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 17;

                    ;% reaction_pendulum_P.FilteredDerivative_x0
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 18;

                    ;% reaction_pendulum_P.Defaultstoponerror_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 19;

                    ;% reaction_pendulum_P.Controllerselection_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 20;

                    ;% reaction_pendulum_P.Delay1_InitialCondition
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 21;

                    ;% reaction_pendulum_P.Constant_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 22;

                    ;% reaction_pendulum_P.Integrator_gainval
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 23;

                    ;% reaction_pendulum_P.Integrator_UpperSat
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 24;

                    ;% reaction_pendulum_P.Integrator_LowerSat
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 25;

                    ;% reaction_pendulum_P.Saturation_UpperSat
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 26;

                    ;% reaction_pendulum_P.Saturation_LowerSat
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 27;

                    ;% reaction_pendulum_P.last_x_InitialCondition
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 28;

                    ;% reaction_pendulum_P.last_mv_InitialCondition
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 34;

                    ;% reaction_pendulum_P.Ref_Value
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 35;

                    ;% reaction_pendulum_P.md_zero_Value
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 38;

                    ;% reaction_pendulum_P.umin_zero_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 39;

                    ;% reaction_pendulum_P.umax_zero_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 40;

                    ;% reaction_pendulum_P.ymin_zero_Value
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 41;

                    ;% reaction_pendulum_P.ymax_zero_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 44;

                    ;% reaction_pendulum_P.E_zero_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 47;

                    ;% reaction_pendulum_P.umin_scale4_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 48;

                    ;% reaction_pendulum_P.F_zero_Value
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 49;

                    ;% reaction_pendulum_P.ymin_scale1_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 52;

                    ;% reaction_pendulum_P.G_zero_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 55;

                    ;% reaction_pendulum_P.S_zero_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 56;

                    ;% reaction_pendulum_P.ymin_scale2_Gain
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 57;

                    ;% reaction_pendulum_P.switch_zero_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 58;

                    ;% reaction_pendulum_P.extmv_zero_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 59;

                    ;% reaction_pendulum_P.extmv_scale_Gain
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 60;

                    ;% reaction_pendulum_P.mvtarget_zero_Value
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 61;

                    ;% reaction_pendulum_P.extmv_scale1_Gain
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 62;

                    ;% reaction_pendulum_P.ywt_zero_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 63;

                    ;% reaction_pendulum_P.uwt_zero_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 66;

                    ;% reaction_pendulum_P.duwt_zero_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 67;

                    ;% reaction_pendulum_P.ecrwt_zero_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 68;

                    ;% reaction_pendulum_P.umin_scale1_Gain
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 69;

                    ;% reaction_pendulum_P.last_x_InitialCondition_e
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 70;

                    ;% reaction_pendulum_P.last_mv_InitialCondition_g
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 76;

                    ;% reaction_pendulum_P.Ref1_Value
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 77;

                    ;% reaction_pendulum_P.md_zero_Value_o
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 80;

                    ;% reaction_pendulum_P.umin_zero_Value_m
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 81;

                    ;% reaction_pendulum_P.umax_zero_Value_n
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 82;

                    ;% reaction_pendulum_P.ymin_zero_Value_g
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 83;

                    ;% reaction_pendulum_P.ymax_zero_Value_m
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 86;

                    ;% reaction_pendulum_P.E_zero_Value_f
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 89;

                    ;% reaction_pendulum_P.umin_scale4_Gain_e
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 90;

                    ;% reaction_pendulum_P.F_zero_Value_f
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 91;

                    ;% reaction_pendulum_P.ymin_scale1_Gain_g
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 94;

                    ;% reaction_pendulum_P.G_zero_Value_a
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 97;

                    ;% reaction_pendulum_P.S_zero_Value_d
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 98;

                    ;% reaction_pendulum_P.ymin_scale2_Gain_i
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 99;

                    ;% reaction_pendulum_P.switch_zero_Value_f
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 100;

                    ;% reaction_pendulum_P.extmv_zero_Value_k
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 101;

                    ;% reaction_pendulum_P.extmv_scale_Gain_j
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 102;

                    ;% reaction_pendulum_P.mvtarget_zero_Value_d
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 103;

                    ;% reaction_pendulum_P.extmv_scale1_Gain_l
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 104;

                    ;% reaction_pendulum_P.ywt_zero_Value_k
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 105;

                    ;% reaction_pendulum_P.uwt_zero_Value_d
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 108;

                    ;% reaction_pendulum_P.duwt_zero_Value_j
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 109;

                    ;% reaction_pendulum_P.ecrwt_zero_Value_e
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 110;

                    ;% reaction_pendulum_P.umin_scale1_Gain_g
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 111;

                    ;% reaction_pendulum_P.Gain2_Gain
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 112;

                    ;% reaction_pendulum_P.Saturation_UpperSat_h
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 113;

                    ;% reaction_pendulum_P.Saturation_LowerSat_f
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 114;

                    ;% reaction_pendulum_P.Step2_Y0
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 115;

                    ;% reaction_pendulum_P.Step2_YFinal
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 116;

                    ;% reaction_pendulum_P.Gain_Gain
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 117;

                    ;% reaction_pendulum_P.Prescaler_Value
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 119;

                    ;% reaction_pendulum_P.ThermFlag_Value
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 120;

                    ;% reaction_pendulum_P.SFunction_P1_Size
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 121;

                    ;% reaction_pendulum_P.SFunction_P1
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 123;

                    ;% reaction_pendulum_P.PendulumConverttorad_Gain
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 124;

                    ;% reaction_pendulum_P.DCConverttorad_Gain
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 125;

                    ;% reaction_pendulum_P.Memory1_InitialCondition
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 126;

                    ;% reaction_pendulum_P.rad2RPM_Gain
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 127;

                    ;% reaction_pendulum_P.Memory_InitialCondition
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 128;

                    ;% reaction_pendulum_P.Gain1_Gain
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 129;

                    ;% reaction_pendulum_P.DCConverttoA1_Gain
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 130;

                    ;% reaction_pendulum_P.Constant_Value_p
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 131;

                    ;% reaction_pendulum_P.Integrator_gainval_n
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 132;

                    ;% reaction_pendulum_P.Integrator_UpperSat_o
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 133;

                    ;% reaction_pendulum_P.Integrator_LowerSat_h
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 134;

                    ;% reaction_pendulum_P.Saturation_UpperSat_b
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 135;

                    ;% reaction_pendulum_P.Saturation_LowerSat_k
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 136;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% reaction_pendulum_P.Memory_InitialCondition_p
                    section.data(1).logicalSrcIdx = 96;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_P.Memory_InitialCondition_a
                    section.data(2).logicalSrcIdx = 97;
                    section.data(2).dtTransOffset = 60;

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
            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

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

                    ;% reaction_pendulum_B.Control
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% reaction_pendulum_B.Saturation
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% reaction_pendulum_B.Gain
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% reaction_pendulum_B.Prescaler
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% reaction_pendulum_B.ThermFlag
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% reaction_pendulum_B.SFunction_o1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% reaction_pendulum_B.SFunction_o2
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% reaction_pendulum_B.SFunction_o3
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

                    ;% reaction_pendulum_B.SFunction_o4
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 15;

                    ;% reaction_pendulum_B.SFunction_o5
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 16;

                    ;% reaction_pendulum_B.SFunction_o6
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 17;

                    ;% reaction_pendulum_B.SFunction_o7
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 18;

                    ;% reaction_pendulum_B.PendulumAnglerad
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 20;

                    ;% reaction_pendulum_B.Periodms
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 21;

                    ;% reaction_pendulum_B.DCVelrads
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 22;

                    ;% reaction_pendulum_B.DCConverttoA1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 23;

                    ;% reaction_pendulum_B.Probe_f
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 24;

                    ;% reaction_pendulum_B.Constant_a
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 26;

                    ;% reaction_pendulum_B.AB_o
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 27;

                    ;% reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 28;

                    ;% reaction_pendulum_B.xk1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 30;

                    ;% reaction_pendulum_B.u
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 36;

                    ;% reaction_pendulum_B.xk1_a
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 37;

                    ;% reaction_pendulum_B.u_f
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 43;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% reaction_pendulum_B.iAout
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_B.iAout_m
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 60;

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
            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Delay1_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.Integrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% reaction_pendulum_DW.last_mv_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% reaction_pendulum_DW.last_mv_DSTATE_d
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% reaction_pendulum_DW.Integrator_DSTATE_g
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% reaction_pendulum_DW.last_x_PreviousInput
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% reaction_pendulum_DW.last_x_PreviousInput_b
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% reaction_pendulum_DW.Memory1_PreviousInput
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 18;

                    ;% reaction_pendulum_DW.Memory_PreviousInput
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.PlotState_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 4;

                    ;% reaction_pendulum_DW.Observer_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 5;

                    ;% reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Integrator_PrevResetState
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.Integrator_PrevResetState_l
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% reaction_pendulum_DW.Memory_PreviousInput_h
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_DW.Memory_PreviousInput_e
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 60;

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


    targMap.checksum0 = 737472710;
    targMap.checksum1 = 1053608817;
    targMap.checksum2 = 1229746792;
    targMap.checksum3 = 4284285695;

