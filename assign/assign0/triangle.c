/* File: triangle.c
 * ----------------
 * Outputs an ascii representation of the Sierpinski triangle.
 *
 * The pattern of stars is generated using a bitwise AND 
 * on the coordinates. This works due to the relationship
 * between the fractal and Pascal's triangle.
 * https://en.wikipedia.org/wiki/Sierpinski_triangle
 */

#include <error.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LEVELS 3
#define LOWER_BOUND 0
#define UPPER_BOUND 8

void print_triangle(int nlevels)
{
    int size = 1 << nlevels;

    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < row; col++) {
            printf(" ");
        }
        for (int col = 0; col + row < size; col++) {
            printf("%c ", (col & row) ? ' ' : '*');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int nlevels = DEFAULT_LEVELS;
    if (argc > 1) {
        nlevels = atoi(argv[1]);
    }

    if (nlevels < LOWER_BOUND || nlevels > UPPER_BOUND) {
        error(1, 0, "Invalid level! The level must be non-negative and less than %d.", UPPER_BOUND + 1);
    }

    print_triangle(nlevels);
    return 0;
}
