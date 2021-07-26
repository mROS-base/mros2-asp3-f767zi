# information for directory tree
ROOTDIR := ../../..
APPDIR := .
APPLDIR	:= $(APPDIR)/

TOPPERS_KERNEL = asp3
ifeq ($(TOPPERS_KERNEL),asp3)
	CDEFS := -DUSE_ASP3_FOR_STM
	# name of main application
	APPLNAME = sample3
else ifeq ($(TOPPERS_KERNEL),asp)
	CDEFS := -DUSE_ASP_FOR_STM
	# name of main application
	APPLNAME = sample1
endif

# additional files for main application
APPL_COBJS := sample_ping.o

# information for user configuration
APPLDIR += ./config
APPLDIR += ./config/asp
APPL_COBJS += atk2ext_user_config.o
APPL_COBJS += atk2ext_asp_user_config.o

MAKEFILEDIR = ${ROOTDIR}/workspace/makefiles_common
include ${MAKEFILEDIR}/Makefile.atk2ext
include ${MAKEFILEDIR}/Makefile.lwip
ifneq ($(TOPPERS_KERNEL),asp3)
include ${MAKEFILEDIR}/Makefile.serial
include ${MAKEFILEDIR}/Makefile.timer
endif
ifeq ($(TOPPERS_KERNEL),asp3)
include ${MAKEFILEDIR}/Makefile.asp3
else ifeq ($(TOPPERS_KERNEL),asp)
include ${MAKEFILEDIR}/Makefile.asp
endif