# Makefile template 

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -I$(INCLDIR)

_DEPS = source.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

OBJDIR = obj
_OBJS = 1.o 2.o 3.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
all: 1 2 3

1: $(OBJDIR)/1.o
	@echo "Compiling 1.c"
	gcc -o $@ $^ $(CFLAGS)

2: $(OBJDIR)/2.o
	@echo "Compiling 2.c" 
	gcc -o $@ $^ $(CFLAGS)
	
3: $(OBJDIR)/3.o
	@echo "Compiling 3.c" 
	gcc -o $@ $^ $(CFLAGS)
		
		
.PHONY: clean
clean:
	@echo "Deleting everything except source files."
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
