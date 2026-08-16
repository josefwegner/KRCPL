#include <stdio.h>
#include <stdlib.h>

#define swap(t, x, y) do { t *px = &(x); t *py = &(y); t tmp = *px; *px = *py; *py = tmp; } while (0)

int main(void) {
  int a[] = {1,2,3,4};
  int i = 0, j = 1;

  swap(int, a[i++], a[j++]);    /* safe: &(b[i++]) evaluated once each */
  printf("ptr:  i=%d j=%d a[0]=%d a[1]=%d\n", i, j, a[0], a[1]);

  return EXIT_SUCCESS;
}
