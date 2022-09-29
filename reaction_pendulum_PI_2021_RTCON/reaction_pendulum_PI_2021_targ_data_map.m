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
        ;% Auto data (reaction_pendulum_PI_2021_P)
        ;%
            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% reaction_pendulum_PI_2021_P.SFunction_P2_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_PI_2021_P.h
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% reaction_pendulum_PI_2021_P.DiscretePIDController_I
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% reaction_pendulum_PI_2021_P.DiscretePIDController_InitialCo
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% reaction_pendulum_PI_2021_P.DiscretePIDController_P
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% reaction_pendulum_PI_2021_P.Constant1_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% reaction_pendulum_PI_2021_P.Constant_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% reaction_pendulum_PI_2021_P.Reset_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% reaction_pendulum_PI_2021_P.Normal_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% reaction_pendulum_PI_2021_P.DC_Ctrl1_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 10;

                    ;% reaction_pendulum_PI_2021_P.Delay_InitialCondition
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 11;

                    ;% reaction_pendulum_PI_2021_P.Integrator_gainval
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 12;

                    ;% reaction_pendulum_PI_2021_P.Gain2_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 13;

                    ;% reaction_pendulum_PI_2021_P.Saturation_UpperSat
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 14;

                    ;% reaction_pendulum_PI_2021_P.Saturation_LowerSat
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 15;

                    ;% reaction_pendulum_PI_2021_P.Gain_Gain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 16;

                    ;% reaction_pendulum_PI_2021_P.Prescaler_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 18;

                    ;% reaction_pendulum_PI_2021_P.ThermFlag_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 19;

                    ;% reaction_pendulum_PI_2021_P.SFunction_P1_Size
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 20;

                    ;% reaction_pendulum_PI_2021_P.SFunction_P1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 22;

                    ;% reaction_pendulum_PI_2021_P.PendulumConverttorad_Gain
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 23;

                    ;% reaction_pendulum_PI_2021_P.DCConverttorad_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 24;

                    ;% reaction_pendulum_PI_2021_P.Memory1_InitialCondition
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 25;

                    ;% reaction_pendulum_PI_2021_P.rad2RPM_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 26;

                    ;% reaction_pendulum_PI_2021_P.Memory_InitialCondition
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 27;

                    ;% reaction_pendulum_PI_2021_P.Gain1_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 28;

                    ;% reaction_pendulum_PI_2021_P.DCConverttoA1_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 29;

                    ;% reaction_pendulum_PI_2021_P.Constant2_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 30;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% reaction_pendulum_PI_2021_P.ManualSwitch1_CurrentSetting
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_PI_2021_P.ManualSwitch_CurrentSetting
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% reaction_pendulum_PI_2021_P.ResetEncoders_CurrentSetting
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 2;

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
        nTotSects     = 1;
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
        ;% Auto data (reaction_pendulum_PI_2021_B)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% reaction_pendulum_PI_2021_B.Control
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_PI_2021_B.Saturation
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% reaction_pendulum_PI_2021_B.Gain
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% reaction_pendulum_PI_2021_B.Prescaler
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% reaction_pendulum_PI_2021_B.ThermFlag
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o2
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o3
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o4
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o5
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 10;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o6
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 11;

                    ;% reaction_pendulum_PI_2021_B.SFunction_o7
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 12;

                    ;% reaction_pendulum_PI_2021_B.PendulumAnglerad
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% reaction_pendulum_PI_2021_B.Periodms
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 15;

                    ;% reaction_pendulum_PI_2021_B.DCVelrads
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 16;

                    ;% reaction_pendulum_PI_2021_B.DCConverttoA1
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 17;

                    ;% reaction_pendulum_PI_2021_B.Product1
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 18;

                    ;% reaction_pendulum_PI_2021_B.TmpSignalConversionAtToWorkspac
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        nTotSects     = 2;
        sectIdxOffset = 1;

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
        ;% Auto data (reaction_pendulum_PI_2021_DW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% reaction_pendulum_PI_2021_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_PI_2021_DW.Integrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% reaction_pendulum_PI_2021_DW.Memory1_PreviousInput
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% reaction_pendulum_PI_2021_DW.Memory_PreviousInput
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% reaction_pendulum_PI_2021_DW.PlotState_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% reaction_pendulum_PI_2021_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 4;

                    ;% reaction_pendulum_PI_2021_DW.ToWorkspace_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 5;

                    ;% reaction_pendulum_PI_2021_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
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


    targMap.checksum0 = 718429032;
    targMap.checksum1 = 609093004;
    targMap.checksum2 = 662411530;
    targMap.checksum3 = 3683977293;

