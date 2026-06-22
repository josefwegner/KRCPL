#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Exercise 3-06. Write a version of itoa that accepts three arguments.
   The third argument is a minimum field length. */

void reverse(char s[]);
void myitoa(int n, char s[], unsigned int l);

/* myitoa: convert n to charactes in s */
void myitoa(int n, char s[], unsigned int l)
{
   int i, sign;

   sign = n;                        /* record sign */
   i = 0;
   do {                             /* generate digits in reverse order */
      s[i++] = abs(n % 10) + '0';   /* get next POSITIVE digit */
   } while ((n /= 10) != 0);        /* delete it */
   if (sign < 0)
      s[i++] = '-';
   while (i < l)
      s[i++] = ' ';
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
   char s[32];
   myitoa(INT_MIN, s, 10);
   printf("%s\n", s);
   myitoa(INT_MAX, s, 20);
   printf("%s\n", s);
   myitoa(-1, s, 5);
   printf("%s\n", s);


   return 0;
}
