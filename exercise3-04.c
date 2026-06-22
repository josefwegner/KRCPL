#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Exercise 3-04. Make itoa work even with -2^(32-1). */

/* Converting -2^31 does not work because there is no positive
   representation of this number on two's complement machines.
   The biggest positive (signed) number would be 2^31-1 */

void reverse(char s[]);
void myitoa(int n, char s[]);

/* myitoa: convert n to charactes in s */
void myitoa(int n, char s[])
{
   int i, sign;

   sign = n;                        /* record sign */
   i = 0;
   do {                             /* generate digits in reverse order */
      s[i++] = abs(n % 10) + '0';   /* get next POSITIVE digit */
   } while ((n /= 10) != 0);        /* delete it */
   if (sign < 0)
      s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
   int c, i, j;

   for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;

   }

}

int main(void)
{
   char s[10];
   myitoa(INT_MIN, s);
   printf("%s\n", s);
   myitoa(INT_MAX, s);
   printf("%s\n", s);

   return 0;
}
