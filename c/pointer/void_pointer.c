#include <stdio.h>

/*
voidへのポインタ
汎用ポインタとしてどのようなデータ型でも指すことができる
・voidへのポインタはcharへのポインタと同じ表現とメモリ上の並びを持つ。
・voidへのポインタは他のポインタと等しくなることはない。
　※nullの場合は等しい
*/
int main() {
  char c = 1;
  printf("%d %p\n", c, (void *)&c);
  int i = 2;
  printf("%d %p\n", i, (void *)&i);
  double d = 3.0;
  printf("%f %p\n", d, (void *)&d);

  return 0;
}
