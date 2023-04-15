#include <stdlib.h>

int *is_it_two(int *ptr) {
    if (*ptr == 2) {
        return ptr;
    }
    return NULL;
}

int main() {
    int *ptr = malloc(sizeof(int));
    ptr = is_it_two(ptr);
    free(ptr);
}
