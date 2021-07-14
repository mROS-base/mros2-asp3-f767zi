# information for directory tree
ROOTDIR := ../..
APPDIR := .

TOPPERS_KERNEL = asp3
CDEFS := -DMROS2_USE_ASP3

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

# link option for C++ code
SRCLANG = c++
APPL_CXXLIBS += -specs=nano.specs

#cmsis_asp3 makefiles include
CMSIS_MAKEFILEDIR = ${ROOTDIR}/cmsis-asp3
include ${CMSIS_MAKEFILEDIR}/Makefile.mros2

#mros2 makefiles include
MROS2_MAKEFILEDIR = ${ROOTDIR}/mros2/makefiles
include ${MROS2_MAKEFILEDIR}/Makefile.lwip
include ${MROS2_MAKEFILEDIR}/Makefile.rtps
include ${MROS2_MAKEFILEDIR}/Makefile.mros2

#asp3-f767zi makefiles include
ASP3F767_MAKEFILEDIR = ${ROOTDIR}/asp3-f767zi
include ${ASP3F767_MAKEFILEDIR}/Makefile.mros2
