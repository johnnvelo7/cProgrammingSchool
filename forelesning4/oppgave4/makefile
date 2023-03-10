# Makefile template 

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -I$(INCLDIR)

OBJDIR = obj

SRCS = ex1.c ex2.c ex3.c ex4.c 
_OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
	
all: ex1 ex2 ex3 ex4

ex1: $(OBJDIR)/ex1.o
	$(CC) -o $@ $^ $(CFLAGS)

ex2: $(OBJDIR)/ex2.o 
	$(CC) -o $@ $^ $(CFLAGS)
	
ex3: $(OBJDIR)/ex3.o 
	$(CC) -o $@ $^ $(CFLAGS)
		
ex4: $(OBJDIR)/ex4.o
	$(CC) -o $@ $^ $(CFLAGS)
		
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
