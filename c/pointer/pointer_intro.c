#include <stdio.h>

int main() {
  int thing_var; // 整数型を宣言

  /*
  int *thing_ptr
  int * thing_ptr
  int* thing_ptr
  上記のどの書き方でも良い
  */
  int *thing_ptr; // thing_varを指すポインタを宣言

  thing_var = 2; // 整数2を代入
  printf("Thing %d\n", thing_var);

  /*
  thing_varのアドレスを代入
  ここで*thing_ptrは&thing_varのアドレスを参照するポインタである。
  */
  thing_ptr = &thing_var;
  printf("Thing %p\n", thing_ptr);
  printf("Thing %d\n", *thing_ptr); // 値は入っていない

  /*
  　*(逆参照)により、ポインタそのものではなく、ポイントされているデータを
  　参照することを指定する。
  　ここで*thing_ptrはthing_varのアドレスを参照しているので、
  　間接的にthing_varに3を代入している。
  */
  *thing_ptr = 3;
  printf("Thing %p\n", thing_ptr); // thing_varのアドレス
  printf("Thing %d\n", *thing_ptr); // 3
  printf("Thing_var %d\n", thing_var); // 3

  int thing_other; // 別の整数型を宣言
  thing_other = *thing_ptr; // otherにthing_ptrの値(つまり3)を代入
  printf("Thing_other %d\n", thing_other);

  *thing_ptr = 6;
  printf("Thing_other %d\n", thing_other); // 値は変わらない

  return 0;
}
