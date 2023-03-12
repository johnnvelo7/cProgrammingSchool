# Makefile template 

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -I$(INCLDIR)

_DEPS = pgdbglog.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

OBJDIR = obj
_OBJS = main.o pgdbglog.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
main: $(OBJDIR)/pgdbglog.o $(OBJDIR)/main.o $(DEPS)
	gcc -o $@ $^ $(CFLAGS)
		
.PHONY: clean
clean:
	@echo "Deleting everything except source files."
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
