TARGETS = filehandling variables functions arrays arraysAsFunc pointers union struct typedef enum filehandling2
CC = gcc
CFLAGS = -O0 -g -std=c11 -o $(TARGET)
# CFLAGS = -O2 -std=c11 -o $(TARGET)
# LINKEXTRA = -lncurses
RM = rm -f *.o

$(TARGET): $(TARGET).c makefile
	$(CC) $(CFLAGS) $< $(LINKEXTRA)

clean:
	$(RM) $(TARGETS)
