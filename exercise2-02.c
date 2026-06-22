#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

/* Exercise 2-1. Write a loop equivalent without using && or || */

int main()
{
    int i, c;

    for (i = 0; i < MAXLINE - 1; ++i) {
        if ((c = getchar()) == '\n')
            break;
        if (c == EOF)
            break;

        putchar(c);
    }
}
