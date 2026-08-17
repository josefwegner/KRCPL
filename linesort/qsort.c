#include <string.h>

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

