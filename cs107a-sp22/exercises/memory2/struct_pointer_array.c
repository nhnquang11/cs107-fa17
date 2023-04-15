#include <stdio.h>
#include <stdlib.h>

struct geolocation {
  int latitude; // Positive = north of equator, Negative = south
  int longitude; // Positive = east of Prime Meridian, Negative = west
};

int main() {
  // The following code isn't a good idea, but it does make for a nice memory
  // diagram example.

  // This is rounded to the nearest degree to avoid having to introduce floats.
  struct geolocation stanford = { 37, -122 };

  // The ith entry in this array is a pointer to the gelocation of the ith
  // student in the class.
  struct geolocation **locations = malloc(10*sizeof(struct geolocation*));
  for (int i = 0; i < 10; i++) {
    locations[i] = &stanford;
  }

  for (int i = 0; i < 10; i++) {
    printf("Student %d is at (%d, %d)\n", i, locations[i]->latitude,
        locations[i]->longitude);
  }

  // Cleanup.
  free(locations);
  // Do I need to free stanford?
  return 0;
}
