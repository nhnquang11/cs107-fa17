#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

// We're only going to read 10 strings for simplicity's sake.
#define NUM_STRINGS 10

/**
 * Dedupes strings in an array so that future occurrences of the string just
 * point to the first occurrence.
 *
 * Yes, this is an inefficient O(n^2) solution, but we haven't learned about
 * hash tables, so we can't make it faster.
 *
 * Algorithm:
 * "For each index, if the string pointer there is the same string as at a
 * previous index but is not the same pointer, free the current string and set
 * it equal to the previous index's pointer."
 *
 * @param array Array of strings to dedupe
 * @param length Length of @code array
 * @return The number of strings deduped
 */
int dedupe_strings(char **array, int length) {
    int count = 0;
    for (int i = length - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (array[i] != array[j] && strcmp(array[i], array[j]) == 0) {
                free(array[i]);
                array[i] = array[j];
                count++;
                break;
            }
        }
    }
    return count;
}

/**
 * Frees a deduped array carefully so that no string is double-freed.
 *
 * Yes, this is a stupid O(n^2) algorithm since we're constrained by not using
 * any data structures except arrays.
 *
 * Algorithm:
 * "For each string pointer, if it's not NULL, set any future equal pointers to
 * NULL, then free the original string."
 *
 * That way, every time we see a string pointer for the first time, we NULL out
 * any future occurrences so we skip it when we iterate there.
 *
 * @param array Array of dedupe strings to free
 * @param length Length of @code array
 */
void free_strings(char **array, int length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] != NULL) {
            for (int j = i + 1; j < length; j++) {
                if (array[i] == array[j]) {
                    array[j] = NULL;
                }
            }   
            free(array[i]);
        }
    } 
}

void print_array(char **array, int length) {
  for (int i = 0; i < length; i++) {
    printf("%s\n", array[i]);
  }
}

int main(int argc, char *argv[]) {
  // Shamelessly stolen from assign3 starter code.
  FILE *file_pointer = NULL;

  if (argc == 1) {
      file_pointer = stdin;
  } else {
      file_pointer = fopen(argv[1], "r");
      if (file_pointer == NULL) {
          error(1, errno, "cannot access '%s'", argv[1]);
      }
  }

  char *strings[NUM_STRINGS];
  for (int i = 0; i < NUM_STRINGS; i++) {
    strings[i] = read_line(file_pointer);
  }

  printf("Before:\n");
  print_array(strings, NUM_STRINGS);

  printf("Deduped %d strings!\n", dedupe_strings(strings, NUM_STRINGS));

  printf("After:\n");
  print_array(strings, NUM_STRINGS);
  free_strings(strings, NUM_STRINGS);

  printf("Don't forget to valgrind to check for errors and leaks!\n");

  fclose(file_pointer);
}
