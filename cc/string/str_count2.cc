#include <iostream>
#include <cctype>

// 語のカウンタの統計を保存する構造体
struct wc {
  int words;
  int spaces;
  int punct;
  int lines;
  wc() {
    words = punct = spaces = lines = 0;
  }
};

/*
文字列の中の語、行、スペースと句読点をカウントし、
wc構造体で結果を返す。
*/
wc wordcount(const char *str) {
  wc data;

  // 文字列がNULLでなければ、少なくとも1行は含まれる
  if (*str)
    ++data.lines;

  while (*str) {
    // 語をチェックする
    if (isalpha(*str)) {
      // 語の先頭が見つかった。そこで、語の最後を探す。
      // it'sのような語の中のアポストロフィーも許容する
      while (isalpha(*str) || *str == '\'') {
        if (*str == '\'')
          ++data.punct;
        ++str;
      }
      data.words++;
    } else {
      // 句読点、スペース（改行を含む）、行数をカウントする
      if (ispunct(*str)) {
        ++data.punct;
      } else if (isspace(*str)) {
        ++data.spaces;
        // 改行のあとに何らかの文字がある場合、
        // 行カウンタをインクリメントする
        if (*str == '\n' && *(str + 1))
          ++data.lines;
      }
      ++str;
    }
  }
  return data;
}

int main() {
  const char *test = "By supplying a string class and also "
                 "supporting null-terminated strings,\nC++ "
                 "offers a rich programming environment for "
                 "string-intensive tasks.\nIt's power programming.";

  std::cout << test << std::endl;

  wc wcd = wordcount(test);
  std::cout << "\n語 (Word): " << wcd.words << std::endl;
  std::cout << "スペース: " << wcd.spaces << std::endl;
  std::cout << "行数: " << wcd.lines << std::endl;
  std::cout << "句読点: " << wcd.punct << std::endl;

  return 0;
}
