# information for directory tree
ROOTDIR := ../../../asp-stm32f767
APPDIR := .
APPLDIR	:= $(APPDIR)/

# name of main application
APPLNAME = sample1
# additional files for main application
APPL_COBJS := sample_ping.o

# information for user configuration
APPLDIR	+= $(APPDIR)/config
APPLDIR	+= $(APPDIR)/config/asp
APPL_COBJS += atk2ext_user_config.o
APPL_COBJS	+= atk2ext_asp_user_config.o

SRCLANG = c++
APPL_CXXLIBS += -specs=nano.specs

MAKEFILEDIR = ${ROOTDIR}/workspace/makefiles_common
include ${MAKEFILEDIR}/Makefile.atk2ext
include ${MAKEFILEDIR}/Makefile.lwip
include ${MAKEFILEDIR}/Makefile.serial
include ${MAKEFILEDIR}/Makefile.timer
include ${MAKEFILEDIR}/Makefile.rtps
include ${MAKEFILEDIR}/Makefile.asp