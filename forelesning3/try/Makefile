TARGET ?= ex1

ifneq ($(strip $(windir)),)
#Windows
	EXT = .exe
	CC = cl
	# CFLAGS = -0d -Zi -TP
	CFLAGS = -O2 -TP
	RM = del /Y
else
# Linux
	CC = gcc
	# CFLAGS = -00 -o $(TARGET)
	CFLAGS = -O2 -o $(TARGET)
	LINKMATH = -lm # For ex7 only, but doesnt hurt
	RM = rm -f
endif

$(TARGET)$(EXT): $(TARGET).c Makefile
	$(CC) $(CFLAGS) $< $(LINKMATH)
	
clean:
	$(RM) *.obj *.o *.sln *.pdb *.ilk *.exe $(TARGET)$(EXT)
	
help:
	@echo make TARGET=ex1 to build ex1. Similar for ex2 etc.
