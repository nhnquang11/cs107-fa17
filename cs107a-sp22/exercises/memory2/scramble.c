#include <stdio.h>
#include <stdlib.h>

struct word_pair {
  char *first;
  char *second;
};

void scramble(struct word_pair *wp1, struct word_pair *wp2) {
  char *temp = wp1->first;
  wp1->first = wp1->second;
  wp1->second = wp2->first;
  wp2->first = wp2->second;
  wp2->second = temp;
}

int main() {
  struct word_pair pair1;
  pair1.first = "please";
  pair1.second = "draw";

  struct word_pair *pair2_p = malloc(sizeof(struct word_pair));
  pair2_p->first = "memory";
  pair2_p->second = "diagrams";

  printf("Printing in the following order: pair1.first, pair1.second, pair2_p->first, pair2_p->second\n");

  printf("Before: %s %s %s %s\n", pair1.first, pair1.second, pair2_p->first, pair2_p->second);
  scramble(&pair1, pair2_p);
  printf("After: %s %s %s %s\n", pair1.first, pair1.second, pair2_p->first, pair2_p->second);

  free(pair2_p);
}
