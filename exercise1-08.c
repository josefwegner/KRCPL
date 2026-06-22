#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs and newlines */

int main()
{
    long nb, nt, nl;
    int c;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;
    printf("blanks: %ld, tabs: %ld, lines: %ld\n", nb, nt, nl);
}
