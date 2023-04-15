//#include "samples/prototypes.h"
#include <error.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define US (unsigned short)

#define T1 (unsigned short) 0x0080
#define T2 (unsigned short) 0x0800
#define HEXFROM110 (unsigned char) 0x6
#define HEXFROM10 (unsigned char) 0x2
#define HEXFROM1110 (unsigned char) 0xe

/** Given a Unicode code point cp, constructs its sequence of UTF-8
 *  encoded byte into seq.
 */
int to_utf8(unsigned short cp, unsigned char seq[]){
    /* One-byte sequence. */
    if (cp < T1) {
        seq[0] = (unsigned char) cp;
        return 1;
    }
    /* Two-byte sequence. */
    else if (cp >= T1 && cp < T2) {
        // leading byte
        unsigned char high_order = HEXFROM110 << 5;
        unsigned char low_order = (cp >> 6) & ((1U << 5) - 1);
        seq[0] = high_order | low_order;

        // continuation byte
        high_order = HEXFROM10 << 6;
        low_order = cp & ((1U << 6) - 1);
        seq[1] = high_order | low_order;
        return 2;
    }
    /* Three-byte sequence. */
    else {
        // leading byte
        unsigned char high_order = HEXFROM1110 << 4;
        unsigned char low_order = (cp >> 12) & ((1U << 4) - 1);
        seq[0] = high_order | low_order;

        // continuation byte 1
        high_order = HEXFROM10 << 6;
        low_order = (cp >> 6) & ((1U << 6) - 1);
        seq[1] = high_order | low_order;

        // continuation byte 2
        low_order = cp & ((1U << 6) - 1);
        seq[2] = high_order | low_order;
        return 3;
    }
}

// ------- DO NOT EDIT ANY CODE BELOW THIS LINE (but do add comments!)  -------

void print_utf8(unsigned short cp, unsigned char seq[], int len)
{
    int i;
    printf("U+%04X   Hex:", cp);
    for (i = 0; i < len; i++)
       printf(" %02x", seq[i]);
    for ( ; i < 4; i++) printf("   ");
    seq[len] = '\0';
    printf("Character: %s  \n", seq);  
}

unsigned short convert_arg(const char *str, unsigned short low, unsigned short high)
{
    char *end;
    long n = strtol(str, &end, 0);
    if (*end != '\0')
        error(1, 0, "Invalid code point '%s'", str);
    if (n < low || n > high) 
        error(1, 0, "Code point %s not in range [%u, %u]", str, low, high);
    return n;
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
        error(1, 0, "Missing argument. Please supply one or more unicode code points in decimal or hex.");
    
    for (int i = 1; i < argc; i++) {
        unsigned short cp = convert_arg(argv[i], 0, USHRT_MAX);
        unsigned char seq[4];
        int len = to_utf8(cp, seq);
        print_utf8(cp, seq, len);  
    }
    return 0;
}
