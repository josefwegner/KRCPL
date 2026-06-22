#include <stdio.h>

/* Exercise 4-1. Write the function strrindex(s,t). */

int strrindex(char source[], char target[]);

int main()
{
  char s[] = "Hello, world!";
  char t1[] = "o";
  char t2[] = "ll";
  char t3[] = "wer";

  printf("%s\n", s);
  printf("Right index of %s is %d.\n", t1, strrindex(s, t1));
  printf("Right index of %s is %d.\n", t2, strrindex(s, t2));
  printf("Right index of %s is %d.\n", t3, strrindex(s, t3));
  return 0;
}

/* strrindex: return right index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  /*
   Either:
   - get the length and iterate back to front
   - reverse the strings
   - iterate the complete list and take the last entry

   I guess the last would be fastest as we only need to traverse the
   list once. Reversing the strings or getting its length would traverse
   it once and then until the first match.
   */
  int i, j, k, n;
  n = -1;
  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
       ;
    if (t[k] == '\0')
      n = i;
  }

  return n;
}
