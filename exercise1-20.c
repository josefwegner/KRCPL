#include <stdio.h>

#define TABWIDTH 8      /* replace a tab with this number of spaces */

/* Exercise 1-20. Detab the program's input. */
int main()
{
    int c, i;

    while ((c = getchar()) != EOF) {
        if (c != '\t') {
            putchar(c);
        } else {
            for (i = 0; i < TABWIDTH; ++i) {
                putchar(' ');
            }
        }
    }

    return 0;
}

