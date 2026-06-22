#include <stdio.h>

float toCelsius(int fahrenheit);

/* Exercise 1-15. Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300.
   version using a function */

#define LOWER 0     /* lower limit of temperature table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d%7.1f\n", fahr, toCelsius(fahr));
    }
}

float toCelsius(int fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
