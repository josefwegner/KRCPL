#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line size */

/* Exercise 2-4. Alternate version squeeze(s1, s2). */

void squeeze(char *s1, char *s2);
void test_squeeze(char *s1, char *s2);


int main(void)
{
    test_squeeze("ABCDEF", "A");
    test_squeeze("ABCDEF", "AF");
    test_squeeze("ABCDEF", "a");
    test_squeeze("AABBCC", "ABC");
    test_squeeze("BAAAAC", "ADE");

    return 0;
}

void squeeze(char *s1, char *s2)
{
    int i, j, k, found;

    for (i = j = 0; s1[i] != '\0'; ++i) {
        found = 0;
        for (k = 0; s2[k] != '\0'; ++k) {
            if (s1[i] == s2[k]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

void test_squeeze(char *s1, char *s2)
{
    char s[MAXLINE];

    strncpy(s, s1, MAXLINE);
    s[MAXLINE - 1] = '\0';
    squeeze(s, s2);
    printf("Remove all chars in '%s' from '%s': %s\n", s2, s1, s);
}
