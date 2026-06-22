#include <stdio.h>

/* Exercise 2-8. Write the function rightrot(x). */

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void)
{
    printf("rightrot(0x%x, %d) = 0x%x\n", 0xAAAAAAAA, 4,
        rightrot(0xAAAAAAAA, 4));
    printf("rightrot(0x%x, %d) = 0x%x\n", 0xA, 4,
        rightrot(0xA, 4));
    printf("rightrot(0x%x, %d) = 0x%x\n", 0xA, 8,
        rightrot(0xA, 8));
    printf("rightrot(0x%x, %d) = 0x%x\n", 0xA, 16,
        rightrot(0xA, 16));
    printf("rightrot(0x%x, %d) = 0x%x\n", 0xA, 32,
        rightrot(0xA, 32));

    return 0;
}

/* rightrot. Returns the value rotated to the right by n bit positions. */
unsigned int rightrot(unsigned int x, unsigned int n)
{
    unsigned int mask, tmp;

    mask = ~(~0 << n);
    tmp = x & mask;
    printf("    0x%x - 0x%x\n", mask, tmp);
    return (x >> n) | tmp << (32 - n);
}
