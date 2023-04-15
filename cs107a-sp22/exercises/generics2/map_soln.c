#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns a copy of the input array where each element has been transformed by
 * the input function.
 *
 * (This operation is well-known as the "map" operation.)
 *
 * @code transform is called once for each element in the array. This function
 * takes in a pointer to the src element, and writes the transformed version to
 * the dst pointer.
 *
 * The returned array is heap-allocated. It is the caller's responsibility to
 * free it.
 *
 * @param arr Pointer to generic array to map
 * @param num_elems Number of elements in @code arr
 * @param elem_size Size in bytes of each element in @code arr
 * @param transform Transformation function to perform on each element
 * @return Pointer to heap-allocated array of transformed elements
 */
void *map(void *arr, size_t num_elems, size_t elem_size, void (*transform)(void *dst, void *src)) {
  void *mapped_arr = malloc(num_elems * elem_size);
  for (int i = 0; i < num_elems; i++) {
    void *ith_dst_ptr = (char*)mapped_arr + i * elem_size;
    void *ith_src_ptr = (char*)arr + i * elem_size;
    transform(ith_dst_ptr, ith_src_ptr);
  }
  return mapped_arr;
}

/**
 * Given a pointer to an int, squares it, and writes to @code dst.
 *
 * This function adheres to the @code transform interface.
 *
 * @param dst Pointer to where to write the squared int
 * @param src Pointer to int to square
 */
void square_transform(void *dst, void *src) {
  int n = *(int*)src;
  *(int*)dst = n*n;
}

/** Demonstrates the use of the @code map function using an int array. */
void demo_map_for_ints() {
  int integers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  size_t num_ints = sizeof(integers) / sizeof(integers[0]);

  printf("Original integers before mapping: ");
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", integers[i]);
  }
  printf("\n");

  int *mapped_integers = map(integers, num_ints, sizeof(int), square_transform);

  printf("Original integers after mapping: ");
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", integers[i]);
  }
  printf("\n");

  printf("Mapped integers: ");
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", mapped_integers[i]);
  }
  printf("\n");

  free(mapped_integers);
}

/**
 * Given a pointer to a string, capitalizes it, and writes to @code dst.
 *
 * This function adheres to the @code transform interface.
 *
 * The pointed-to strings are assumed to be non-empty.
 *
 * NOTE: The capitalized strings are newly heap-allocated. It is the caller's
 * responsibility to free them.
 *
 * @param dst Pointer to where to write the squared int
 * @param src Pointer to int to square
 */
void capitalize(void *dst, void *src) {
  char *src_str = *(char**)src;
  char *copy = strdup(src_str);
  copy[0] = toupper(copy[0]);
  *(char**)dst = copy;
}

/** Demonstrates the use of the @code map function using a string array. */
void demo_map_for_strings() {
  char *strings[] = {"according", "to", "all", "known", "laws", "of", "aviation"};
  size_t num_strings = sizeof(strings) / sizeof(strings[0]);

  printf("Original strings before mapping: ");
  for (int i = 0; i < num_strings; i++) {
    printf("%s, ", strings[i]);
  }
  printf("\n");

  char **mapped_strings = map(strings, num_strings, sizeof(char*), capitalize);

  printf("Original strings after mapping: ");
  for (int i = 0; i < num_strings; i++) {
    printf("%s, ", strings[i]);
  }
  printf("\n");

  printf("Mapped strings: ");
  for (int i = 0; i < num_strings; i++) {
    printf("%s, ", mapped_strings[i]);
    free(mapped_strings[i]);
  }
  printf("\n");

  free(mapped_strings);
}

int main() {
  demo_map_for_ints();
  printf("\n");
  demo_map_for_strings();
  return 0;
}
