#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define PRINT_LEN 80 /* print lines longer than this value */

int mygetline(char line[], int maxline);

/* Exercise 1-17. Print lines longer than 80 characters */
int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > PRINT_LEN)
            printf("%s", line);

    return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i, n;

    for (i = n = 0; (c = getchar()) != EOF && c != '\n'; ++n)
        if (i < lim - 1) /* only add character if there is still space */
            s[i++] = c;
    if (c == '\n') {
        if (i < lim - 1) /* only add the return if there is still space */
            s[i++] = c;
        ++n;
    }
    s[i] = '\0';
    return n;
}
