#include <stdio.h>

/* Exercise 2-10. Rewrite the function lower with a conditional expression. */

int lower(int c);

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}

/* lower: Returns the characters 'A' - 'Z' in lower case, or the original
          character. */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
