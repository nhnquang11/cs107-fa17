#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Reverses the given string and stores the result in @code rev.
 *
 * @param str The string to reverse. It is guaranteed to be valid.
 * @param rev Pointer to memory into which the reversed result should be put. It
 *     is guaranteed to be big enough for the reversed string, but not
 *     necessarily larger. It does not necessarily point to anything meaningful.
 */
void string_reverse(char *str, char *rev) {
  int length = strlen(str);
  rev[length] = '\0';
  for (int i = 0; i < length; i++) {
    rev[length - i - 1] = str[i];
  }
}

/**
 * Returns whether the given string is a palindrome (i.e. the same forwards or
 * backwards, like racecar).
 *
 * FOR THE PURPOSES OF THIS EXERCISE, YOU MUST USE STRING_REVERSE IN YOUR
 * SOLUTION, EVEN THOUGH THAT'S NOT THE MOST EFFICIENT WAY.
 *
 * @param str The string to examine to see if it's a palindrome
 * @return Whether the string is a palindrome
 */
bool is_string_palindrome(char *str) {
  int length = strlen(str);
  char rev[length+1];
  string_reverse(str, rev);
  return strcmp(str, rev) == 0;
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_string_reverse() {
  printf("Testing string_reverse...\n");

  // Result array is arbitrarily large for testing purposes. Hopefully students
  // don't depend on it having room!
  char result[4096];
  result[0] = '\0';

  // Try empty string.
  printf("Testing on input \"\"...");
  string_reverse("", result);
  expect_string("", result);
  result[0] = '\0';

  // Try one-letter string.
  printf("Testing on input \"a\"...");
  string_reverse("a", result);
  expect_string("a", result);
  result[0] = '\0';

  // Try two-letter string.
  printf("Testing on input \"ab\"...");
  string_reverse("ab", result);
  expect_string("ba", result);
  result[0] = '\0';

  // Try a sentence.
  printf("Testing on input \"She sells seashells by the seashore.\"...");
  string_reverse("She sells seashells by the seashore.", result);
  expect_string(".erohsaes eht yb sllehsaes slles ehS", result);
  result[0] = '\0';

  // Try palindrome.
  printf("Testing on input \"racecar\"...");
  string_reverse("racecar", result);
  expect_string("racecar", result);
  result[0] = '\0';

  printf("\n");
}

void test_is_string_palindrome() {
  printf("Testing is_string_palindrome...\n");

  // Try empty string.
  printf("Testing on input \"\"...");
  expect_bool(true, is_string_palindrome(""));

  // Try one-letter string.
  printf("Testing on input \"a\"...");
  expect_bool(true, is_string_palindrome("a"));

  // Try two-letter string.
  printf("Testing on input \"ab\"...");
  expect_bool(false, is_string_palindrome("ab"));

  // Try two-letter string palindrome.
  printf("Testing on input \"aa\"...");
  expect_bool(true, is_string_palindrome("aa"));

  // Try longer non-palindrome.
  printf("Testing on input \"programming\"...");
  expect_bool(false, is_string_palindrome("programming"));

  // Try longer palindrome.
  printf("Testing on input \"racecar\"...");
  expect_bool(true, is_string_palindrome("racecar"));

  printf("\n");
}

int main() {
  test_string_reverse();
  test_is_string_palindrome();
  return 0;
}
