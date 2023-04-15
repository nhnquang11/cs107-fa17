#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aged_person {
  char *first_name;
  unsigned int age;
};

void print_aged_person(struct aged_person *ap) {
  printf("{%s, %u}\n", ap->first_name, ap->age);
}

/**
 * Comparison function for struct aged_person* comparing by name then age.
 *
 * @param a Generic pointer to the first struct aged_person*
 * @param b Generic pointer to the first struct aged_person*
 * @return Negative if a < b, positive if b > a, 0 if equal
 */
int compare_aged_person_by_name_then_age(const void *a, const void *b) {
    struct aged_person *ap = *(struct aged_person**)a;
    struct aged_person *bp = *(struct aged_person**)b;
    int name_cmp = strcmp(ap->first_name, bp->first_name);
    if (name_cmp != 0) return name_cmp;

    return ap->age - bp->age;
}

/**
 * Comparison function for struct aged_person* comparing by age then name.
 *
 * @param a Generic pointer to the first struct aged_person*
 * @param b Generic pointer to the first struct aged_person*
 * @return Negative if a < b, positive if b > a, 0 if equal
 */
int compare_aged_person_by_age_then_name(const void *a, const void *b) {
    struct aged_person *ap = *(struct aged_person**)a;
    struct aged_person *bp = *(struct aged_person**)b;
    int age_cmp = ap->age - bp->age;
    if (age_cmp != 0) return age_cmp;

    return strcmp(ap->first_name, bp->first_name);
}

/**
 * Sorts the given struct aged_person* array according to the boolean parameter.
 *
 * @param arr Array of struct aged_person pointers
 * @param length Length of @code arr
 * @param by_name_first Whether to sort by name first (otherwise age first)
 */
void conditional_sort(struct aged_person **arr, int length, bool by_name_first) {
    qsort(arr, length, sizeof(struct aged_person*), by_name_first ? compare_aged_person_by_name_then_age : compare_aged_person_by_age_then_name);
}

int main() {
  struct aged_person people[] = {
    {"A", 40},
    {"B", 20},
    {"B", 30},
    {"C", 30},
  };
  struct aged_person *ptrs[] = {
    &people[3], // ptrs[0] = C, 30
    &people[2], // ptrs[1] = B, 30
    &people[1], // ptrs[2] = B, 20
    &people[0], // ptrs[3] = A, 40
    &people[0], // ptrs[4] = A, 40
  };

  printf("Testing compare_aged_person_by_name_then_age...\n");
  assert(compare_aged_person_by_name_then_age(&ptrs[0], &ptrs[1]) > 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[1], &ptrs[0]) < 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[1], &ptrs[2]) > 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[2], &ptrs[1]) < 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[2], &ptrs[3]) > 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[3], &ptrs[2]) < 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[3], &ptrs[4]) == 0);
  assert(compare_aged_person_by_name_then_age(&ptrs[4], &ptrs[3]) == 0);
  printf("Succeeded.\n");

  printf("Testing compare_aged_person_by_age_then_name...\n");
  assert(compare_aged_person_by_age_then_name(&ptrs[0], &ptrs[1]) > 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[1], &ptrs[0]) < 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[1], &ptrs[2]) > 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[2], &ptrs[1]) < 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[2], &ptrs[3]) < 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[3], &ptrs[2]) > 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[3], &ptrs[4]) == 0);
  assert(compare_aged_person_by_age_then_name(&ptrs[4], &ptrs[3]) == 0);
  printf("Succeeded.\n");

  printf("\n");

  printf("Testing conditional_sort...\n");
  printf("Before:\n");
  for (int i = 0; i < sizeof(ptrs) / sizeof(ptrs[0]); i++) {
    print_aged_person(ptrs[i]);
  }
  printf("After sorting by name then age:\n");
  conditional_sort(ptrs, sizeof(ptrs) / sizeof(ptrs[0]), true);
  for (int i = 0; i < sizeof(ptrs) / sizeof(ptrs[0]); i++) {
    print_aged_person(ptrs[i]);
  }
  printf("After sorting by age then name:\n");
  conditional_sort(ptrs, sizeof(ptrs) / sizeof(ptrs[0]), false);
  for (int i = 0; i < sizeof(ptrs) / sizeof(ptrs[0]); i++) {
    print_aged_person(ptrs[i]);
  }
}
