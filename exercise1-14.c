#include <stdio.h>

/* Exercise 1-14. Create a histogram of characters in the output */

#define NUMBER_OF_CHARS 26
#define NUMBER_OF_DIGITS 10

int main()
{
    int c, i, j;
    int characters[NUMBER_OF_CHARS + NUMBER_OF_DIGITS];

    for (i = 0; i < NUMBER_OF_CHARS + NUMBER_OF_DIGITS; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++characters[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            ++characters[c - 'A'];
        } else if (c >= '0' && c <= '9') {
            ++characters[c - '0' + NUMBER_OF_CHARS];
        }
    }

    printf("Histogram of characters\n");
    for (i = 0; i < NUMBER_OF_CHARS; ++i) {
        printf("%c: ", ('a' + i));
        for (j = 0; j < characters[i]; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
    for (i = 0; i < NUMBER_OF_DIGITS; ++i) {
        printf("%c: ", ('0' + i));
        for (j = 0; j < characters[i + NUMBER_OF_CHARS]; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
}
