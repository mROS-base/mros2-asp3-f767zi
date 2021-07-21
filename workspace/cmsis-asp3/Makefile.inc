#
# Makefile for a cmsis-asp3 test
#

TOPPERS_KERNEL = asp3

# compile switch
CDEFS := -DMROS2_USE_ASP3

# name of main application
APPLNAME = sample3

# information for directory tree
CMSISTEST_MAKEFILEDIR := $(ROOTDIR)/cmsis-asp3/test/build

include $(CMSISTEST_MAKEFILEDIR)/Makefile.test