CC = gcc
CFLAGS ?= -Wall -g
LDFLAGS ?= -lm
#CC=vc
#CFLAGS=+aosppc -lm

.PHONY: all clean

all: linesort

linesort: main.o alloc.o getline.o qsort.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	- rm -Rf linesort *.o
