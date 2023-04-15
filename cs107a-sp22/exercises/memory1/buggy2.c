#include <stdio.h>
#include <string.h>

void print_char_by_char(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("The %dth char is %c\n", i, arr[i]);
    }
}

int main() {
    char stack_string[] = "stack";
    // strdup creates a heap-allocated copy of a string.
    char *heap_string = strdup("heap");
    
    print_char_by_char(stack_string, sizeof(stack_string) - 1);
    print_char_by_char(heap_string, strlen(heap_string));
    return 0;
}
