#include <stdio.h>

/* Exercise 2-7. Write the function invert(x, p, n). */

unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
    printf("invert(0x%x, %d, %d) = 0x%x\n", 0xFFFF, 4, 4,
        invert(0xFFFF, 4, 4));
    printf("invert(0x%x, %d, %d) = 0x%x\n", 0xAAAA, 4, 4,
        invert(0xAAAA, 4, 4));

    return 0;
}

/* invert. Returns x with the n bits that begin at position p inverted. */
unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int mask;

    mask = ((1 << n) - 1) << p;
    return (x & ~mask) | (~x & mask);
}
