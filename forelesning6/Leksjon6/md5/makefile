	# Makefile template 

INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -I$(INCLDIR)

_DEPS = md5.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

OBJDIR = obj
_OBJS = md5.o md5_example.o md5_test.o print_md5.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

md5_example: $(OBJDIR)/md5.o $(OBJDIR)/print_md5.o
	@echo "Compiling md5_example.c"
	gcc -o $@ $^ $(CFLAGS)

		
.PHONY: clean
clean:
	@echo "Deleting everything except source files."
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~

