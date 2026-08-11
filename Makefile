CC ?= gcc
CFLAGS ?= -Wall -g
LDFLAGS ?= -lm
#CC=vc
#CFLAGS=+aosppc -lm

UNAME_S := $(shell uname -s)

# Nur auf AmigaOS 4.1 erweitern
ifeq ($(UNAME_S), AmigaOS)
    CFLAGS += -mcrt=clib4
endif

BUILDDIR=build

.PHONY: all clean

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
