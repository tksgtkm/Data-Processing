#include <iostream>
#include <string>

// tokenizerクラスはstringをトークンに切り分けるために使う。
// トークンに切り分けるstringをコンストラクタに渡す。
// 次のトークンを取得するために、デリミタを含むstringを渡して
// get_token( )を呼び出す。
class Tokenizer {
  std::string s;
  std::string::size_type startidx;
  std::string::size_type endidx;

public:
  Tokenizer(const std::string &str) {
    s = str;
    startidx = 0;
  }

  // stringから1個のトークンを返す
  std::string get_token(const std::string &delims);
};

// stringから1個のトークンを返す。
// トークンがそれ以上見つからない場合は空のstringを返す。
// デリミタはdelimsで渡す。
std::string Tokenizer::get_token(const std::string &delims) {

  // トークンがそれ以上見つからない場合は空のstringを返す。
  if (startidx == std::string::npos)
    return std::string("");

  // startidxから初めて、次のデリミタを探す
  endidx = s.find_first_of(delims, startidx);

  // トークンを含むstringを作成する
  std::string tok(s.substr(startidx, endidx-startidx));

  // 次のトークンの先頭を探す。
  // これはデリミタでない文字である。
  startidx = s.find_first_not_of(delims, endidx);

  // 次のトークンを返す
  return tok;
}

int main() {

  std::string strA("I have four, five, six tokens. ");
  std::string strB("I might have more tokens!¥nDo You?");

  std::string delimiters(" ,.!?\n");

  std::string token;

  Tokenizer tokA(strA);
  Tokenizer tokB(strB);

  token = tokA.get_token(delimiters);
  while (token != "") {
    std::cout << token << std::endl;
    token = tokA.get_token(delimiters);
  }
  std::cout << std::endl;

  token = tokB.get_token(delimiters);
  while (token != "") {
    std::cout << token << std::endl;
    token = tokB.get_token(delimiters);
  }
  return 0;
}
