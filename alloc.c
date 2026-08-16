#include <stdio.h>
#include <stdlib.h>

char *alloc(int);
void afree(char *);

int main(void)
{
    char *cp;

    if ((cp = alloc(10))) {
        printf("Allocated 10 chars\n");
        afree(cp);
    }
    else
        printf("Not enough room\n");

    if ((cp = alloc(10000 + 1))) {
        printf("Allocated %d chars\n", 10000 + 1);
        afree(cp);
    }
    else
        printf("Not enough room\n");

    return EXIT_SUCCESS;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

char *alloc(int n)  /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else      /* not enough room */
        return 0;
}

void afree(char *p)  /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
