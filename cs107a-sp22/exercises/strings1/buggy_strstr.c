#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Finds the first occurrence of @code needle in @code haystack, else NULL.
 * See more at `man strstr`, as it implements that function.
 *
 * NOTE: This function is buggy! Also, the intended algorithm is not the fastest
 * it could be. If you're interested at what an efficient solution would be, see
 * https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
 *
 * @param haystack The string to find @code needle within
 * @param needle The string to find
 * @return Pointer to instance of @code needle within @code haystack, else NULL
 */
const char *buggy_strstr(const char *haystack, const char *needle) {
  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);
  // Upper bound subtracts needle_len since a needle can't extend beyond the end
  // of the haystack.
  for (int i = 0; i < haystack_len - needle_len + 1; i++) {
    if (strncmp(haystack + i, needle, needle_len) == 0) {
      return haystack + i;
    }
  }
  return NULL;
}

int main() {
  printf("Looking for \"tan\" in \"stanford\"!\n");
  const char *tan = buggy_strstr("stanford", "tan");
  if (tan == NULL) {
    printf("Could not find \"tan\" in \"stanford\"!\n");
  } else {
    printf("Found \"tan\"! The substring starting at it is \"%s\"\n", tan);
  }

  printf("\n");

  printf("Looking for \"golden bears\" in \"stanford\"!\n");
  const char *gbears = buggy_strstr("stanford", "golden bears");
  if (gbears == NULL) {
    printf("Could not find \"golden bears\" in \"stanford\"!\n");
  } else {
    printf("Found \"golden bears\"! The substring starting at it is \"%s\"\n", gbears);
  }
  return 0;
}
