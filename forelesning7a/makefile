#MakeFile Template

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)
LIBS += -L/home/bruce/Documents/lib -Ipgdbglog

OBJDIR = obj

_DEPS = source.h pgdbglog.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

_OBJS = ex1.o pgdbglog.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
		
ex1: $(OBJDIR)/pgdbglog.o $(OBJDIR)/ex1.o $(DEPS)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
		
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
