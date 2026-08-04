CC = gcc
CFLAGS ?= -Wall -gstabs
LDFLAGS ?= -lm
#CC=vc
#CFLAGS=+aosppc -lm

.PHONY: all clean

all: calc

calc: main.o stack.o getch.o getop.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c calc.h
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	- rm -Rf calc *.o
