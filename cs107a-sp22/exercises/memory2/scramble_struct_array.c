#include <stdio.h>
#include <stdlib.h>

struct labelled_string {
  int label;
  char *s;
};

void print_labelled_string(struct labelled_string *ls) {
  printf("%d: %s\n", ls->label, ls->s);
}

void scramble(struct labelled_string *ls1, struct labelled_string *ls2) {
  char *temp = ls1->s;
  ls1->s = ls2->s;
  ls2->s = temp;
}

int main() {
  // This is not an exhaustive list of all the variations you could do!
  // In general, you can put the array in either the stack or heap, and its
  // contents can be either the structs themselves, or pointers to the structs
  // in either the stack or heap.

  // A stack-allocated array of stack-allocated structs.
  // There's also a way to do this all in one assignment, but I'm doing it this
  // way to show how to access the elements of this array.
  struct labelled_string sasa[2];
  sasa[0].label = 1;
  sasa[0].s = "we are number one ðŸŽ¶";
  sasa[1].label = 2;
  sasa[1].s = "a tale of two cities";

  // A heap-allocated array of heap-allocated structs.
  struct labelled_string *haha = malloc(2*sizeof(struct labelled_string));
  haha[0].label = 3;
  haha[0].s = "the three musketeers";
  haha[1].label = 4;
  haha[1].s = "long ago, the four nations lived together in harmony";

  // A heap-allocated array of pointers to heap-allocated structs.
  struct labelled_string **hapha = malloc(2*sizeof(struct labelled_string*));
  hapha[0] = malloc(sizeof(struct labelled_string));
  hapha[0]->label = 5;
  hapha[0]->s = "five nights at freddy's";
  hapha[1] = malloc(sizeof(struct labelled_string));
  hapha[1]->label = 6;
  hapha[1]->s = "six flags";

  printf("Before:\n");
  print_labelled_string(sasa);
  print_labelled_string(sasa+1);
  print_labelled_string(haha);
  print_labelled_string(haha+1);
  print_labelled_string(hapha[0]);
  print_labelled_string(hapha[1]);

  scramble(sasa+1, hapha[0]);

  printf("After:\n");
  print_labelled_string(sasa);
  print_labelled_string(sasa+1);
  print_labelled_string(haha);
  print_labelled_string(haha+1);
  print_labelled_string(hapha[0]);
  print_labelled_string(hapha[1]);

  // Free the array, whose block includes the structs.
  free(haha);
  // Free the individual blocks where the structs reside, then the array of
  // pointers.
  free(hapha[0]);
  free(hapha[1]);
  free(hapha);
}
