#include <iostream>
#include <fstream>
#include <string>

int main() {
  int i, n;
  double d;
  std::string str;

  std::ifstream fin("test.dat");

  if (!fin) {
    std::cout << "ファイルを開けません。\n";
    return 1;
  }

  fin >> i;
  fin >> n;
  fin >> d;
  fin >> str;

  fin.close();

  if (!fin.good()) {
    std::cout << "ファイルエラーが発生しました。";
    return 1;
  }

  std::cout << i << " " << n << " " << d << " " << str << "\n";

  return 0;
}
