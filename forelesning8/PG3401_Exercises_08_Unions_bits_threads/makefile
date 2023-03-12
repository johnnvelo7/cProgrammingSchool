TARGET ?= variadic

CC = gcc
# CFLAGS = -O0 -o $(TARGET)
CFLAGS = -O2 -o $(TARGET)
LINKEXTRA = -lpthread
RM = rm -f

$(TARGET): $(TARGET).c makefile
	$(CC) $(CFLAGS) $< $(LINKEXTRA)

clean:
	$(RM) *.o $(TARGET)

help:
	@echo make TARGET=ex1 to build ex1. Similar for ex2 etc.
