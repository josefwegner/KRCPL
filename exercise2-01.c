#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* Exercise 2-1. Print the limits of all types */

int main()
{
    signed char sc;
    unsigned char uc;
    signed short ss;
    unsigned short us;
    signed int si;
    unsigned int ui;
    signed long sl;
    unsigned long ul;

    /* from limits.h */
    printf("Limits from limits.h:\n---------------------\n\n");
    printf("signed   char:  %11d to %10d\n", SCHAR_MIN, SCHAR_MAX);
    printf("signed   short: %11d to %10d\n", SHRT_MIN, SHRT_MAX);
    printf("signed   int:   %11d to %10d\n", INT_MIN, INT_MAX);
    printf("signed   long:  %11ld to %10ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned char:  %11u to %10u\n", 0, UCHAR_MAX);
    printf("unsigned short: %11u to %10u\n", 0, USHRT_MAX);
    printf("unsigned int:   %11u to %10u\n", 0, UINT_MAX);
    printf("unsigned long:  %11lu to %10lu\n", 0L, ULONG_MAX);
    printf("float:          %f to %f\n", -FLT_MAX, FLT_MAX);
    printf("double:         %lf to %lf\n", -DBL_MAX, DBL_MAX);

    printf("Calculated limits:\n----------------------\n\n");
    sc = (signed char) (pow(2, 8 * sizeof(char) - 1) - 1);
    printf("signed   char:  %11d to %10d\n", (signed char) (sc + 1), sc);
    ss = (signed short) (pow(2, 8 * sizeof(short) - 1) - 1);
    printf("signed   short: %11d to %10d\n", (signed short) (ss + 1), ss);
    si = (signed int) (pow(2, 8 * sizeof(int) - 1) - 1);
    printf("signed   int:   %11d to %10d\n", (signed int) (si + 1), si);
    sl = (signed long) (pow(2, 8 * sizeof(long) - 1) - 1);
    printf("signed   long:  %11ld to %10ld\n", (signed long) (sl + 1), sl);
    uc = (unsigned char) (pow(2, 8 * sizeof(char)) - 1);
    printf("unsigned char:  %11u to %10u\n", 0, uc);
    us = (unsigned short) (pow(2, 8 * sizeof(short)) - 1);
    printf("unsigned short: %11u to %10u\n", 0, us);
    ui = (unsigned int) (pow(2, 8 * sizeof(int)) - 1);
    printf("unsigned int:   %11u to %10u\n", 0, ui);
    ul = (unsigned long) (pow(2, 8 * sizeof(long)) - 1);
    printf("unsigned long:  %11lu to %10lu\n", 0L, ul);

    return 0;
}

