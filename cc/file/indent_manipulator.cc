#include <iostream>
#include <string>
#include <sstream>

class Indent {
  int len;
public: Indent(int i) {
  len = i;
  }
  friend std::ostream &operator<<(std::ostream &stream, Indent ndt);
};

std::ostream &operator<<(std::ostream &stream, Indent ndt) {
  for (int i=0; i<ndt.len; ++i)
    stream << " ";

  return stream;
}

class Skipchar {
  char ch;
public: Skipchar(char c) {
  ch = c;
  }
  friend std::istream &operator>>(std::istream &stream, Skipchar sc);
};

std::istream &operator>>(std::istream &stream, Skipchar sc) {
  char ch;
  do {
    ch = stream.get();
  } while (!stream.eof() && ch == sc.ch);

  if (!stream.eof())
    stream.unget();

  return stream;
}

int main() {
  std::string str;

  // indentを使ってインデントした出力を行う。.
  std::cout << Indent(9) << "9だけインデントしたもの。\n"
      << Indent(9) << "これもそう。\n" << Indent(18)
      << "これは18インデントとしたもの。\n\n";

  // skipcharを使って先行するゼロを無視する。
  std::cout << "文字列を入力してください: ";
  std::cin >> Skipchar('0') >> str;
  std::cout << "先行するゼロをスキップしました。strの内容: " << str << "\n\n";

  std::ostringstream ostrstrm;
  ostrstrm << Indent(5) << 128;
  std::cout << "ostrstrmの内容:¥n" << ostrstrm.str() << std::endl;

  return 0;
}
