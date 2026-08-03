#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int kr_getline(char line[], int limit);
int trimline(char line[]);
int trimline2(char line[], int length);

/* Exercise 1-18. Remove trailing whitespaces and blank lines */
int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = kr_getline(line, MAXLINE)) > 0)
        if ((len = trimline2(line, len)) > 0)
            printf("%s", line);

    return 0;
}

/* kr_getline: read a line into s, return length */
int kr_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/* trimline: removes trailing whitespace from a line */
/* Walk through the line until end of the string and save the index
   of the last non-whitespace character. If hit the end or
   find a return, set a \0 after the index. */
int trimline(char line[])
{
    char c;
    int i, n;

    for (n = i = 0; (c = line[n]) && c != '\n' && c != '\0'; ++n) {
        if (c != ' ' && c != '\t') {
            i = n;
        }
    }
    /* copy index of last non-whitespace char (if any) back to length
     as return value */
    n = i;

    if (c == '\n') {
        line[++i] = '\n';
    }

    line[++i] = '\0';

    return n;
}

/* trimline2: removes trailing whitespace form a line */
/* We have the length of the line, so it is more efficient to go from the end */
int trimline2(char line[], int len)
{
    char c;
    int i, addNL;

    addNL = (line[len - 1] == '\n');

    for (i = len - (1 + addNL);
         (c = line[i]) && (c == ' ' || c == '\t') && i > 0;
         --i)
         ;

    if (addNL) {
        line[i + 1] = '\n';
    }
    line[i + (1 + addNL)] = '\0';


    return i;
}
