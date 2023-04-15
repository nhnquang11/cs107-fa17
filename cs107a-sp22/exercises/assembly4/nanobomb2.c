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

#include <stdlib.h>

#include "nanobomb_util.h"

int reduce(unsigned int n) {
  int i = 0;
  while (n > 1) {
    n /= 2;
    i++;
  }
  return i;
}

void try_defuse() {
  int n = risky_read_int();
  int i = reduce(n);
  if (i != 3) {
    nano_explode();
  }
  nano_defuse();
}

int main() {
  nano_intro();
  try_defuse();
}
