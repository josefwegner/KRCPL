#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myitoa(int, char []);

int main(void)
{
   char s[10];

   myitoa(-1230, s);
   printf("Result: %s\n", s);

   return EXIT_SUCCESS;
}

/* myitoa: recursively convert n to charactes in s */
void myitoa(int n, char s[])
{
   int sign;
   void myitoaloop(int, int, char [], int);

   if (n == 0) {           /* special handling for 0 */
      s[0] = '0';
      s[1] = '\0';
      return;
   }

   if ((sign = n) < 0)        /* record sign */
      n = -n;                 /* make n positive */

   myitoaloop(n, 0, s, sign);
}

void myitoaloop(int n, int i, char s[], int sign) {
   void reverse(char []);

   if (n > 0) {
      s[i++] = n % 10 + '0';  /* get next digit */
      myitoaloop(n / 10, i, s, sign);
   } else {
      if (sign < 0)
         s[i++] = '-';
      s[i] = '\0';
      reverse(s);
   }
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

