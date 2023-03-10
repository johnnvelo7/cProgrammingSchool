# Makefile template 

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -I$(INCLDIR)

_DEPS = source.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

OBJDIR = obj
_OBJS = ex1.o ex3-2.o ex3.o ex4.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
all: ex1 ex3 ex3-2 ex4

ex1: $(OBJDIR)/ex1.o
	@echo "Compiling ex1.c"
	gcc -o $@ $^ $(CFLAGS)

ex3: $(OBJDIR)/ex3.o
	@echo "Compiling ex3.c" 
	gcc -o $@ $^ $(CFLAGS)
	
ex3-2: $(OBJDIR)/ex3-2.o
	@echo "Compiling ex3-2.c" 
	gcc -o $@ $^ $(CFLAGS)
		
ex4: $(OBJDIR)/ex4.o
	@echo "Compiling ex4.c"
	gcc -o $@ $^ $(CFLAGS)
		
.PHONY: clean
clean:
	@echo "Deleting everything except source files."
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
