#include <stdio.h>

int bitcount(unsigned int x);

/* Exercise 2-9. Why does x &= (x - 1) deletes the rightmmost 1-bit?
                 Implement a faster bitcount with this. */

int main(void)
{
    printf("bitcount(0x%x) = %d\n", 0xAAAA, bitcount(0xAAAA));
    printf("bitcount(0x%x) = %d\n", 0x8000, bitcount(0x8000));
    printf("bitcount(0x%x) = %d\n", 0xFFFFFFFF, bitcount(0xFFFFFFFF));

    return 0;
}

/* bitcount: Returns the number of 1-bits in an int. Faster version. */
int bitcount(unsigned int x)
{
    int n;

    n = 0;
    while (x) {
        x &= (x - 1);
        n++;
    }

    return n;}

/*
 It works because the -1 flips all bits until it encounters the
 rightmost 1-bit or the most significant bit. The mask then sets
 everything to 0 including the place of the rightmost 1-bit.
 */
