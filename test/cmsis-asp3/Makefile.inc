#
# Makefile for a cmsis-asp3 test
#

TOPPERS_KERNEL = asp3

# compile switch
CDEFS := -DUSE_ASP3_FOR_STM

# name of main application
APPLNAME = sample3

# information for directory tree
CMSISTEST_MAKEFILEDIR := $(ROOTDIR)/cmsis-asp3/test/build
APPLDIR	:= $(APPDIR)
APPLDIR	+= $(APPDIR)/config

# additional files for configuration
APPL_COBJS += mros2_user_config.o

include $(CMSISTEST_MAKEFILEDIR)/Makefile.test