#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_CAPACITY 10
#define ADDITIONAL_CAPACITY 5
#define NUM_NUMBERS 998

int main() {
  // Don't worry about this, this just initializes something for randomness.
  srand(time(NULL));

  // The current size of the array i.e. how many are stored.
  int size = 0;
  // The current capacity of the array i.e. how many can be stored.
  int capacity = INITIAL_CAPACITY;
  int *numbers = malloc(capacity * sizeof(int));
  assert(numbers != NULL); // As required by CS 107.

  // Aside: Doesn't it seem kinda dumb to resize as you go along, when we could
  // have allocated the array to NUM_NUMBERS ints at the beginning? Yes, that's
  // a great point, but this is just to serve as a demo. (If it weren't a demo,
  // we could have done this on the stack for better efficiency, like
  // int numbers[NUM_NUMBERS];
  // )

  for (int i = 0; i < NUM_NUMBERS; i++) {
    if (size == capacity) {
      // We're about to add a number, better resize!
      capacity += ADDITIONAL_CAPACITY;
      numbers = realloc(numbers, capacity * sizeof(int));
      assert(numbers != NULL); // As required by CS 107.
    }
    size++;
    // Don't worry about this, it just gets us a random number between 0 and 9.
    numbers[i] = rand() % 10;
  }

  // "But why are you doing it this way-" Yes, it's a demo; yes, you'd do it
  // differently in real life.
  int sum = 0;
  for (int i = 0; i < NUM_NUMBERS; i++) {
    sum += numbers[i];
  }
  printf("Final size: %d, final capacity: %d, sum of random numbers: %d\n",
      size, capacity, sum);

  free(numbers);
}
