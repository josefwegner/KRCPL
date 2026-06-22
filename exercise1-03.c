#include <stdio.h>

/* Exercise 1-3. Print a header. */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("Fahr Celsius\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f   %5.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
