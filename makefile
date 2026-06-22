CC ?= gcc
CFLAGS ?= -Wall -g -mcrt=clib4
LDFLAGS ?= -lm
#CC=vc
#CFLAGS=+aosppc -lm

BUILDDIR=build

SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c,$(BUILDDIR)/%,$(SRCS))

all: $(TARGETS)

$(TARGETS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	- rm -Rf $(BUILDDIR)
