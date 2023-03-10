TARGET ?= ex1

ifneq ($(strip $(windir)),)
# Windows
   EXT = .exe
   CC = cl
   # CFLAGS = -Od -Zi -TP
   CFLAGS = -O2 -TP
   RM = del /Y
else
# Linux
   CC = gcc
   # CFLAGS = -O0 -o $(TARGET)
   CFLAGS = -O2 -o $(TARGET)
   LINKMATH = -lm # For ex7 only, but doesn't hurt
   RM = rm -f
endif

$(TARGET)$(EXT): $(TARGET).c makefile
	$(CC) $(CFLAGS) $< $(LINKMATH)

clean:
	$(RM) *.obj *.o *.sln *.pdb *.ilk *.exe $(TARGET)$(EXT)
