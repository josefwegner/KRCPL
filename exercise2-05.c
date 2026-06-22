#include <stdio.h>

/* Exercise 2-5. Write the function any(s1, s2). */

int any(char *s1, char *s2);
void test_any(char *s1, char *s2);

int main(void)
{
    test_any("aBcDeF", "AbCdEf");
    test_any("ABCDEF", "F");
    test_any("ABCDEF", "FA");

    return 0;
}

int any(char *s1, char *s2)
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

void test_any(char *s1, char *s2)
{
    int result;

    result = any(s1, s2);
    if (result > -1) {
        printf("Found a character from '%s' in '%s' at position %d.\n", s1, s2, result);
    } else {
        printf("No character from '%s' found in '%s'.\n", s1, s2);
    }
}
