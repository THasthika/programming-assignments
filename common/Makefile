TARGET = libcommon.a
LIBS = 
CC = gcc
AR = ar
CFLAGS = -g -Wall
LDFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(AR) -rcs $(TARGET) $(OBJECTS)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
