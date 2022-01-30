#include <stdio.h>

void abc(int *a, int *b, int *c) {
  *a += *c;
  *b += *c;
}

void abc_restrict(int *a, int *b, int *restrict c) {
  *a += *c;
  *b += *c;
}

int main() {
  int x, y;

  x = y = 13;
  abc(&x, &y, &x);
  printf("%d %d\n", x, y);

  x = y = 13;
  abc_restrict(&x, &y, &x);
  printf("%d %d\n", x, y);

  return 0;
}
