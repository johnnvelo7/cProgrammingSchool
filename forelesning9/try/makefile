#
# Generic makefile for compiling and linking more than one source file
#
TARGET = main
OBJS = $(TARGET).o # List object files for the excutable here

LIB = doublylinkedlist
LIBOBJS = $(LIB).o # List object files for the library here

DEPS = doublylinkedlist.h makefile
# CFLAGS = -O2
CFLAGS = -O0 -g

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS) $(LIB).a
	gcc -o $@ $^ $(CFLAGS)

$(LIB).a: $(LIBOBJS)
	ar rcs $@ $^

.phony: clean
clean:
	rm -f *.a *.o $(TARGET)

