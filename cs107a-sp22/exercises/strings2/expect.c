#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Checks a boolean value against an expected value and prints a diagnostic.
 *
 * @param expected The expected boolean value
 * @param actual The actual boolean value
 */
void expect_bool(bool expected, bool actual) {
  if (expected == actual) {
    printf("\x1b[32mPASSED\x1b[0m â­\n");
  } else {
    printf("\x1b[31mFAILED\x1b[0m ðŸ˜­\n");
    printf("Expected %s, got %s\n",
        expected ? "true" : "false",
        actual ? "true" : "false");
  }
}

/**
 * Checks a nullable string against an expected nullable string and prints a
 * diagnostic.
 *
 * @param expected The expected possibly-null string
 * @param actual The actual possibly-null string
 */
void expect_string(char *expected, char *actual) {
  if ((expected == actual) ||
      (expected != NULL && actual != NULL && strcmp(expected, actual) == 0)) {
    printf("\x1b[32mPASSED\x1b[0m â­\n");
  } else {
    printf("\x1b[31mFAILED\x1b[0m ðŸ˜­\n");
    printf("Expected \"%s\", got \"%s\"\n",
        expected == NULL ? "NULL" : expected,
        actual == NULL ? "NULL" : actual);
  }
}
