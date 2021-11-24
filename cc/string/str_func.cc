#include <iostream>
#include <cstring>

int main() {
  char strA[7] = "Up";
  char strB[5] = "Down";
  char strC[5] = "Left";
  char strD[6] = "Right";
  std::cout << "strA: " << strA << std::endl;
  std::cout << "strB: " << strB << std::endl;
  std::cout << "strC: " << strC << std::endl;
  std::cout << "strD: " << strD << "\n\n";

  std::cout << "strAの長さは: " << strlen(strA) << std::endl;

  strcat(strA, strB);
  std::cout << "連結後のstrA: " << strA << std::endl;
  std::cout << "現在のstrAの長さ: " << strlen(strA) << std::endl;

  // strCをstrBにコピーする
  strcpy(strB, strC);
  std::cout << "現在のstrBの内容: " << strB << std::endl;

  // 文字列を比較する
  if (!strcmp(strB, strC))
    std::cout << "strBはstrCと同じ\n";

  int result = strcmp(strC, strD);
  if (!result)
    std::cout << "strCはstrDと同じ\n";
  else if (result < 0)
    std::cout << "strCはstrDより小さい\n";
  else if (result > 0)
    std::cout << "strCはstrDより大きい\n";

  return 0;
}
