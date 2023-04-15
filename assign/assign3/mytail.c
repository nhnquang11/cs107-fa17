#include "samples/prototypes.h"
#include <error.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_NLINES_ON_STACK 10000

/** Prints the final N lines of the input. */
void print_last_n(FILE *fp, int n) {
    char *lines[MAX_NLINES_ON_STACK];
    char **arr;
    int using_heap = 0;  // To decide whether to free memory later
    if (n <= MAX_NLINES_ON_STACK) {
        arr = lines;
    } else {
        using_heap = 1;
        arr = malloc(n * sizeof(char *));
    }

    int pos = 0;  // Current position to add new line
    int wrap_around = 0;  // whether the number of lines in the file larger than the length of the array
    char *line;  // To store new line read from file
    int file_not_empty = 0; 
    while ((line = read_line(fp)) != NULL) {
        if (file_not_empty == 0) file_not_empty = 1;
        // If current position contains a line, free that line before point to
        // the new line.
        if (wrap_around) free(arr[pos]);
        // The array is full so we have to wrap around.   
        if (pos == n - 1)  wrap_around = 1;
        
        arr[pos] = line;
        pos = (pos + 1) % n;
    }
    // Print the final N lines of the input. 
    if (file_not_empty) {
        if (!wrap_around) {
            for (int i = 0; i < pos; ++i) {
                printf("%s\n", arr[i]);
                free(arr[i]);
            }
        } else {
            for (int i = (pos + 1) % n; i != pos; i = (i + 1) % n) {
                printf("%s\n", arr[i]);
                free(arr[i]);
            }
            printf("%s\n", arr[pos]);
            free(arr[pos]);
        }
    }

    if (using_heap) free(arr);
}

int convert_arg(const char *str) {
    char *end;
    long n = strtol(str, &end, 10);
    if (*end != '\0') 
        error(1, 0, "Invalid number '%s'", str);
    if (n < 1 || n > INT_MAX) 
        error(1, 0, "%s is not within the acceptable range [%d, %d]", str, 1, INT_MAX);
    return n;
}

int main(int argc, char *argv[]) {
    int num = 10;

    if (argc > 1 && argv[1][0] == '-') {
        num = convert_arg(argv[1] + 1);
        argv++;
        argc--;
    }

    FILE *fp;
    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) error(1, 0, "%s: no such file", argv[1]);
    }
    print_last_n(fp, num);
    fclose(fp);
    return 0;
}
