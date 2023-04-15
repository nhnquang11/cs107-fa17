/*
 * File: code.c
 * ------------
 * Code to read/analyze, CS107 assign1
 * Refer to assignment writeup for more information.
 */
#include <sys/param.h>
#include <stdbool.h>
#include <stdio.h>

int mid_orig(int low, int high)
{
    return (low + high) / 2;
}

int mid_A(int low, int high)
{
    return low + ((high - low) / 2);
}

int mid_B(int low, int high)
{
    return ((unsigned int)low + (unsigned int)high) >> 1;
}

int mid_C(int low, int high)
{
    return (low & high) + ((low ^ high) >> 1);
}

bool has_zero_byte(unsigned long val)
{
    unsigned long ones = ~0UL/UCHAR_MAX;
    unsigned long highs = ones << (CHAR_BIT - 1);
    return ((val - ones) & (~val & highs)) != 0;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i <= 10; i++)
        printf("powerof2(%d) = %d\n", i, powerof2(i));
    
    int a1 = INT_MIN + 1, b1 = INT_MAX;
    printf("mid(%d, %d) = %d(orig) %d(A) %d(B) %d(C)\n", 
        a1, b1, mid_orig(a1, b1), mid_A(a1, b1), mid_B(a1, b1), mid_C(a1, b1));

    int a2 = -3, b2 = -1;
    printf("mid(%d, %d) = %d(orig) %d(A) %d(B) %d(C)\n", 
        a2, b2, mid_orig(a2, b2), mid_A(a2, b2), mid_B(a2, b2), mid_C(a2, b2));

    unsigned long num = 0x1a2b3c004d5e6f;
    printf("has_zero_byte(%#lx) = %d\n", num, has_zero_byte(num));
    
    printf("%x\n", UCHAR_MAX);
    return 0;
}
