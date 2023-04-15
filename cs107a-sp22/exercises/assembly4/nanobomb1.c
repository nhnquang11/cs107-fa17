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

#include <string.h>

#include "nanobomb_util.h"

static const char *array[] = {
  "ricker",
  "lakeside",
  "flomo",
  "stern",
  "arrillaga",
  "wilbur",
  "branner",
  "casper",
  "evgr",
};

void try_defuse() {
  int chr = risky_read_int();
  int count = 0;
  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    if (strchr(array[i], chr) != NULL) {
      count += 1;
    }
  }
  if (count != 6) {
    nano_explode();
  }
  nano_defuse();
}

int main() {
  nano_intro();
  try_defuse();
}
