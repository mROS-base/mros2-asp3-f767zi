
# get the app name with the argument of make
APPNAME := ${app}
BUILDSPACE := build

ifdef app
# nothing to do
else
usage:
	@echo Please specify the application
	@echo Usage Guide：make app="<application folder>"
endif

all:
	@cd $(BUILDSPACE) &&  make -j 24 -f Makefile.common app=${APPNAME}
	@cp $(BUILDSPACE)/asp.bin . && cp $(BUILDSPACE)/asp.elf .

clean:
	@cd $(BUILDSPACE) && make -f Makefile.common clean
	rm -f asp.*
