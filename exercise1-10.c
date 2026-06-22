#include <stdio.h>

/* Exercise 1-10. Replace tab with \t, backspace with \b and \ with \\ */

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':  printf("\\t"); break;
            case '\b':  printf("\\b"); break;
            case '\\':  printf("\\\\"); break;
            default:
                putchar(c);
        }
   }
}
