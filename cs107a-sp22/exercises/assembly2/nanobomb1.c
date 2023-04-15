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
#include <stdlib.h>

#include "nanobomb_util.h"

void try_defuse() {
  char *s = risky_read_string();
  if ((s[1] & 0x7) != 1) {
    nano_explode();
  }
  if ((s[1] & -8) != 40) {
    nano_explode();
  }
  free(s);
  nano_defuse();
}

int main() {
  nano_intro();
  try_defuse();
}
