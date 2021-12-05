#include <iostream>
#include <fstream>

int main() {
  std::ofstream fout("test.dat");

  if (!fout) {
    std::cout << "ファイルが開けません\n";
    return 1;
  }

  fout << 10 << " " << -20 << " " << 30.2 << "\n";
  fout << "This is a test.";

  fout.close();
  if (!fout.good()) {
    std::cout << "ファイルエラーが発生しました";
    return 1;
  }
}
