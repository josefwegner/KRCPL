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
void kr_strcat(char *s, char *t)
{
    while (*s)    /* find end of s */
        s++;
    while ((*s++ = *t++))    /* copy t */
        ;
}
