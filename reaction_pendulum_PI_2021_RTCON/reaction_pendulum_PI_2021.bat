
set skipSetupArg=%1
if "%skipSetupArg%" NEQ "skip_setup_msvc" (
call "setup_msvc.bat"
)

cd .
nmake -f reaction_pendulum_PI_2021.mk  MAT_FILE=1 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 OPTS="-DEXT_MODE -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1"
@if errorlevel 1 goto error_exit
exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1