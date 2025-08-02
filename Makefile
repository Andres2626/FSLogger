OUTDIR := build
LOGDIR := log
FSDIR  := $(LOGDIR)/FS
TESTDIR := tests
CFLAGS := -I$(LOGDIR)/

OBJS := $(OUTDIR)/$(TESTDIR)/main.o


LOGOBJS :=   $(OUTDIR)/$(FSDIR)/Logger.o \
		     $(OUTDIR)/$(FSDIR)/LogMessage.o \
		     $(OUTDIR)/$(FSDIR)/Console/ConsoleOutput.o

LOGLIB  :=   $(OUTDIR)/libfslog.a
TESTS   :=   $(OUTDIR)/example1

.PHONY: all clean

all: $(LOGLIB) $(TESTS)

$(LOGLIB): $(LOGOBJS)
	ar rcs $@ $^

$(TESTS): $(OBJS)
	g++ -o $@ $< -lfslog -L$(OUTDIR)/

clean:
	rm -rf $(LOGLIB)
	rm -rf $(TESTS)
	rm -rf $(LOGOBJS)
	rm -rf $(OBJS)

$(OUTDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	g++ -c -o $@ $< $(CFLAGS)