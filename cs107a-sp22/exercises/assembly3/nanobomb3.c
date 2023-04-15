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
  char *in = risky_read_string();
  if (in[0] + 10 != in[2]) {
    nano_explode();
  } else if (in[2] + 8 != in[4]) {
    nano_explode();
  }
  free(in);
  nano_defuse();
}

int main() {
  nano_intro();
  try_defuse();
}
