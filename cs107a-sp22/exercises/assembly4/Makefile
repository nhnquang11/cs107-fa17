# A simple makefile for building a program composed of C source files.
# Refer to CS107 guide to Make for background info on makefiles

PROGRAMS = lottery nanobomb1 nanobomb2

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -Og -std=gnu99 -Wall $$warnflags -fno-toplevel-reorder -fno-builtin -fno-inline -fno-stack-protector -D_GNU_SOURCE -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -Winit-self -fno-diagnostics-show-option

LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

nanobomb1 nanobomb2: nanobomb_util.c

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
