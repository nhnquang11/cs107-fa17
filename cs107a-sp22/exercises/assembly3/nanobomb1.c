/*
 * WAIT
 *
 * THIS IS THE SOURCE CODE!
 *
 * HERE BE SPOILERS
 *
 * ARE YOU SURE YOU WANT TO LOOK AT IT?
 *
 * IF YOU'RE REALLY SURE, KEEP SCROLLING...
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>

#include "nanobomb_util.h"

void try_defuse() {
  char *s = risky_read_string();
  if (*s != 'c') {
    nano_explode();
    // Unreachable, but here to convince the compiler to delete some dead code.
    return;
  }
  int counter = 0;
  while (*s != '\0') {
    if (*s % 2 == 0) {
      nano_explode();
    }
    s++;
    counter++;
  }
  if (counter == 4) {
    nano_defuse();
  } else {
    nano_explode();
  }
}

int main() {
  nano_intro();
  try_defuse();
}
