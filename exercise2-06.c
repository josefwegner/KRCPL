#include <stdio.h>

/* Exercise 2-6. Write the function setbits(x, p, n, y). */

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void)
{
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFFFF, 4, 4, 0xAAAA,
        setbits(0xFFFF, 4, 4, 0xAAAA));
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFFFF, 0, 0, 0xAAAA,
        setbits(0xFFFF, 0, 0, 0xAAAA));
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFFFF, 4, 0, 0xAAAA,
        setbits(0xFFFF, 4, 0, 0xAAAA));
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFF, 2, 4, 0x6,
        setbits(0xFF, 2, 4, 0x6));
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFFFFFFFF, 0, 32, 0xAAAAAAAA,
        setbits(0xFFFFFFFF, 0, 32, 0xAAAAAAAA));
    printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", 0xFFFFFFFF, 4, 28, 0xAAAAAAAA,
        setbits(0xFFFFFFFF, 4, 28, 0xAAAAAAAA));

    return 0;
}

/* setbits: Returns x with the n bits that begin at position p set to the
            rightmost n bits of y, leaving the other bits unchanged. */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int mask;

    mask = ((1 << n) - 1);
    return (x & ~(mask << p)) | ((y & mask) << p);
}
