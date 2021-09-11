
# get the app name with the argument of make
APPNAME := ${app}
BUILDSPACE := build

BOARDNAME := NODE_F767ZI
BOARDPATH := /media/${USER}/${BOARDNAME}

ifdef app
# nothing to do
else
usage:
	@echo Please specify the application
	@echo Usage Guide：make app="<application directory>"
endif

all:
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
	rm -f asp.*
