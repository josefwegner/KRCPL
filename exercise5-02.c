#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void) {
  int i, n;
  float array[SIZE];

  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
       ;

  for (i = 0; i < n; i++)
       printf("%d: %f\n", i, array[i]);

  return EXIT_SUCCESS;
}

/* getfloat:  get next float from input into *pf */
int getfloat(float *pf)
{
  int c, sign;
  float pow;

  while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);    /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch()) && c != '.') {
            if (c != EOF)
              ungetch(c);
            *pf = 0.0;
            return sign == -1 ? '-' : '+';
        }
    for (*pf = 0; isdigit(c); c = getch())
        *pf = 10 * *pf + (c - '0');
    if (c == '.') {
        c = getch();
        for (pow = 10.0; isdigit(c); c = getch(), pow = pow * 10.0)
            *pf = *pf + (c - '0') / pow;
    }
    *pf *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int  bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
      return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
      if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
          else
                    buf[bufp++] = c;
}

