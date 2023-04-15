#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Represents a generic, ordered, two-tuple (a pair!) of values.
 *
 * The two values should be of the same type. These could be two ints, two
 * strings, maybe even two pairs!
 *
 * Programmers should allocate a struct pair, either on the stack or the heap,
 * then use pair_create() to initialize it. For example,
 *
 * struct pair origin;
 * int x = 0;
 * int y = 0;
 * pair_create(&origin, &x, &y, sizeof(int));
 */
struct pair {
  void *two_elem_arr; // 2-element array where the values are stored.
  size_t elem_size;   // Size of elements stored.
};

/**
 * Initializes a pair with the given values.
 * @param p The pair to initialize
 * @param first Pointer to first generic value
 * @param second Pointer to second generic value
 * @param elem_size Number of bytes taken up by any value
 */
void pair_create(struct pair *p, void *first, void *second, size_t elem_size) {
  p->two_elem_arr = malloc(2 * elem_size);
  assert(p->two_elem_arr != NULL);
  p->elem_size = elem_size;
  memcpy(p->two_elem_arr, first, elem_size);
  memcpy((char*)p->two_elem_arr + elem_size, second, elem_size);
}

/**
 * Frees any internal memory used by a pair.
 * Assumes the pair is already initialized.
 * You may still need to free the pair itself if you heap-allocated it!
 * @param p The pair to free
 */
void pair_free(struct pair *p) {
  free(p->two_elem_arr);
}

/**
 * Extracts the first value and puts it into @code data.
 * @param p The pair to extract from
 * @param data Pointer to write the value into
 */
void pair_get_first(struct pair *p, void *data) {
  memcpy(data, p->two_elem_arr, p->elem_size);
}

/**
 * Extracts the second value and puts it into @code data.
 * @param p The pair to extract from
 * @param data Pointer to write the value into
 */
void pair_get_second(struct pair *p, void *data) {
  void *second = (char*)p->two_elem_arr + p->elem_size;
  memcpy(data, second, p->elem_size);
}

/**
 * Sets the first value with the given value.
 * @param p The pair to set the first value of
 * @param data Pointer to value to set
 */
void pair_set_first(struct pair *p, void *data) {
  memcpy(p->two_elem_arr, data, p->elem_size);
}

/**
 * Sets the second value with the given value.
 * @param p The pair to set the second value of
 * @param data Pointer to value to set
 */
void pair_set_second(struct pair *p, void *data) {
  void *second = (char*)p->two_elem_arr + p->elem_size;
  memcpy(second, data, p->elem_size);
}

/**
 * Swaps the first and second values in the pair.
 * @param p The pair to swap
 */
void pair_swap(struct pair *p) {
  void *second = (char*)p->two_elem_arr + p->elem_size;
  char temp[p->elem_size];
  memcpy(temp, p->two_elem_arr, p->elem_size);
  memcpy(p->two_elem_arr, second, p->elem_size);
  memcpy(second, temp, p->elem_size);
}

/**
 * Prints an int pair that represents a football score.
 *
 * @code p MUST hold ints.
 *
 * @param p The pair representing a score to print
 */
void print_score(struct pair *p) {
  // Initialize a and b with poison values that should be overwritten.
  int a = -1;
  int b = -1;
  pair_get_first(p, &a);
  pair_get_second(p, &b);
  printf("Current football score is %d against %d!\n", a, b);
}

/**
 * Prints a string pair that represents a name.
 *
 * @code p MUST hold char*s.
 *
 * @param p The pair representing a name to print
 */
void print_name(struct pair *p) {
  // Initialize a and b with poison values that should be overwritten.
  char *a = "uninitializedFirst";
  char *b = "uninitializedSecond";
  pair_get_first(p, &a);
  pair_get_second(p, &b);
  printf("This instructor's name is %s %s!\n", a, b);
}

int main() {
  /*
   * INT PAIR ON THE STACK
   */
  struct pair stack_score;
  int a = 0;
  int b = 0;
  pair_create(&stack_score, &a, &b, sizeof(int));

  printf("[stack] ");
  print_score(&stack_score);

  int c = 7;
  pair_set_first(&stack_score, &c);

  printf("[stack] ");
  print_score(&stack_score);

  c = 6;
  pair_set_second(&stack_score, &c);

  printf("[stack] ");
  print_score(&stack_score);

  pair_swap(&stack_score);

  printf("[stack] ");
  print_score(&stack_score);

  pair_free(&stack_score);

  /*
   * INT PAIR ON THE HEAP
   */
  struct pair *heap_score = malloc(sizeof(struct pair));
  assert(heap_score != NULL);
  a = 0;
  b = 0;
  pair_create(heap_score, &a, &b, sizeof(int));

  printf("[heap] ");
  print_score(heap_score);

  c = 7;
  pair_set_first(heap_score, &c);

  printf("[heap] ");
  print_score(heap_score);

  c = 6;
  pair_set_second(heap_score, &c);

  printf("[heap] ");
  print_score(heap_score);

  pair_swap(heap_score);

  printf("[heap] ");
  print_score(heap_score);

  pair_free(heap_score);
  free(heap_score);

  /*
   * STRING PAIR ON THE HEAP
   */
  // Create a pair on the heap initialized to "Nick" and "Parlante".
  struct pair *instructor = malloc(sizeof(struct pair));
  char *nick = "Nick";
  char *parlante = "Parlante";
  pair_create(instructor, &nick, &parlante, sizeof(char*));

  print_name(instructor);

  // Set the first name to "Troccoli" (not a typo).
  char *troccoli = "Troccoli";
  pair_set_first(instructor, &troccoli);

  print_name(instructor);

  // Set the last name to "Nicholas" (not a typo);
  char *nicholas = "Nicholas";
  pair_set_second(instructor, &nicholas);

  print_name(instructor);

  // Swap the first and last names.
  pair_swap(instructor);

  print_name(instructor);

  // Appropriately free all memory used by the instructor pair.
  pair_free(instructor);
  free(instructor);
}
