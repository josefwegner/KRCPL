#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int kr_getline(char *, int);
int kr_atoi(const char *);
void kr_itoa (int, char *);
void reverse(char *);
int strindex(char *, char *);
int getop(char *);

int main(void)
{
    return EXIT_SUCCESS;
}

/* kr_getline: get line into s, return length */
int kr_getline(char *s, int lim)
{
    unsigned char c;
    char *sp = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *sp++= c;
    if (c == '\n')
        *sp++ = c;
    *sp = '\0';

    return sp - s;
}

/* kr_atoi: convert a string to an integer */
int kr_atoi(const char *s) {
    unsigned char c;
    int value, sign;

    while (isspace((c = *s++))) /* skip white space */
        ;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (value = 0; isdigit(*s); s++)
        value = 10 * value + (*s - '0');

    return sign * value;
}

/* kr_itoa: convert n to charactes in s */
void kr_itoa(int n, char *s)
{
    int sign;
    char *sstart = s;

    if ((sign = n) < 0)        /* record sign */
        n = -n;                /* make n positive */
    do {                       /* generate digits in reverse order */
        *s++ = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(sstart);
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    unsigned char c;
    char *ps = s;
    size_t len = strlen(s);

    if (len == 0)
        return;

    ps = ps + len - 1;

    while (s < ps) {
        c = *s;
        *s++ = *ps;
        *ps-- = c;
    }
}

/* strindex: return index of pattern in source, -1 if none */
int strindex(char *source, char *pattern)
{
  char *c, *s, *p;

  for (c = source; *c != '\0'; c++) {
    for (s = c, p = pattern; *p != '\0' && *s == *p; s++, p++)
      ;
    if (p > pattern && *p == '\0')
      return c - source;
  }

  return -1;
}

#define NUMBER   '0'  /* signal that a number was found */
#define VARIABLE '1'  /* signal that a variable (a-z) was found */

/* getop:  get next operator or numeric operand */
int getop(char *s)
{
    char *p = s;
    int c;
    static int buf = EOF;

    c = buf != EOF ? buf : getchar();
    buf = EOF;

    while (c == ' ' || c == '\t')
        c = getchar();

    *p     = c;
    *(++p) = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        if (c >= 'a' && c <= 'z')
            return VARIABLE; /* variable */
        else
            return c;        /* not a number */
    }
    p = s;
    if (c == '-') {
        buf = getchar();     /* look at the next char */
        if (!isdigit(buf) && buf != '.')
            return c;        /* the operator - */
        else
            *(++p) = c = buf;
    }
    if (isdigit(c))          /* collect integer part */
        while (isdigit(*(++p) = c = getchar()))
            ;
    if (c == '.')            /* collect fraction part */
        while (isdigit(*(++p) = c = getchar()))
            ;
    *p = '\0';
    if (c != EOF)
        buf = c;

    return NUMBER;
}
