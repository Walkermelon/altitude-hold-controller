CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c
OBJ = src/main.o
TARGET = controller

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	del /f src\*.o $(TARGET).exe