
# get the app name with the argument of make
APPNAME := ${app}
BUILDSPACE := build

BOARDNAME := NODE_F767ZI
ifeq ($(shell uname), Linux)
	BOARDPATH := /media/${USER}/${BOARDNAME}
else ifeq ($(shell uname), Darwin)
	BOARDPATH := /Volumes/${BOARDNAME}
endif

MSGFILE := ${msg}
MROS2DIR := ../mros2
HEADERGEN_FILE := $(MROS2DIR)/mros2_header_generator/header_generator.py
TEMPLATESGEN_FILE := $(MROS2DIR)/mros2_header_generator/templates_generator.py

ifdef app
# nothing to do
else
usage:
	@echo "Please specify the application"
	@echo "Usage:"
	@echo "  build app: make app=<app_dir_name>"
	@echo "  generate header file: make msg=<msg_file_path>"
endif

all: clean
	@python3 $(TEMPLATESGEN_FILE) $(APPNAME)
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
	@if [ -f custom_msgs/$(MSGFILE) ]; then \
		python3 -B $(HEADERGEN_FILE) $(MSGFILE); \
		echo "header file for custom message was generated from ${MSGFILE}"; \
	else \
		echo "error in msg file: ${MSGFILE} does not exist"; \
	fi
