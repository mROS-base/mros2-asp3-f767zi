# information for directory tree
ROOTDIR := ../../../../../asp-stm32f767
APPDIR := .
APPLDIR	:= $(APPDIR)/

# name of main application
APPLNAME = sample1
# additional files for main application
APPL_COBJS := sample.o
APPLDIR	+= $(APPDIR)/../tcp_comm
APPL_COBJS += sample_lwip_comm.o sample_lwip_scene1.o

# information for user configuration
APPLDIR	+= $(APPDIR)/config
APPLDIR	+= $(APPDIR)/config/asp
APPL_COBJS += atk2ext_user_config.o
APPL_COBJS	+= atk2ext_asp_user_config.o

MAKEFILEDIR = ${ROOTDIR}/workspace/makefiles_common
include ${MAKEFILEDIR}/Makefile.atk2ext
include ${MAKEFILEDIR}/Makefile.lwip
include ${MAKEFILEDIR}/Makefile.serial
include ${MAKEFILEDIR}/Makefile.timer
include ${MAKEFILEDIR}/Makefile.asp