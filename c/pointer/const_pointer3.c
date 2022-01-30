#include <stdio.h>
// 定数へのポインタへ対して、値を変更するための間接参照はできない
// ただし、ポインタ自身の値を変えることはできる
int main() {
  int i = 42;
  int *ip = &i;
  const int *cp = &i;

  for (int j=0; j<10; ++j) {
    i++;
    printf("i == %d, *ip == %d, *cp == %d\n",i, *ip, *cp);
  }

  return 0;
}
