# A makefile for building a program composed of C source files.
# Refer to CS107 guide to Make for background info on makefiles.

PROGRAMS = buggy1 buggy2 pointer_arithmetic_demo struct_pointer_array scramble_struct_array scramble
PROGRAMS_READLINE = dedupe dedupe_soln

all:: $(PROGRAMS) $(PROGRAMS_READLINE)

CC = gcc
CFLAGS = -g3 -O0 -std=gnu99 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -Winit-self -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(PROGRAMS_READLINE): %:%.c read_line.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean::
	rm -f $(PROGRAMS) $(PROGRAMS_READLINE)

.PHONY: clean all
