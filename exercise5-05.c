#include <stdio.h>
#include <stdlib.h>

char *kr_strncpy(char [], const char *, size_t);
char *kr_strncat(char *, const char [], size_t);
int kr_strncmp(const char [], const char [], size_t);

int main(void)
{
    char t[20] = "Hello", s[] = "Hello, world!", u[] = ", world!", w[] = "Hello", *x;

    x = kr_strncpy(t, s, 14);

    printf("%s\n", t);
    printf("%s\n", x);

    kr_strncpy(t, w, 20);

    printf("strncat: %s\n", kr_strncat(t, u, 8));

    printf("strncmp(\"ABC\", \"ABC\", 3) = %d\n", kr_strncmp("ABC", "ABC", 3));
    printf("strncmp(\"ABC\", \"ABC\", 4) = %d\n", kr_strncmp("ABC", "ABC", 4));
    printf("strncmp(\"ABC\",  \"AB\", 3) = %d\n", kr_strncmp("ABC",  "AB", 3));
    printf("strncmp(\"ABC\",  \"AB\", 2) = %d\n", kr_strncmp("ABC",  "AB", 2));
    printf("strncmp(\"ABC\", \"ABZ\", 4) = %d\n", kr_strncmp("ABC", "ABZ", 4));

    return EXIT_SUCCESS;
}

char *kr_strncpy(char t[], const char *s, size_t n) {
    size_t i;

    for (i = 0; i < n && *s != '\0'; ++i)
        t[i] = *s++;

    for (; i < n; ++i)
        t[i] = '\0';

    return t;
}

char *kr_strncat(char *t, const char s[], size_t n) {
    char *tp = t;
    size_t i;

    while (*tp != '\0') // find end of t, pointer to '\0'
        tp++;

    for (i = 0; i < n && s[i] != '\0'; ++i)
        *tp++ = s[i];

    *tp = '\0'; // add null byte

    return t;
}

int kr_strncmp(const char s1[], const char s2[], size_t n) {
    size_t i;

    for (i = 0; i < n && s1[i] == s2[i]; i++)
        if (s1[i] == '\0' || i == n - 1)
            return 0;

    return (unsigned char) s1[i] - (unsigned char) s2[i];
}

