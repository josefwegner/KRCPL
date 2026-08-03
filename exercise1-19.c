#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int kr_getline(char line[], int limit);
void reverse(char line[], int length);

/* Exercise 1-19. Reverse the program's input line by line. */
int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = kr_getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

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

/* reverse: reverse a string in place */
/* swap characters one at a time */
/*
12:
len = 2
swap 0 and 1
One loop: 2 / 2

12\n:
len = 3
swap 0 and 1
One loop 3 - 1 / 2

123\n:
len = 4
swap 0 and 2
One loop 4 - 1 / 2

1234\n:
len = 5
swap 0 and 4
swap 1 and 3
Two loops
*/
void reverse(char line[], int len)
{
    char c;
    int i, addNL;

#ifdef DEBUG
    printf("len: %d\n", len);
#endif

    addNL = (line[len - 1] == '\n');

    if (len < (2 + addNL))
        return;

    for (i = 0; i < ((len - addNL) / 2) && (c = line[i]); ++i) {
#ifdef DEBUG
        printf("i: %d, i2: %d, c: %c\n", i, len - 1 - addNL - i, c);
#endif

        line[i] = line[len - 1 - addNL - i];
        line[len - 1 - addNL - i] = c;
    }
}
