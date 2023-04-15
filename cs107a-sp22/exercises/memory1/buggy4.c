#include <stdio.h>
#include <stdlib.h>

void print_int(int *ptr) {
  printf("%d\n", *ptr);
}

int main() {
  int *ptr = malloc(sizeof(int));
  *ptr = 42;
  print_int(ptr);
  free(ptr);
}
