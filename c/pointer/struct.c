#include <stdio.h>

struct data { // sizeof 11
  int i; // sizeof 4
  double d; // sizeof 8
  char c; // sizeof 1
};

int main() {
  struct data data;
  printf("sizeof(data) == %zu\n", sizeof data);
  printf("size of components == %zu\n", sizeof data.c + sizeof data.i + sizeof data.d);

  printf("data at %p\n", (void *)&data);
  printf("data.c at %p\n", (void *)&data.c);
  printf("data.i at %p\n", (void *)&data.i);
  printf("data.d at %p\n", (void *)&data.d);

  return 0;
}
