#include <stdio.h>
#include <time.h>

#define NUM_ELEMENTS 10000
#define LOOPS 1000000

/* Exercise 3-1. Rewrite binsearch to only use one comparison
                 inside the loop. */

int binsearch(int x, int v[], int n);
int binsearch_fast(int x, int v[], int n);

int main(void)
{
    int i;
    int v[NUM_ELEMENTS];
    long start, end;

    for (i = 0; i < NUM_ELEMENTS; ++i) {
        v[i] = i;
    }

    start = clock();
    for (i = 0; i < LOOPS; ++i)
        binsearch(NUM_ELEMENTS - 1, v, NUM_ELEMENTS);
    end = clock();

    printf("binsearch took %ld clock cycles\n", end - start);

    start = clock();
    for (i = 0; i < LOOPS; ++i)
        binsearch_fast(NUM_ELEMENTS - 1, v, NUM_ELEMENTS);
    end = clock();

    printf("binsearch_fast took %ld clock cycles\n", end - start);

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }

    return -1;  /* no match */
}

/* binsearch_fast: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_fast(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[low - 1])
        return low -1;

    return -1;  /* no match */
}
