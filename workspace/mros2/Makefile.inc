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

# information for user configuration
APPLDIR	:= $(APPDIR)
APPLDIR	+= $(APPDIR)/config
APPLDIR	+= $(APPDIR)/config/asp

# additional files for main application
APPL_COBJS := sample_ping.o
APPL_COBJS += atk2ext_user_config.o
APPL_COBJS += atk2ext_asp_user_config.o
