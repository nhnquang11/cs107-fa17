#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Removes the first and last characters of the given string and writes it to
 * the provided buffer.
 *
 * @param s The non-NULL valid string of length at least 2 to "peel"
 * @param buf A non-NULL buffer to write the peeled string into. It is
 *     guaranteed to be big enough for the result. It does NOT necessarily
 *     contain a valid string.
 */
void peel_string(char *s, char *buf) {
  int length = strlen(s);
  strncpy(buf, s+1, length - 2);
  buf[length - 2] = '\0';
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_peel_string() {
  printf("Testing peel_string...\n");

  // Result array is arbitrarily large for testing purposes. Hopefully students
  // don't depend on it having room!
  char result[4096];
  // Try to ensure students don't depend on the buffer containing an empty
  // string.
  memset(result, 101, sizeof(result));

  // Try min-sized string.
  printf("Testing on input \"ab\"...");
  peel_string("ab", result);
  expect_string("", result);
  memset(result, 101, sizeof(result));

  // Try a string with an odd number of letters.
  printf("Testing on input \"abc\"...");
  peel_string("abc", result);
  expect_string("b", result);
  memset(result, 101, sizeof(result));

  // Try a string with a larger even number of letters.
  printf("Testing on input \"abcdefghijkl\"...");
  peel_string("abcdefghijkl", result);
  expect_string("bcdefghijk", result);
  memset(result, 101, sizeof(result));

  printf("\n");
}

int main() {
  test_peel_string();
  return 0;
}
