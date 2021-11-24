#include <iostream>
#include <cctype>

// 大文字/小文字を無視した単純な文字列比較関数
int strcmp_ign_case(const char *str1, const char *str2) {
  while (*str1 && *str2) {
    if (tolower(*str1) != tolower(*str2))
      break;
    ++str1;
    ++str2;
  }
  return tolower(*str1) - tolower(*str2);
}

void showresult(const char *str1, const char *str2, int result) {
  std::cout << str1 << " は ";

  if (!result)
    std::cout << " 次の文字列と等しい ";
  else if (result < 0)
    std::cout << " 次の文字列より小さい ";
  else
    std::cout << " 次の文字列より大きい ";

  std::cout << str2 << std::endl;
}

int main() {
  char strA[]= "tesT";
  char strB[] = "Test";
  char strC[] = "testing";
  char strD[] = "Tea";

  int result;

  std::cout << "strA: " << strA << std::endl;
  std::cout << "strB: " << strB << std::endl;
  std::cout << "strC: " << strC << std::endl;
  std::cout << "strD: " << strD << "\n\n";

  // 大文字/小文字を無視して文字列を比較する
  result = strcmp_ign_case(strA, strB);
  showresult(strA, strB, result);

  result = strcmp_ign_case(strA, strC);
  showresult(strA, strC, result);

  result = strcmp_ign_case(strA, strD);
  showresult(strA, strD, result);

  result = strcmp_ign_case(strD, strA);
  showresult(strD, strA, result);
  return 0;
}
