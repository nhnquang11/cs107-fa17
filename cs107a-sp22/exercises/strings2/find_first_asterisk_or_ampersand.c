#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Returns a pointer to the first asterisk (*) or ampersand (&) in the given
 * string.
 *
 * @param s The non-NULL valid string to find an asterisk or ampersand in
 * @return A pointer to the first asterisk or ampersand in the string, or NULL
 *     if none exist
 */
char *find_first_asterisk_or_ampersand(char *s) {
    size_t offset = strcspn(s, "&*");
    if (s[offset] == '\0') {
        return NULL;
    }
    return s + offset;
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_find_first_asterisk_or_ampersand() {
  printf("Testing find_first_asterisk_or_ampersand...\n");

  // Try empty string.
  printf("Testing on input \"\"...");
  expect_string(NULL, find_first_asterisk_or_ampersand(""));

  // Try a 1-letter string that isn't an asterisk or ampersand.
  printf("Testing on input \"a\"...");
  expect_string(NULL, find_first_asterisk_or_ampersand("a"));

  // Try a 1-letter string that is an asterisk.
  printf("Testing on input \"*\"...");
  char *single_asterisk = "*";
  expect_string(single_asterisk, find_first_asterisk_or_ampersand(single_asterisk));

  // Try a 1-letter string that is an ampersand.
  printf("Testing on input \"*\"...");
  char *single_ampersand = "&";
  expect_string(single_ampersand, find_first_asterisk_or_ampersand(single_ampersand));

  // Try a longer string without an asterisk or ampersand.
  printf("Testing on input \"abcdefgh\"...");
  expect_string(NULL, find_first_asterisk_or_ampersand("abcefgh"));

  // Try a longer string with an asterisk at the beginning.
  printf("Testing on input \"*abcdefgh\"...");
  char *beginning_asterisk = "*abcdefgh";
  expect_string(beginning_asterisk, find_first_asterisk_or_ampersand(beginning_asterisk));

  // Try a longer string with an ampersand at the beginning.
  printf("Testing on input \"&abcdefgh\"...");
  char *beginning_ampersand = "&abcdefgh";
  expect_string(beginning_ampersand, find_first_asterisk_or_ampersand(beginning_ampersand));

  // Try a longer string with an asterisk at the end.
  printf("Testing on input \"abcdefgh*\"...");
  char *end_asterisk = "abcdefgh*";
  expect_string(end_asterisk+8, find_first_asterisk_or_ampersand(end_asterisk));

  // Try a longer string with an ampersand at the end.
  printf("Testing on input \"abcdefgh&\"...");
  char *end_ampersand = "abcdefgh&";
  expect_string(end_ampersand+8, find_first_asterisk_or_ampersand(end_ampersand));

  // Try a longer string with a few asterisks/ampersands in the middle.
  printf("Testing on input \"ab&*cde*fgh\"...");
  char *middle_symbols = "ab&*cde*fgh";
  expect_string(middle_symbols+2, find_first_asterisk_or_ampersand(middle_symbols));

  printf("\n");
}

int main() {
  test_find_first_asterisk_or_ampersand();
  return 0;
}
