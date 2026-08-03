#include <stdio.h>
#include <ctype.h>

/* Exercise 3-3. Write the function expand(s1,s2). */

#define MAXLINE 1000 /* maximum input line size */
int kr_getline(char line[], int limit);
int expand(char source[], char target[], int maxlen);

int main(int argc, char **argv)
{
    int len;
    char line[MAXLINE], buffer[MAXLINE];

    while ((len = kr_getline(line, MAXLINE)) > 0) {
        expand(line, buffer, MAXLINE);
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

/* expand: Expand shorthand notations like a-z in the string source into the
 *         equivalent complete list abc...xyz. Including a-b-c, a-z0-9 and
 *         -a-z.
 */
int expand(char src[], char dest[], int maxlen)
{
    int i,j;
    char c;

    for (i = j = 0; src[i] != '\0' && j < maxlen -1; ++i) {
        if (isalnum(src[i]) && src[i + 1] == '-' && src[i] < src[i + 2]) {
            c = src[i];
            while (c <= src[i + 2] && j < maxlen-1) {
                if (isalnum(c))
                    dest[j++] = c;
                c++;
            }
            i += 2;
        } else {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';

    return j;
}
