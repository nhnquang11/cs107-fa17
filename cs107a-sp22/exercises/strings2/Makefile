# A makefile for building a program composed of C source files.
# Refer to CS107 guide to Make for background info on makefiles.

PROGRAMS = peel_string peel_string_sol is_suffix is_suffix_sol find_first_asterisk find_first_asterisk_sol find_first_asterisk_or_ampersand find_first_asterisk_or_ampersand_sol string_reverse string_reverse_sol my_strcat my_strcat_sol string_pointers whatdoitdo

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g3 -O0 -std=gnu99 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -Winit-self -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

peel_string peel_string_sol is_suffix is_suffix_sol find_first_asterisk find_first_asterisk_sol find_first_asterisk_or_ampersand find_first_asterisk_or_ampersand_sol string_reverse string_reverse_sol my_strcat my_strcat_sol: expect.c

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
