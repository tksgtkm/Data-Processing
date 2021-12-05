#include <iostream>
#include <fstream>

int main() {
  char ch;
  char str[256];

  std::ofstream fout("test.sst");
  if (!fout) {
    std::cout << "出力用のファイルを開けません。\n";
    return 1;
  }

  fout << "This is a line of text.\n";
  fout << "This is another line of text.\n";
  fout << "This is the last line of text.\n";
  fout.close();
  if (!fout.good()) {
    std::cout << "ファイルへの書き込みでエラーが発生しました。\n";
    return 1;
  }

  std::ifstream fin("test.sst", std::ios::in);
  if (!fin) {
    std::cout << "入力用のファイルを開けません\n";
    return 1;
  }
  std::cout << "get()を使う：\n";

  std::cout << "最初の3文字：";
  for (int i=0; i<3; ++i) {
    fin.get(ch);
    std::cout << ch;
  }
  std::cout << std::endl;

  fin.get(str, 255);
  std::cout << "最初の行の残りの文字列：";
  std::cout << str << std::endl;

  fin.get(ch);
  std::cout << "\n次に、getline()を使う：\n";

  fin.getline(str, 255);
  std::cout << str << std::endl;
  fin.getline(str, 255);
  std::cout << str;

  fin.close();

  if (!fin.good()) {
    std::cout << "ファイルの読み込みまたはクローズでエラーが発生しました。\n";
    return 1;
  }

  return 0;
}
