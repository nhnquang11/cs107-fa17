#include <errno.h>
#include <error.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define INVERTED_BOX "\e[7m \e[0m"

// each cell is drawn as LIVE_STR or EMPTY_STR
// uncomment the alternate #define below to use + as LIVE_STR
// if your terminal doesn't play nice with inverted box
#define LIVE_STR INVERTED_BOX
//#define LIVE_STR "+"
#define EMPTY_STR " "

const int BITWIDTH =  sizeof(unsigned long) * 8;

/** Generates the next generation of the current generation based on
 *  the ruleset. */
unsigned long advance(unsigned long cur_gen, unsigned char ruleset){
    unsigned long advance = 0;
    unsigned char mask = 0x7; // get three rightmost bits

    /* For every cell from the leftmost to just before the rightmost,
     * right shift its neighborhood to the three rightmost position,
     * then filter out the three rightmost bits with mask to get the
     * neighborhood. */
    for (int i = BITWIDTH - 2; i >= 0; --i) {
        unsigned char neighborhood = (cur_gen >> i) & mask;

        /* Get the value of the kth position bit in the ruleset where
         * k is the value of neighborhood. */
        unsigned char state = (ruleset >> neighborhood) & 1U;

        /* Append the state to the result. */
        advance <<= 1;
        advance |= state;
    }

    /* For the rightmost cell, right shift the cur_gen by one and
     * filter out the three rightmost bits to get its neighborhood.  */
    unsigned char neighborhood = (cur_gen << 1) & mask;
    unsigned char state = (ruleset >> neighborhood) & 1U;
    advance <<= 1;
    advance |= state;

    return advance;
}

/** Prints out a line illustrating the given generation where bit 1
    is depicted by LIVE_STR and bit 0 is depicted by EMPTY_STR. */
void draw_generation(unsigned long gen){
    for (int i = BITWIDTH - 1; i >= 0; i--) {
        unsigned char state = (gen >> i) & 1U;
        if (state) {
            printf("%s", LIVE_STR);
        } else {
            printf("%s", EMPTY_STR);
        }
    }
    printf("\n");
}

// ------- DO NOT EDIT ANY CODE BELOW THIS LINE (but do add comments!)  -------

unsigned long convert_arg(const char *str, unsigned long low, unsigned long high, const char *argname)
{
    char *end;
    unsigned long n = strtoul(str, &end, 0);
    if (*end != '\0') 
        error(1, 0, "Invalid number '%s' for %s", str, argname);
    if (n < low || n > high || errno == ERANGE) 
        error(1, 0, "%s %s is not in range [%#lx, %#lx]", argname, str, low, high);
    return n;
}

int main(int argc, char *argv[])
{
    unsigned long gen_0 = 1L << 32;
    unsigned char ruleset = 30;

    if (argc < 2)
        error(1, 0, "Missing argument. Please supply ruleset and optional initial generation.");

    ruleset = convert_arg(argv[1], 0, UCHAR_MAX, "ruleset");
    if (argc > 2) gen_0 = convert_arg(argv[2], 0, ULONG_MAX, "initial generation");

    if (ruleset == 0) {
        draw_generation(gen_0);
    } else {
        unsigned long gen = gen_0;
        for (int i = 0; i < 32; i++) {
            draw_generation(gen);
            gen = advance(gen, ruleset);
        }
    }
    return 0;
}
