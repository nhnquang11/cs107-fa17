#include <stdio.h>
#include <string.h>

/**
 * Moves the first element of this array, if it exists, to the back.
 *
 * For example, if the array was [1, 2, 3] (note: it's generic, so we can't
 * assume these are ints), then after this function completes, the array should
 * contain [2, 3, 1].
 *
 * @param base Pointer to beginning of array
 * @param width Number of bytes in a single element
 * @param nelems Number of elements in the array
 */
void move_to_back(void *base, size_t width, size_t nelems) {
    // If there is no second element, there's no need to move anything.
    if (nelems <= 1) {
        return;
    }
    // Save the first element locally. We'll be overwriting it when we move the
    // other elements up.
    char temp[width];
    memcpy(temp, base, width);
  // Move all other elements up.
  memmove(base, (char*)base + width, (nelems - 1) * width);
  // Copy the first element to the end.
  memcpy((char*)base + (nelems - 1) * width, temp, width);
}

/**
 * Prints an integer array for convenience.
 *
 * @param arr Pointer to the int array
 * @param n Length of the array
 */
void print_int_array(int *arr, int n) {
  printf("[");
  for (int i = 0; i < n-1; i++) {
    printf("%d, ", arr[i]);
  }
  if (n > 0) {
    printf("%d", arr[n-1]);
  }
  printf("]\n");
}

/**
 * Prints a string array for convenience.
 *
 * @param arr Pointer to the string array
 * @param n Length of the array
 */
void print_str_array(char **arr, int n) {
  printf("[");
  for (int i = 0; i < n-1; i++) {
    printf("%s, ", arr[i]);
  }
  if (n > 0) {
    printf("%s", arr[n-1]);
  }
  printf("]\n");
}

int main() {
  // These test cases aren't exhaustive by any means.
  int empty_int[] = {};
  printf("Before: ");
  print_int_array(empty_int, sizeof(empty_int) / sizeof(empty_int[0]));
  move_to_back(empty_int, sizeof(empty_int[0]), sizeof(empty_int) / sizeof(empty_int[0]));
  printf("After: ");
  print_int_array(empty_int, sizeof(empty_int) / sizeof(empty_int[0]));

  int singleton_int[] = {42};
  printf("Before: ");
  print_int_array(singleton_int, sizeof(singleton_int) / sizeof(singleton_int[0]));
  move_to_back(singleton_int, sizeof(singleton_int[0]), sizeof(singleton_int) / sizeof(singleton_int[0]));
  printf("After: ");
  print_int_array(singleton_int, sizeof(singleton_int) / sizeof(singleton_int[0]));

  int triple_int[] = {42, 13, 55};
  printf("Before: ");
  print_int_array(triple_int, sizeof(triple_int) / sizeof(triple_int[0]));
  move_to_back(triple_int, sizeof(triple_int[0]), sizeof(triple_int) / sizeof(triple_int[0]));
  printf("After: ");
  print_int_array(triple_int, sizeof(triple_int) / sizeof(triple_int[0]));

  char *empty_str[] = {};
  printf("Before: ");
  print_str_array(empty_str, sizeof(empty_str) / sizeof(empty_str[0]));
  move_to_back(empty_str, sizeof(empty_str[0]), sizeof(empty_str) / sizeof(empty_str[0]));
  printf("After: ");
  print_str_array(empty_str, sizeof(empty_str) / sizeof(empty_str[0]));

  char *singleton_str[] = {"cat"};
  printf("Before: ");
  print_str_array(singleton_str, sizeof(singleton_str) / sizeof(singleton_str[0]));
  move_to_back(singleton_str, sizeof(singleton_str[0]), sizeof(singleton_str) / sizeof(singleton_str[0]));
  printf("After: ");
  print_str_array(singleton_str, sizeof(singleton_str) / sizeof(singleton_str[0]));

  char *triple_str[] = {"eenie", "meenie", "minie"};
  printf("Before: ");
  print_str_array(triple_str, sizeof(triple_str) / sizeof(triple_str[0]));
  move_to_back(triple_str, sizeof(triple_str[0]), sizeof(triple_str) / sizeof(triple_str[0]));
  printf("After: ");
  print_str_array(triple_str, sizeof(triple_str) / sizeof(triple_str[0]));
}
