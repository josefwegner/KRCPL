#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
#define ALLOCSIZE 10000     /* size of available space */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *storage);
void writelines(char *lineptr[], int nlines);
void kr_qsort(char *lineptr[], int left, int right);
 
/* sort input lines */
int main(void)
{
    int nlines;     /* number of input lines read */
    char storage[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, storage)) >= 0) {
        kr_qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000    /* max length of any input line */
int kr_getline(char *,  int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines, char *storage)
{
    int  len, nlines;
    char *p = storage, line[MAXLEN];

    nlines = 0;
    while ((len = kr_getline(line, MAXLEN)) > 0) {
        if (line[len-1] == '\n') {
            len--;
            line[len] = '\0'; /* delete newline and correct len */
        }
        if (nlines >= maxlines || (p - storage) + len >= ALLOCSIZE)
            return -1;
        else {
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len + 1;
        }
    }
    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* kr_getline: get line into s, return length */
int kr_getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';

  return i;
}

/* kr_qsort:  sort v[left]...v[right] into increasing order */
void kr_qsort(char *v[],  int left, int right)
{
    int i, last;
    void kr_swap(char *v[], int i, int j);
 
    if (left >= right)   /* do nothing if array contains */
        return;           /* fewer than two elements */
    kr_swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            kr_swap(v,  ++last, i);
    kr_swap(v, left, last);
    kr_qsort(v, left, last-1);
    kr_qsort(v, last+1, right);
}

/* kr_swap:  interchange v[i] and v[j] */
void kr_swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

