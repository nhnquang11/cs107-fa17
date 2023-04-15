#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Joins all strings in the given array of strings that do not contain an
 * asterisk and puts the result in the output array.
 *
 * Ex)
 * This is pseudo-syntax, but after this runs:
 * filter_pollution(["a*bbb", "hello", "wor*d", "world", "***"], "")
 * the passed in array contains "helloworld"
 *
 * @param strings An array of valid but possibly-polluted strings to join. A
 *     string is polluted if it contains an asterisk (*).
 * @param n The [guaranteed valid] length of @code strings
 * @param filtered_result Pointer to memory into which the joined result should
 *     be put. It is guaranteed to be big enough for the result and to initially
 *     contain an empty string.
 */
void filter_pollution(char *strings[], int n, char *filtered_result) {
    for(int i = 0; i < n; ++i) {
        if (strchr(strings[i], '*') == NULL) {
            strcat(filtered_result, strings[i]);
        }
    }
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void expect_string(char *expected, char *actual) {
  if (strcmp(expected, actual) == 0) {
    printf("\x1b[32mPASSED\x1b[0m â­\n");
  } else {
    printf("\x1b[31mFAILED\x1b[0m ðŸ˜­\n");
    printf("Expected \"%s\", got \"%s\"\n", expected, actual);
  }
}

void test_filter_pollution() {
  printf("Testing filter_pollution...\n");

  // Result array is arbitrarily large for testing purposes. Hopefully students
  // don't depend on it having room!
  char result[4096];
  result[0] = '\0';

  // Try empty array.
  printf("Testing on inputs ({}, 0)...");
  char *empty[] = {};
  filter_pollution(empty, 0, result);
  expect_string("", result);
  result[0] = '\0';

  // Try no words with asterisks.
  printf("Testing on inputs ({\"hello\", \"world\"}, 2)...");
  char *no_asterisks[] = {"hello", "world"};
  filter_pollution(no_asterisks, 2, result);
  expect_string("helloworld", result);
  result[0] = '\0';

  // Try all words with asterisk.
  printf("Testing on inputs ({\"h*llo\", \"worl*\"}, 2)...");
  char *all_asterisks[] = {"h*llo", "worl*"};
  filter_pollution(all_asterisks, 2, result);
  expect_string("", result);
  result[0] = '\0';

  // Try interspersing words with asterisks, some of which are empty.
  printf("Testing on inputs ({\"*what\", \"a\", \"\", \"t*est\", \"case\", "
         "\"this\", \"is*\"}, 7)...");
  char *interspersed[] = {"*what", "a", "", "t*est", "case", "this", "is*"};
  filter_pollution(interspersed, 7, result);
  expect_string("acasethis", result);
  result[0] = '\0';

  printf("\n");
}

int main() {
  test_filter_pollution();
  return 0;
}
