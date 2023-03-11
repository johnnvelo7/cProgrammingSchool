TARGET ?= ex1

ifneq ($(strip $(windir)),)
# Windows
   TARGETS = ex0.exe ex0a.exe ex0b.exe ex1.exe ex2.exe ex3.exe
   EXT = .exe
   CC = cl
   CFLAGS = -Od -Zi -TP
   # CFLAGS = -O2 -TP
   RM = del /Y *.obj *.ilk *.pdb *.sln
else
# Linux
   TARGETS = ex0 ex0a ex0b ex1 ex2 ex3 botgame botgame2
   CC = gcc
   # CFLAGS = -O0 -std=c11 -o $(TARGET)
   CFLAGS = -O2 -std=c11 -o $(TARGET)
   LINKEXTRA = -lncurses
   RM = rm -f *.o
endif

$(TARGET)$(EXT): $(TARGET).c makefile
	$(CC) $(CFLAGS) $< $(LINKEXTRA)

clean:
	$(RM) $(TARGETS)
