#include <stdio.h>

/* Exercise 1-9. Replace multiple blanks with one blank */

int main()
{
    int c, isBlank;

    isBlank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!isBlank) {
                putchar(c);
                isBlank = 1;
            }
            /* else ignore following blanks */
        } else {
            putchar(c);
            isBlank = 0;
        }
    }
}
