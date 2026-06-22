#include <stdio.h>

int power(int m, int n);
int power2(int m, int n);

/* test power function */

int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %3d %6d\n", i, power(2, i), power2(-3, i));
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/* power: raise base to n-th power; n >= 0; version 2 */
int power2(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
