#include <stdio.h>
#include <stdlib.h>

int* add_sorta_maybe(int a, int b) {
    int* x = malloc(sizeof(int));
    *x =  a + b;
    return x;
}

int main() {
  int *sum = add_sorta_maybe(5, 7);
  printf("sum: %d\n", *sum);
  free(sum);
}
