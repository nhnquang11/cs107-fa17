#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a "messy pointer array" for the given array.
 *
 * A "messy pointer array" for some array A is a new array of pointers where
 * each pointer points to a separate block of memory containing the respective
 * value in the original array.
 *
 * For instance, if A were {1, 2, 3}, then the "messy pointer array" for A is a
 * new array {ptr1, ptr2, ptr3} where ptr1 points to a heap-allocated int
 * containing 1, ptr2 points to a heap-allocated int containing 2, etc.
 *
 * @param arr The array to create a "messy pointer array" for
 * @param n The length of @code arr
 * @return Pointer to the "messy pointer array"
 */
int **create_messy_ptr_array(int arr[], int n) {
  int **ptrs = malloc(n * sizeof(int*));
  assert(ptrs != NULL);
  for (int i = 0; i < n; i++) {
    ptrs[i] = malloc(sizeof(int));
    assert(ptrs[i] != NULL);
    *ptrs[i] = arr[i];
  }
  return ptrs;
}

/**
 * Prints out the integer contents of a "messy pointer array".
 *
 * @param arr The "messy pointer array" to print
 * @param n The length of @code arr
 */
void print_messy_ptr_array(int *arr[], int n) {
  printf("{");
  for (int i = 0; i < n; i++) {
    printf("%d, ", *arr[i]);
  }
  printf("}\n");
}

/**
 * Consolidates the pointed-to memory blocks in a "messy pointer array" into a
 * single block.
 *
 * For example, the "messy pointer array" for {1, 2, 3} contains three pointers
 * that each point to separate allocated ints. After this function runs, the
 * pointers would point into a single memory block big enough to contain the
 * three ints.
 *
 * @param arr The "messy pointer array" to consolidate
 * @param n The length of @code arr
 */
void consolidate_messy_ptr_array(int *arr[], int n) {
    int *new_arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        new_arr[i] = *arr[i];
        free(arr[i]);
        arr[i] = new_arr + i;
    }
}

/**
 * Handles freeing a consolidated "messy pointer array".
 *
 * This assumes the array has already been consolidated; do not call on an
 * unconsolidated "messy pointer array".
 *
 * @param arr The "messy pointer array" to free
 */
void free_messy_ptr_array(int *arr[]) {
    free(arr[0]);
    free(arr);
}

int main() {
  int arr[10] = {
    91, 73, 68, 2, 81, 94, 10, 69, 97, 71,
  };

  int **ptrs = create_messy_ptr_array(arr, sizeof(arr) / sizeof(arr[0]));

  printf("To check your work, make sure these printed arrays continue to match"
         " after you've written the consolidate function, and that you get a "
         "clean valgrind report!\n");
  printf("Before consolidation:\n");
  print_messy_ptr_array(ptrs, sizeof(arr) / sizeof(arr[0]));

  consolidate_messy_ptr_array(ptrs, sizeof(arr) / sizeof(arr[0]));

  printf("After consolidation:\n");
  print_messy_ptr_array(ptrs, sizeof(arr) / sizeof(arr[0]));

  free_messy_ptr_array(ptrs);
}
