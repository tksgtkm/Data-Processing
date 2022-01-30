#include <stdio.h>

int main() {
  int *p = 0;
  int const **q = 0;
  int const i = 42;

  q = (int const **)&p; // int型の定数への多重間接参照
  *q = &i; // iのアドレスをqが参照する

  // pはqが参照している値のアドレスを取得する
  printf("&i == %p, *p == %p\n", (void *)&i, (void *)p);

  // pはqを通してiのアドレスを参照しており、
  // 5を代入すると、iのアドレスの値も変わる
  *p = 5;

  printf("i == %d / %d\n", i, *p);

  return 0;
}
