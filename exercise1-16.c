#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int kr_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Exercise 1-16. Print longest input line and its length */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = kr_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("Length %d: %s\n", max, longest);
    return 0;
}

/* kr_getline: read a line into s, return length */
int kr_getline(char s[], int lim)
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

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
/* no, you should not assume it is big enough. it will bite you */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
