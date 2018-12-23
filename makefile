#compiler: gcc for C
CC = gcc

#compiler flags:
# -g debugging info 
# -w turns on compiler warnings
CFLAGS = -g -Wall

TARGET = ass1
all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
