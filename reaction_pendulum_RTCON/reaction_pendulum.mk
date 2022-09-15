##################################################################################
##                                                                              ##
##  RTCON_RPEND_VC_USB2_x64.tmf  template makefile                               ##
##                      Builds executable DLL format files for                  ##
##                      W7 x 64 environments                                    ##
##                                                                              ##
##  Packages:   rpend                                                           ##
##                                                                              ##
##  MATLAB versions:             2014a  64 bit                                  ##
##  Simulink versions:           2014a                                          ##
##                                                                              ##
##  Visual C/C++ versions:       10.0 / SDK 7.1                                 ##
##                                                                              ##
##  (C) COPYRIGHT 2016 InTeCo Inc., 2K/KH                                       ##
##                                                                              ##
##                                                                              ##
##                                                                              ##
##                                                                              ##
##################################################################################

# Copyright 1994-2009 The MathWorks, Inc.
#
# File    : grt_vcx64.tmf   $Revision: 1.1.6.16 $
#
# Abstract:
#       Real-Time Workshop template makefile for building a Windows-based
#       stand-alone generic real-time version of Simulink model using
#       generated C code and the
#          Microsoft Visual C/C++ compiler version 8.0 for x64
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1, which will trigger OPTS=-Zi (may vary with
#                               compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rtcon_rpend_usb2.tlc
BUILD_SUCCESS	= ^#^#^# Created RT-CON executable
COMPILER_TOOL_CHAIN = vcx64

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#
#  STARTUP_MESSAGE     - Display startup message window.
#  LINK_RTDAC_USB      - Append RT-DAC/USB libraries.
#  USE_HIGH_PRIORITY   - Boost the priority to the HIGH_PRIORITY class
#  USE_REALTIME_PRIORITY - Boost the priority to the REALTIME_PRIORITY class

MODEL                = reaction_pendulum
MODULES              = rt_matrx.c rt_printf.c rt_logging.c reaction_pendulum_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rtiostream_utils.c rtdacusb2_rpend_dd.c
MAKEFILE             = reaction_pendulum.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2021b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2021b
MATLAB_BIN           = C:\Program Files\MATLAB\R2021b\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2021b\bin
MASTER_ANCHOR_DIR    = 
START_DIR            = C:\Users\saumans\Documents\reaction-pendulum
SOLVER               = 
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 0
BUILDARGS            =  MAT_FILE=1 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 OPTS="-DEXT_MODE -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1"
MULTITASKING         = 0
EXT_MODE             = 1
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS            = 
TARGET_LANG_EXT      = c
MEX_OPT_FILE         = 
VISUAL_VER           = 15.0
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 

CLASSIC_INTERFACE    = 0
# Optional for GRT
ONESTEPFCN           = 1
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0

STARTUP_MESSAGE      = 1
USE_HIGH_PRIORITY    = 0
USE_REALTIME_PRIORITY = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = reaction_pendulum_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

##############################################################################
#
# RT-CON definitions
#
RTCON_DIR = $(MATLAB_ROOT)\toolbox\rpend
RTCON_DIR_C = $(RTCON_DIR)\src
RTCON_DIR_BLOCKS = $(RTCON_DIR)\blocks\c


#--------------------------- Tool Specifications ------------------------------

CPU = AMD64
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak
APPVER = 5.02

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl
#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\common
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\grt

# Additional file include paths

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\reaction_pendulum_RTCON
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\coder\rtiostream\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(INCLUDE)


#------------------------ External mode ---------------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!if $(EXT_MODE) == 1
EXT_CC_OPTS = -DEXT_MODE # -DVERBOSE
!if $(EXTMODE_TRANSPORT) == 0 #tcpip
EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
EXT_LIB = wsock32.lib
!endif
!if $(EXTMODE_TRANSPORT) == 1 #serial_win32
EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
EXT_SRC = $(EXT_SRC) ext_serial_pkt.c ext_serial_win32_port.c
EXT_LIB =
!endif
!if $(TMW_EXTMODE_TESTING) == 1
EXT_SRC     = $(EXT_SRC) ext_test.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DTMW_EXTMODE_TESTING
!endif
!if $(EXTMODE_STATIC) == 1
EXT_SRC     = $(EXT_SRC) mem_mgr.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!endif
!else
EXT_SRC     =
EXT_CC_OPTS =
EXT_LIB     =
!endif

#------------------------ rtModel ----------------------------------------------

RTM_CC_OPTS = -DUSE_RTMODEL

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
!if "$(DEBUG_BUILD)" == "0"
OPTS =
!else
#   Set OPT_OPTS=-Zi and any additional flags for debugging
OPTS = -Zi
!endif

!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)
!endif

# C-compiler options
#RTCON_OPTS = /D outportb=outp /D outport=outpw /D inportb=inp /D inport=inpw
RTCON_OPTS = /D MODEL_NAME_STR="""$(MODEL)"""
#RTCON_OPTS = $(RTCON_OPTS) /DrtBIOSignals=rtBlockIOSignals
!if $(STARTUP_MESSAGE) == 1
RTCON_OPTS = $(RTCON_OPTS) -DSTARTUP_MESSAGE
!endif
!if $(USE_HIGH_PRIORITY) == 1
!if $(USE_REALTIME_PRIORITY) == 0
RTCON_OPTS = $(RTCON_OPTS) -DUSE_HIGH_PRIORITY 
!endif
!endif
!if $(USE_REALTIME_PRIORITY) == 1
RTCON_OPTS = $(RTCON_OPTS) -DUSE_REALTIME_PRIORITY 
!endif

CC_OPTS = $(CC_OPTS) $(RTCON_OPTS)

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
          -DRT_MODEL=RT_MODEL_$(MODEL)_T \
##CPP_REQ_DEFINES = -DRT -DNUMST=$(NUMST) \
		  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DMT=$(MULTITASKING) -DHAVESTDIO 

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS   = $(MODELREF_INC_PATH) $(cflags) $(cvarsmt) /wd4996 $(CC_OPTS)\
	   $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(MODELREF_INC_PATH) $(cflags) $(cvarsmt) /wd4996 /EHsc- \
	   $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
#LDFLAGS  = $(ldebug) $(conflags) $(EXT_LIB) $(conlibs) libcpmt.lib $(ADDITIONAL_LDFLAGS)

LDRTCONFLAGS = /RELEASE /INCREMENTAL:NO /NOLOGO /DLL $(EXT_LIB) 
LDRTCONFLAGS = $(LDRTCONFLAGS) kernel32.lib  ws2_32.lib mswsock.lib advapi32.lib user32.lib
LDFLAGS  = $(LDRTCONFLAGS) libcpmt.lib $(ADDITIONAL_LDFLAGS)
LDFLAGS  = $(LDRTCONFLAGS) /EXPORT:SingleStep /EXPORT:GetTimerPeriod /EXPORT:DLL_IPC_Proc


# libcpmt.lib is the multi-threaded, static lib version of the C++ standard lib

#----------------------------- Source Files -----------------------------------


#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
# PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dll
PRODUCT   = $(MODEL).dll

REQ_SRCS  = $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
            rt_sim.c   $(SOLVER) $(EXT_SRC)
#            grt_main.c rt_sim.c  $(SOLVER) $(EXT_SRC)

RTCON_SRCS = rtw_ipc.c rtw_dll.c rtw_aux.c 

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif

USER_SRCS =

SRCS = $(RTCON_SRCS) $(REQ_SRCS) $(USER_SRCS) 
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
# ------------------------- Additional Libraries ------------------------------

LIBS =


LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."" $(RTCON_DIR_C)
	@cmd /C "echo conflags:           $(conflags)"
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) $(LDFLAGS) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@del $(CMD_FILE)
	@cmd /C "echo $(BUILD_SUCCESS) executable $(MODEL).exe"
	@cmd /C "echo $(BUILD_SUCCESS) executable $(PRODUCT)"
	@cmd /C "echo LDFLAGS:         $(LDFLAGS)"
		@cmd /C "echo SHARED_LIB:      $(SHARED_LIB)"
	@cmd /C "echo LIBS:            $(LIBS)"
	@cmd /C "echo MAT_LIBS:        $(MAT_LIBS)"
	@cmd /C "echo CMD_FILE:        $(CMD_FILE)"
	@cmd /C "echo ------------------------------"
	@cmd /C "echo ldebug:             $(ldebug)"
	@cmd /C "echo conflags:           $(conflags)"
	@cmd /C "echo EXT_LIB:            $(EXT_LIB)"
	@cmd /C "echo conlibs:            $(conlibs)"
	@cmd /C "echo ADDITIONAL_LDFLAGS: $(ADDITIONAL_LDFLAGS)"

!else
#--- Model reference RTW Target ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE)
	@cmd /C "echo $(BUILD_SUCCESS) static library $(MODELLIB)"
!endif

!if "$(TARGET_LANG_EXT)" ==  "cpp"
{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) /TP $(CPPFLAGS) $<
!else
{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\rtiostreamtcpip}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# RT-CON sources
{$(RTCON_DIR_C)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(RTCON_DIR_C)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<


# RT-CON sources
{$(RTCON_DIR_BLOCKS)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

rt_matrx.obj : $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c

rt_printf.obj : $(MATLAB_ROOT)\rtw\c\src\rt_printf.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_printf.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_printf.c

rt_logging.obj : $(MATLAB_ROOT)\rtw\c\src\rt_logging.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_logging.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_logging.c

rtiostream_utils.obj : $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils\rtiostream_utils.c



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:





#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
