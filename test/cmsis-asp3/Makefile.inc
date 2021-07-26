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

include $(CMSISTEST_MAKEFILEDIR)/Makefile.test