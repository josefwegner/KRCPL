#include <stdio.h>

int htoi(char *s);
void test_htoi(char *);

/* Exercise 2-3. Write the function htoi(s) that converts
                 a number in hexadecimal format into an int */

int main()
{
    test_htoi("0xDEADBEEF");
    test_htoi("0XdeadBEEF");
    test_htoi("DeadBeef");
    test_htoi("1");
    test_htoi("a");
    test_htoi("0A");
    test_htoi("10");
    test_htoi("1f");
    test_htoi("100");
    test_htoi("0xFF");
    test_htoi(  "7FFFffff");
    test_htoi("0x7FFFffff");
    test_htoi(  "7FFFFffffF");
    test_htoi("0x7FFFFffffF");
    test_htoi("0x80000000");
    test_htoi("0xFFFFffff");
    test_htoi("0x-1");

    return 0;
}

int htoi(char *s)
{
    int i, n, start;
    char c;

    n = start = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        start = 2;

    for (i = start; (c = s[i]) != '\0' && i < (8 + start); ++i)
        if (c >= '0' && c <= '9')
            n = n * 16 + (c - '0');
        else if (c >= 'a' && c <= 'f')
            n = n * 16 + (c - 'a') + 10;
        else if (c >= 'A' && c <= 'F')
            n = n * 16 + (c - 'A') + 10;
        else {
            printf("string is not a valid hexadecimal representation of an int\n");
            n = 0;
            break;
        }

    return n;
}

void test_htoi(char *s)
{
    printf("%s = %d\n", s, htoi(s));
}

