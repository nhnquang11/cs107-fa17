#include "samples/prototypes.h"
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/** Removes adjacent matching lines from the input; the output will contain oly
 * one copy of each line that is duplicated the input along with the number
 * counting the number of consecutive occurrences for each line in the input.*/
void print_uniq_lines(FILE *fp){
    char *prev_line = read_line(fp);
    if (prev_line == NULL) return;
    int count = 1;
    char *curr_line;
    while ((curr_line = read_line(fp)) != NULL) {
        if (strcmp(prev_line, curr_line) == 0) {
            ++count;
        } else {
            printf("%d %s\n", count, prev_line);
            count = 1;
        }
        free(prev_line);
        prev_line = curr_line;
    }
    printf("%d %s\n", count, prev_line);
    free(prev_line);
}

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) error(1, 0, "%s: no such file", argv[1]);
    }
    print_uniq_lines(fp);
    fclose(fp);
    return 0;
}
