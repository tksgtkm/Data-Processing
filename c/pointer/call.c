#include <stdio.h>

void int_count(int *count_ptr) {
  // count_ptrはcountのアドレスにある値を受け取り、++で+1した値を出力する
  ++(*count_ptr);
  printf("Count %d\n", *count_ptr);
}

int main() {
  int count = 0;
  while (count < 10)
    int_count(&count); // countのアドレスを渡す

  return 0;
}
