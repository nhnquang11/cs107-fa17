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

#include "nanobomb_util.h"

void try_defuse() {
  int i = risky_read_int();
  int j = 21;
  int k = 0;
  while (j < 100) {
    j += i;
    k++;
  }
  if (k != 7) {
    nano_explode();
  }
  nano_defuse();
}

int main() {
  nano_intro();
  try_defuse();
}
