#
# Makefile definition for mros2 application
#

# link option for C++ code
SRCLANG = c++
APPL_CXXLIBS += -specs=nano.specs

# compile switch
CDEFS := -DUSE_ASP3_FOR_STM

# name of main application
APPLNAME = sample3

# information for directory tree
APPLDIR	:= $(APPDIR)
APPLDIR	+= $(APPDIR)/config

# additional files for configuration
APPL_COBJS := sample_ping.o
APPL_COBJS += autosar_os_ext_user_config.o
APPL_COBJS += autosar_os_ext_asp3_user_config.o
APPL_COBJS += mros2_user_config.o
