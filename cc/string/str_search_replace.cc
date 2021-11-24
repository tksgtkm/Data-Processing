#include <iostream>
#include <cstring>

/*
strが指す文字列の中でoldsubstrと最初に一致するものをnewsubstrに置換する。
これはstrが指す文字列がこの関数によって変更されることを意味する。

結果として作られる文字列の最大の長さはmaxlenで指定する。
この値は配列のオーバーランを防ぐためにstrを保存する配列の大きさより
小さくなければならない。
この関数は置換が行われたらtrueを返し、そうでなければfalseを返す
*/
bool search_and_replace(char *str, int maxlen, const char *oldsubstr, const char *newsubstr) {
  if (!*oldsubstr)
    return false;

  /*
  次に、結果として作られる文字列が、maxlenで指定される許容最大の文字数と
  等しいか小さいかをチェックする。
  最大文字数を超えた場合は、関数はfalseを返して終了する。
  */
  int len = strlen(str) - strlen(oldsubstr) + strlen(newsubstr);
  if (len > maxlen)
    return false;

  // 文字列の中に指定した部分文字列があるか調べる
  char *p = strstr(str, oldsubstr);
  // 文字列が見つかったら、新しい文字列と置き換える
  if (p) {
    /*
    最初に、新しい部分文字列を古い文字列と置き換えできるように、
    memmove()を使って文字列の残りの部分を移動する。
    */
    memmove(p+strlen(newsubstr), p+strlen(oldsubstr), strlen(p)-strlen(oldsubstr)+1);

    strncpy(p, newsubstr, strlen(newsubstr));

    return true;
  }

  return false;
}

int main() {
  char str[80] = "alpha beta gamma alpha beta gamma";
  std::cout << "もとの文字列: " << str << "\n\n";

  while (search_and_replace(str, 79, "alpha", "epsilon"))
    std::cout << "置換後: " << str << std::endl;

  while (search_and_replace(str, 79, "gamma", "zeta"))
    std::cout << "置換後: " << str << std::endl;

  while (search_and_replace(str, 79, "beta", ""))
    std::cout << "置換後: " << str << std::endl;

  return 0;
}
