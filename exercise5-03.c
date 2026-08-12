#include <stdio.h>
#include <stdlib.h>

void kr_strcat(char [], char []);

int main(void)
{
    char s[15] = "Hello, ",  t[] = "world!\n";

    kr_strcat(s, t);
    printf("%s", s);

    return EXIT_SUCCESS;
}

/* kr_strcat:  concatenate t to end of s; s must be big enough */
void kr_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')    /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0')    /* copy t */
        ;
}
