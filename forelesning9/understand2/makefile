TARGET ?= singlelinkedlists singlelinkedlists2 singlelinkedlists3 doublylinkedlists doublylinkedlists2 doublylinkedlists3 doublylinkedlists4
TARGETS = singlelinkedlists singlelinkedlists2 singlelinkedlists3 doublylinkedlists doublylinkedlists2 doublylinkedlists3 doublylinkedlists4 
CC = gcc
CFLAGS = -O0 -g -std=c11 -o $(TARGET)
# CFLAGS = -O2 -std=c11 -o $(TARGET)
# LINKEXTRA = -lncurses
RM = rm -f *.o

$(TARGET): $(TARGET).c makefile
	$(CC) $(CFLAGS) $< $(LINKEXTRA)

clean:
	$(RM) $(TARGETS)
