#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Returns whether @code suffix is a suffix string of @code s.
 *
 * @param s A non-NULL valid string to check for a suffix
 * @param suffix A non-NULL valid string suffix to check for
 * @return Whether it's a suffix
 */
bool is_suffix(char *s, char *suffix) {
    int extra_chars = strlen(s) - strlen(suffix);
    if (extra_chars < 0) {
        return false;
    }
    return strcmp(s + extra_chars, suffix) == 0;
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_is_suffix() {
  printf("Testing is_suffix...\n");

  // Some edge cases.
  printf("Testing on inputs (\"\", \"\")...");
  expect_bool(true, is_suffix("", ""));

  printf("Testing on inputs (\"a\", \"\")...");
  expect_bool(true, is_suffix("a", ""));

  printf("Testing on inputs (\"\", \"a\")...");
  expect_bool(false, is_suffix("", "a"));

  // Equal lengths.
  printf("Testing on inputs (\"aa\", \"aa\")...");
  expect_bool(true, is_suffix("aa", "aa"));

  // strlen(s) > strlen(suffix).
  printf("Testing on inputs (\"aaa\", \"aa\")...");
  expect_bool(true, is_suffix("aaa", "aa"));

  printf("Testing on inputs (\"aab\", \"aa\")...");
  expect_bool(false, is_suffix("aab", "aa"));

  // strlen(s) < strlen(suffix).
  printf("Testing on inputs (\"aa\", \"aaa\")...");
  expect_bool(false, is_suffix("aa", "aaa"));

  printf("Testing on inputs (\"aa\", \"aab\")...");
  expect_bool(false, is_suffix("aa", "aab"));

  printf("\n");
}

int main() {
  test_is_suffix();
  return 0;
}
