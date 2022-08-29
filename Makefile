CC = gcc

CFLAGS = -g -Wall

PRODFLAGS = -Ofast

TARGET = solver

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

prod: $(TARGET).c
	$(CC) $(PRODFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) -r $(TARGET) $(TARGET).dSYM
