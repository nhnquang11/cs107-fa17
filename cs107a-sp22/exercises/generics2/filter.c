#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Returns an array of the elements in @code arr for which @code should_keep
 * returns true.
 *
 * (This operation is well-known as the "filter" operation.)
 *
 * @code should_keep is called once for each element in the array.
 *
 * The returned array is heap-allocated. It is the caller's responsibility to
 * free it.
 *
 * For this version of filter, it is acceptable for the returned array to be of
 * the same size as @code arr even though there may be fewer filtered elements
 * than in the original array.
 *
 * The size of the returned array should be written to @code filtered_size.
 *
 * @param arr Pointer to generic array to filter
 * @param num_elems Number of elements in @code arr
 * @param elem_size Size in bytes of each element in @code arr
 * @param should_keep Predicate function determining whether to keep an element
 * @param filtered_size Pointer to where the size of the output array will be written
 * @return Pointer to heap-allocated array of filtered elements
 */
void *filter(void *arr, size_t num_elems, size_t elem_size,
    bool (*should_keep)(void *elem), int *filtered_size) {
    void *filtered_arr = malloc(num_elems * elem_size);
    assert(filtered_arr != NULL);
    int next_slot = 0;
    for (int i = 0; i < num_elems; ++i) {
        void *ptr_ith = (char *)arr + i * elem_size;
        if (should_keep(ptr_ith)) {
            void *next_ptr = (char *)filtered_arr + next_slot * elem_size;
            memcpy(next_ptr, ptr_ith, elem_size);
            next_slot++;
        }
    }
    *filtered_size = next_slot;
    return filtered_arr;
}

/**
 * Determines whether a pointed-to int is even.
 *
 * This function adheres to the @code should_keep interface.
 *
 * @param elem Pointer to int to check parity
 * @return Whether the pointed-to int is even
 */
bool is_even(void *elem) {
  return *(int*)elem % 2 == 0;
}

void demo_filter_for_ints() {
  int integers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  size_t num_ints = sizeof(integers) / sizeof(integers[0]);

  printf("Original integers before filtering: ");
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", integers[i]);
  }
  printf("\n");

  int filtered_size = 0;
  int *filtered_integers = filter(integers, num_ints, sizeof(int), is_even, &filtered_size);

  printf("Original integers after mapping: ");
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", integers[i]);
  }
  printf("\n");

  printf("Filtered integers: ");
  for (int i = 0; i < filtered_size; i++) {
    printf("%d, ", filtered_integers[i]);
  }
  printf("\n");

  free(filtered_integers);
}

/**
 * Determines whether a pointed-to string does not contain an 'o'.
 *
 * This function adheres to the @code should_keep interface.
 *
 * @param elem Pointer to string to check for 'o'
 * @return Whether the pointed-to string does not contain an 'o'
 */
bool does_not_contain_o(void *elem) {
    return strchr(*(char **)elem, 'o') == NULL;
}

void demo_filter_for_strings() {
  char *strings[] = {"according", "to", "all", "known", "laws", "of", "aviation"};
  size_t num_strings = sizeof(strings) / sizeof(strings[0]);

  printf("Original strings before filtering: ");
  for (int i = 0; i < num_strings; i++) {
    printf("%s, ", strings[i]);
  }
  printf("\n");

  int filtered_size = 0; // Use this in your call to filter.
  char **filtered_strings = filter(strings, num_strings, sizeof(char *), does_not_contain_o, &filtered_size);

  printf("Original strings after filtering: ");
  for (int i = 0; i < num_strings; i++) {
    printf("%s, ", strings[i]);
  }
  printf("\n");

  printf("Filtered strings: ");
  for (int i = 0; i < filtered_size; i++) {
    printf("%s, ", filtered_strings[i]);
  }
  printf("\n");

  free(filtered_strings);
}

int main() {
  demo_filter_for_ints();
  printf("\n");
  demo_filter_for_strings();
  return 0;
}
