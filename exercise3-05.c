#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Exercise 3-05. Make the function itob. */

void reverse(char s[]);
void itob(int n, char s[], unsigned int base);

/* itob: convert n to charactes in s based on base b */
void itob(int n, char s[], unsigned int base)
{
   int i, sign, tmp;

   /* we only support up to base 26 */
   if (base < 2 || base > 26) {
       return;
   }

   sign = n;                        /* record sign */
   i = 0;
   do {                             /* generate digits in reverse order */
      tmp =abs(n % base);           /* get next POSITIVE digit */
      if (tmp < 10)
        tmp += '0';                 /* less than 10 -> generate digits */
      else
        tmp += 'a' - 10;            /* else generate characters a-z */
      s[i++] = tmp;
   } while ((n /= base) != 0);     /* delete it */
   if (sign < 0 && base == 10)
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
   char s[64];
   itob(INT_MIN, s, 2);
   printf("%s\n", s);
   itob(INT_MIN, s, 8);
   printf("%s\n", s);
   itob(INT_MIN, s, 10);
   printf("%s\n", s);
   itob(INT_MIN, s, 16);
   printf("%s\n", s);

   itob(INT_MAX, s, 2);
   printf("%s\n", s);
   itob(INT_MAX, s, 8);
   printf("%s\n", s);
   itob(INT_MAX, s, 10);
   printf("%s\n", s);
   itob(INT_MAX, s, 16);
   printf("%s\n", s);

   return 0;
}
