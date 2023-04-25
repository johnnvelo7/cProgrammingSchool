#MakeFile Template

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)
LIBS += -L/home/bruce/Documents/lib -Ipgdbglog

OBJDIR = obj

_DEPS = main.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

_OBJS = main.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
		
main: $(OBJDIR)/main.o $(DEPS) 
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
		
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~
