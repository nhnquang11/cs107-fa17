#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = 5*i;
    }
    free(arr);
    return 0;
}
