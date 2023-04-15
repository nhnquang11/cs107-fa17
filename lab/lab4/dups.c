#include <error.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool has_duplicates(void *arr, size_t n, size_t elemsz, int (*cmp)(const void *, const void *))
{
    for (int i = 0; i < n; i++) {
        void *ith = (char *)arr + i*elemsz;
        for (int j = i+1; j < n; j++) {
            void *jth = (char *)arr + j*elemsz;
            if (cmp(ith, jth) == 0) return true;
        }
    }
    return false;
}

void remove_duplicates(void *arr, size_t *p_n, size_t elemsz, int (*cmp)(const void *, const void *))
{
    int i = 0;
    while (i < *p_n) {
        void *ith = (char *)arr + i * elemsz;
        for (int j = i + 1; j < *p_n; ++j) {
            void *jth = (char *)arr + j * elemsz;
            if (cmp(ith, jth) == 0) {
                memmove((char *)arr + i * elemsz, 
                        (char *)arr + (i + 1) * elemsz, (*p_n - i - 1) * elemsz);
                --*p_n;
                --i;
                break;
            }
        }
        ++i;
    }
}

int cmp_magnitude(const void *p, const void *q)
{
    int a = *(int *)p;
    int b = *(int *)q;
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;
    return (a > b) - (a < b);
}

int convert_arg(const char *str)
{
    char *end;
    long n = strtol(str, &end, 10);
    if (*end != '\0') 
        error(1, 0, "Invalid number '%s'", str);
    if (n < INT_MIN || n > INT_MAX) 
        error(1, 0, "%s is not within the acceptable range [%d, %d]", str, INT_MIN, INT_MAX);
    return n;
}

void print_array(int arr[], int n, const char *label)
{
    printf("\n%s, array contains: {", label);
    for (int i = 0; i < n; i++) 
        printf(" %d ", arr[i]);
    printf("}\n");    
}

int main(int argc, char *argv[])
{
    int nums[argc - 1];
    size_t nused = 0;

    for (int i = 1; i < argc; i++)  nums[nused++] = convert_arg(argv[i]);

    print_array(nums, nused, "At start");
    bool dups = has_duplicates(nums, nused, sizeof(nums[0]), cmp_magnitude);
    printf("array has duplicate? %s\n", dups ? "yes" : "no");

    if (dups) {
        remove_duplicates(nums, &nused, sizeof(nums[0]), cmp_magnitude);
        print_array(nums, nused, "After remove dups");
        dups = has_duplicates(nums, nused, sizeof(nums[0]), cmp_magnitude);
        printf("now array has duplicate? %s\n", dups ? "yes" : "no"); 
    }
    return 0;
}
