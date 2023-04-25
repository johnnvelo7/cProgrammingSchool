#
# Generic makefile for compiling and linking more than one source file
#
TARGET = testlist
OBJS = $(TARGET).o # List object files for the excutable here

LIB = list
LIBOBJS = $(LIB).o # List object files for the library here

DEPS = list.h makefile
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

