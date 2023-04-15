# A simple makefile for building a program composed of C source files.
# Refer to CS107 guide to Make for background info on makefiles

PROGRAMS = nanobomb1 nanobomb2

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g3 -O1 -std=gnu99 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -Winit-self -fno-diagnostics-show-option -fno-optimize-strlen
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

nanobomb1 nanobomb2: nanobomb_util.c

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
