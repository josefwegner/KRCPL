#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char []);

int main(void)
{
   char test1[] = "abcde";
   char test2[] = "123456";

   reverse(test1);
   printf("reverse(abcde) = %s\n", test1);
   reverse(test2);
   printf("reverse(123456) = %s\n", test2);

   return EXIT_SUCCESS;
}


/* reverse: reverse string s in place */
void reverse(char s[])
{
   void reverse_rec(char [], int, int);
   
   reverse_rec(s, 0, strlen(s) - 1);
}

void reverse_rec(char s[], int left, int right) {
   int c;

   if (left >= right)
      return;

   c = s[left];
   s[left] = s[right];
   s[right] = c;
   reverse_rec(s, left + 1, right - 1);
}
