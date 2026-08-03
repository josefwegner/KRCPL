#include <stdio.h>

/* Exercise 3-2. Write the function escape(s, t) and unescape(s, t). */

#define MAXLINE 1000 /* maximum input line size */
#define ESCAPE 0
#define UNESCAPE 1

int kr_getline(char line[], int limit);
int escape(char source[], char target[], int tlen);
int unescape(char source[], char target[], int tlen);

int main(int argc, char **argv)
{
    int len, operation;
    char line[MAXLINE], buffer[MAXLINE];

    operation = ESCAPE;
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'u')
        operation = UNESCAPE;

    while ((len = kr_getline(line, MAXLINE)) > 0) {
        if (operation == ESCAPE)
            escape(line, buffer, MAXLINE);
        else
            unescape(line, buffer, MAXLINE);
        printf("%s", buffer);
    }

    return 0;
}

/* kr_getline: read a line into s, return length */
int kr_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* escape: replace returns, tabs, backspace and such with visible
           escape sequences */
int escape(char source[], char target[], int tlen)
{
    int i, j;

    for (i = j = 0; source[i] != '\0' && j < tlen - 3; ++i, ++j) {
        switch (source[i]) {
            case '\a':
                target[j++] = '\\';
                target[j] = 'a';
                break;
            case '\b':
                target[j++] = '\\';
                target[j] = 'b';
                break;
            case '\f':
                target[j++] = '\\';
                target[j] = 'f';
                break;
            case '\n':
                target[j++] = '\\';
                target[j] = 'n';
                break;
            case '\r':
                target[j++] = '\\';
                target[j] = 'r';
                break;
            case '\t':
                target[j++] = '\\';
                target[j] = 't';
                break;
            case '\v':
                target[j++] = '\\';
                target[j] = 'v';
                break;
            case '\\':
                target[j++] = '\\';
                target[j]   = '\\';
                break;
            default:
                target[j] = source[i];
                break;
        }
    }
    target[j] = '\0';

    return j;
}

/* unscape: replace visible escape sequences with returns, tabs, ... */
int unescape(char source[], char target[], int tlen)
{
    int i, j;

    for (i = j = 0; (source[i] != '\0') && (j < tlen - 2); ++i, ++j) {
        switch (source[i]) {
            case '\\':
                if (source[i + 1] != '\0') {
                    switch (source[i + 1]) {
                        case 'a':
                            target[j] = '\a';
                            break;
                        case 'b':
                            target[j] = '\b';
                            break;
                        case 'f':
                            target[j] = '\f';
                            break;
                        case 'n':
                            target[j] = '\n';
                            break;
                        case 'r':
                            target[j] = '\r';
                            break;
                        case 't':
                            target[j] = '\t';
                            break;
                        case 'v':
                            target[j] = '\v';
                            break;
                        case '\\':
                            target[j] = '\\';
                            break;
                        default:
                            target[j++] = '\\';
                            target[j] = source[i + 1];
                            break;
                    }
                    ++i;
                } else {
                   target[j] = source[i];
                }
                break;
            default:
                target[j] = source[i];
                break;
        }
    }
    target[j] = '\0';

    return j;
}
