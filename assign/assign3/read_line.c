#include "samples/prototypes.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
// initial allocation will be for min size, if not big enough, doubles
// to 64, then 128, then 256, etc. as needed to accommodate the entire line
#define MINIMUM_SIZE 32

char *read_line(FILE *fp){
    size_t capacity = MINIMUM_SIZE;     /* Initial estimated capacity */
    size_t length = 0;
    char *line;                         /* Buffer to store characters */
    int c;                              /* To read char from file */
    int first_time = 1;                 /* To decide whether to initilize buffer or return NULL */
    while (1) {
        /* Get the character from the file */
        c = fgetc(fp);
        if (first_time) {
            /* The file contains no more lines to read */
            if (c == EOF) return NULL;
            /* Initialization for the first time */
            line = malloc(capacity);
            assert(line != NULL);
            first_time = 0;
        }
        
        if (c == EOF || c == '\n') {
            break;
        }
        line[length] = c;
        ++length;
        /* If the line is longer than the estimated capacity, realloc the buffer
         * to double its current size, and attempt to read the rest of the line
         * */
        if (length == capacity) {
            capacity *= 2;
            line = realloc(line, capacity);
            assert(line != NULL);
        }
    }

    line[length] = '\0';

    return line;
}
