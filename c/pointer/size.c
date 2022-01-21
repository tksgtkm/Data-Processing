#include <stdio.h>

char c[2];

int main() {
  c[0] = 'a';
  c[1] = 'b';
  c[2] = 'c';
  printf("%zu %zu\n", sizeof(char), sizeof c);

  return 0;
}
