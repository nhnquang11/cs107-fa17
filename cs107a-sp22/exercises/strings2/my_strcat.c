#include <stdio.h>
#include <string.h>

#include "expect.h"

/**
 * Concatenates @code suffix to the end of @code buf.
 *
 * It is assumed that @code buf has enough space to hold the combined string.
 *
 * This should have the same behavior as @code strcat, but unlike it, this
 * returns @code void.
 *
 * @param buf The string to concatenate onto
 * @param suffix The string to concatenate
 */
void my_strcat(char *buf, char *suffix) {
    char *ptr = buf + strlen(buf);
    while ((*ptr++ = *suffix++) != '\0');
}

/*
 * TESTING HARNESS - NO NEED TO MODIFY CODE BELOW THIS LINE
 * Feel free to read if you're curious.
 */

void test_my_strcat() {
  printf("Testing my_strcat...\n");

  char buf[4096];

  // Try concatenating onto empty string.
  printf("Testing on input (\"\", \"hello\")...");
  buf[0] = '\0';
  my_strcat(buf, "hello");
  expect_string("hello", buf);

  printf("Testing on input (\"\", \"\")...");
  buf[0] = '\0';
  my_strcat(buf, "");
  expect_string("", buf);

  // Try concatenating an empty string.
  printf("Testing on input (\"cs107a\", \"\")...");
  strcpy(buf, "cs107a");
  my_strcat(buf, "");
  expect_string("cs107a", buf);

  // Try concatenating a string shorter than the initial string.
  printf("Testing on input (\"four\", \"th\")...");
  strcpy(buf, "four");
  my_strcat(buf, "th");
  expect_string("fourth", buf);

  // Try concatenating a string with the same length as the initial string.
  printf("Testing on input (\"four\", \"four\")...");
  strcpy(buf, "four");
  my_strcat(buf, "four");
  expect_string("fourfour", buf);

  // Try concatenating a string longer than the initial string.
  printf("Testing on input (\"four\", \" score and\")...");
  strcpy(buf, "four");
  my_strcat(buf, " score and");
  expect_string("four score and", buf);

  printf("\n");
}

int main() {
  test_my_strcat();
  return 0;
}
