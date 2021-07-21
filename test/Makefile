
# get the app name with the argument of make
APPNAME := ${test}
BUILDSPACE := build

ifdef test
# nothing to do
else
usage:
	@echo Please specify the application
	@echo Usage Guide：make test="<test folder>"
endif

all:
	@cd $(BUILDSPACE) &&  make -j 4 -f Makefile.common test=${test}
	@cp $(BUILDSPACE)/asp.bin . && cp $(BUILDSPACE)/asp.elf .

clean:
	@cd $(BUILDSPACE) && make -f Makefile.common clean
	rm -f asp.*
