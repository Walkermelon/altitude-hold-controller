CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iinclude/SDL3
LDFLAGS = -Llib -lSDL3
SRC = src/main.c sim/physics-engine.c sim/ball.c
OBJ = src/main.o sim/physics-engine.o sim/ball.o
TARGET = controller

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	del /f src\*.o sim\*.o $(TARGET).exe