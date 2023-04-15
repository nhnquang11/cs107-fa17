#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Returns a pointer to the first asterisk (*) in the given string.
 *
 * @param s The non-NULL valid string to find an asterisk in
 * @return A pointer to the first asterisk in the string, or NULL if none exist
 */
char *find_first_asterisk(char *s) {
  return strchr(s, '*');
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_find_first_asterisk() {
  printf("Testing find_first_asterisk...\n");

  // Try empty string.
  printf("Testing on input \"\"...");
  expect_string(NULL, find_first_asterisk(""));

  // Try a 1-letter string that isn't an asterisk.
  printf("Testing on input \"a\"...");
  expect_string(NULL, find_first_asterisk("a"));

  // Try a 1-letter string that is an asterisk.
  printf("Testing on input \"*\"...");
  char *single_asterisk = "*";
  expect_string(single_asterisk, find_first_asterisk(single_asterisk));

  // Try a longer string without an asterisk.
  printf("Testing on input \"abcdefgh\"...");
  expect_string(NULL, find_first_asterisk("abcefgh"));

  // Try a longer string with an asterisk at the beginning.
  printf("Testing on input \"*abcdefgh\"...");
  char *beginning_asterisk = "*abcdefgh";
  expect_string(beginning_asterisk, find_first_asterisk(beginning_asterisk));

  // Try a longer string with an asterisk at the end.
  printf("Testing on input \"abcdefgh*\"...");
  char *end_asterisk = "abcdefgh*";
  expect_string(end_asterisk+8, find_first_asterisk(end_asterisk));

  // Try a longer string with a few asterisks in the middle.
  printf("Testing on input \"ab*cde*fgh\"...");
  char *middle_asterisk = "ab*cde*fgh";
  expect_string(middle_asterisk+2, find_first_asterisk(middle_asterisk));

  printf("\n");
}

int main() {
  test_find_first_asterisk();
  return 0;
}
