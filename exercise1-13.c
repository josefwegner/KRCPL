#include <stdio.h>

/* Exercise 1-13. Print a histogram of the lenght of words in its input */

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 19

int main()
{
    int i, j, c, length, max_word_count, state;
    int histogram[MAX_WORD_LENGTH + 1];

    for (i = 0; i < MAX_WORD_LENGTH + 1; ++i) {
        histogram[i] = 0;
    }

    state = OUT;
    length = max_word_count = 0;
    while ((c = getchar())) {
        if (c == ' ' || c == '\n' || c == '\t' || c == EOF) {
            if (state == IN) {
                if (length > MAX_WORD_LENGTH) {
                    if (++histogram[MAX_WORD_LENGTH] > max_word_count) {
                        max_word_count = histogram[MAX_WORD_LENGTH];
                    }
                } else {
                    if (++histogram[length - 1] > max_word_count) {
                        max_word_count = histogram[length - 1];
                    }
                }
                state = OUT;
                length = 0;
            }
        } else {
            state = IN;
            ++length;
        }
        if (c == EOF) {
            break;
        }
    }
    printf("Horizontal histogram\n");
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("%4d: ", i + 1);
        for (j = 0; j < histogram[i]; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
    printf(">%3d: ", MAX_WORD_LENGTH);
    for (j = 0; j < histogram[MAX_WORD_LENGTH]; ++j) {
        putchar('#');
    }
    putchar('\n');

    printf("\nVertical histogram\n");
    for (i = max_word_count; i > 0; --i) {
        for (j = 0; j < MAX_WORD_LENGTH + 1; ++j) {
            if (histogram[j] >= i) {
                printf(" ## ");
            } else {
                printf("    ");
            }
        }
        putchar('\n');
    }
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf(" %2d ", i + 1);
    }
    printf(" >%2d\n", MAX_WORD_LENGTH);
}
