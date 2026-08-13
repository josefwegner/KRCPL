#include <stdio.h>
#include <stdlib.h>

int strend(char *, char *);

int main(void)
{
    char s[] = "Hello", t[] = "llo", v[] = "foo", w[] = "ello", x[] = "Hello", y[] = "xello", z[] = "";

    printf("strend(\"%s\", \"%s\") = %d\n", s, t, strend(s, t));
    printf("strend(\"%s\", \"%s\") = %d\n", s, v, strend(s, v));
    printf("strend(\"%s\", \"%s\") = %d\n", s, w, strend(s, w));
    printf("strend(\"%s\", \"%s\") = %d\n", s, x, strend(s, x));
    printf("strend(\"%s\", \"%s\") = %d\n", s, y, strend(s, y));
    printf("strend(\"%s\", \"%s\") = %d\n", t, s, strend(t, s));
    printf("strend(\"%s\", \"%s\") = %d\n", s, z, strend(s, z));
    printf("strend(\"%s\", \"%s\") = %d\n", z, s, strend(z, s));
    printf("strend(\"%s\", \"%s\") = %d\n", z, z, strend(z, z));

    return EXIT_SUCCESS;
}

int strend(char *s, char *t) {
    char *sp = s, *tp = t;

    if (s == NULL || t == NULL)
        return 0;

    while (*sp) // search end of string; pointer points to '\0'
        sp++;
    while (*tp) // same
        tp++;

    while(sp > s && tp > t && *--sp == *--tp)
    	;      // decrement pointer before reading, moves the pointer
               // to last char and then start comparing

return (tp == t && (*tp == '\0' || *sp == *tp));
}
