
# get the app name with the argument of make
APPNAME := ${app}
BUILDSPACE := build

BOARDNAME := NODE_F767ZI
BOARDPATH := /media/${USER}/${BOARDNAME}
# BOARDPATH for MAC OS -> BOARDPATH := /Volumes/${BOARDNAME}

MSGDIR := custom_msgs/${msg}
MROS2DIR := ../mros2
HEADERGEN_FILE := $(MROS2DIR)/mros2_header_generator/header_generator.py
TEMPLATESGEN_FILE := $(MROS2DIR)/mros2_header_generator/templates_generator.py

ifdef app
# nothing to do
else
usage:
	@echo Please specify the application
	@echo Usage Guide：make app="<application directory>"
endif

all: clean
    
	@python $(TEMPLATESGEN_FILE) $(MROS2DIR) $(APPNAME);
	@cd $(BUILDSPACE) &&  make -j4 -f Makefile.common app=${APPNAME}
	@cp $(BUILDSPACE)/asp.bin . && cp $(BUILDSPACE)/asp.elf .
	@echo "Build complete successfully"
	@if [ -d "$(BOARDPATH)" ]; then \
		echo "Copying binary to the board..."; \
		cp asp.bin $(BOARDPATH); \
		echo "completed"; \
	fi

clean:
	@cd $(BUILDSPACE) && make -f Makefile.common clean
	rm -f asp.* && rm -f .asp*

gen-msg:
	@if [ -f $(MSGDIR)/msg_settings.json ]; then \
		python $(HEADERGEN_FILE) $(MROS2DIR) $(MSGDIR); \
		echo "msg file for ${msg} generated in ${MSGDIR}"; \
	fi
