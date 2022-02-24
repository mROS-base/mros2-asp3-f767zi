#
# Makefile definition for mros2 application
#

# name of main application
APPLNAME = app

# log level: 0(DEBUG), 1(INFO), 2(WARN), 3(ERROR), 4(FATAL), 5(NONE)
# NOTE: also check `initLogMask` in app.cdl for syslog setting
CDEFS := -DMROS2_LOG_MIN_SEVERITY=2

# information for directory tree
APPLDIR	:= $(APPDIR)
APPLDIR	+= $(APPDIR)/config

# link option for C++ code
SRCLANG = c++
APPL_CXXLIBS += -specs=nano.specs

# compile switch
CDEFS += -DUSE_ASP3_FOR_STM

# additional files for configuration
APPL_COBJS := task_impl.o
APPL_COBJS += autosar_os_ext_user_config.o
APPL_COBJS += autosar_os_ext_asp3_user_config.o
APPL_COBJS += mros2_user_config.o
