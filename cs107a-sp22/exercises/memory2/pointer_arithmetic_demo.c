#include <stdio.h>

void print_chars(char *arr, int num_chars) {
  printf("Array as chars: ");
  char *ptr = arr;
  for (int i = 0; i < num_chars; i++) {
    printf("'%c', ", *ptr);
    ptr++;
  }
  printf("\n");

  printf("Array as chars (hex): ");
  ptr = arr;
  for (int i = 0; i < num_chars; i++) {
    printf("0x%x, ", *ptr);
    ptr++;
  }
  printf("\n");
}

void print_ints(int *arr, int num_ints) {
  printf("Array as ints: ");
  int *ptr = arr;
  for (int i = 0; i < num_ints; i++) {
    printf("%d, ", *ptr);
    ptr++;
  }
  printf("\n");

  printf("Array as ints (hex): ");
  ptr = arr;
  for (int i = 0; i < num_ints; i++) {
    printf("0x%x, ", *ptr);
    ptr++;
  }
  printf("\n");
}

int main() {
  // This char array has 12 chars including the NUL terminator.
  char arr[] = "abracadabra";

  // Pass a char* pointer, tell the function there are 12 chars.
  print_chars(arr, sizeof(arr) / sizeof(char));

  // Pass an int* pointer, tell the function there are 3 ints.
  print_ints((int*)arr, sizeof(arr) / sizeof(int));

  return 0;
}
