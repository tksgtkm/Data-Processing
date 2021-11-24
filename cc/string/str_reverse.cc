#include <iostream>
#include <cstring>

void revstr(char *str) {
  int i, j;
  char t;
  for (i=0, j=strlen(str)-1; i<j; ++i, --j) {
    t = str[i];
    str[i] = str[j];
    str[j] = t;
  }
}

int main() {
  char str[] = "abcdefghijklmnopqrstuvwxyz";
  std::cout << "元の文字列: " << str << std::endl;
  revstr(str);
  std::cout << "反転した文字列: " << str << std::endl;
  return 0;
}
