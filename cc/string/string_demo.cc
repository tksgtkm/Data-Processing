#include <iostream>
#include <string>

int main() {
  std::string str1("Alpha");
  std::string str2("Beta");
  std::string str3("Gamma");
  std::string str4;

  std::cout << "もとのstringは:¥n";
  std::cout << " str1: " << str1 << std::endl;
  std::cout << " str2: " << str2 << std::endl;
  std::cout << " str3: " << str3 << "\n\n";

  // stringの最大の長さを出力する
  std::cout << "stringの最大の長さは: " << str1.max_size() << "\n\n";

  // str1のサイズを出力する
  std::cout << "str1には " << str1.size() << " 文字が含まれる。\n";

  // str1の容量を出力する
  std::cout << "str1の容量は: " << str1.capacity() << "\n\n";

  // インデックス演算子を使って、stringの中の
  // 文字を1個ずつ出力する
  for (unsigned i = 0;  i < str1.size(); ++i)
    std::cout << "str1[i]: " << str1[i] << std::endl;
  std::cout << std::endl;

  // stringに別のstringを代入する
  str4 = str1;
  std::cout << "str1を代入したあとのstr4: " << str4 << "\n\n";

  // 二つのstringを結合する
  str4 = str1 + str3;
  std::cout << "st1+str3を代入したあとのstr4: " << str4 << "\n\n";

  // stringに別のstringを挿入する
  str4.insert(5, str2);
  std::cout << "str2を挿入したあとのstr4: " << str4 << "\n\n";

  // 部分文字列を取得する
  str4 = str4.substr(5, 4);
  std::cout << "str4.substr(5, 3)を代入したあとのstr4 : "
     << str4 << "\n\n";

  // 2個のstringを比較する
  std::cout << "stringを比較する\n";
  if (str3 > str1)
    std::cout << "str3 > str1\n";
  if (str3 == str1+str2)
    std::cout << "str3 == str1+str2\n";
  if (str1 <= str2)
    std::cout << "str1 <= str2\n\n";

  // 他のstringオブジェクトを使ってstringオブジェクトを作成する
  std::cout << "str1の内容を使ってstr5を初期化する\n";
  std::string str5(str1);
  std::cout << "str5: " << str5 << "\n\n";

  // str4を削除する
  std::cout << "str4を削除する\n";
  str4.erase();
  if (str4.empty())
    std::cout << "str4は現在は空¥n";
  std::cout << "str4のサイズと容量は " << str4.size() << " "
     << str4.capacity() << "\n\n";

  // push_back()を使ってstr4に文字列を追加する
  for (char ch = 'A'; ch <= 'Z'; ++ch)
    str4.push_back(ch);

  std::cout << "push_back()を呼び出したあとのstr4: " << str4 << std::endl;
  std::cout << "現在のstr4のサイズと容量 " << str4.size() << " "
    << str4.capacity() << "\n\n";

  // str4の容量を128にする
  std::cout << "str4の容量を128に設定する\n";
  str4.reserve(128);
  std::cout << "現在のstr4の容量: " << str4.capacity() << "\n\n";

  // cinから文字列を入力する
  std::cout << "文字列を入力してください: ";
  std::cin >> str1;
  std::cout << "入力された文字列: " << str1 << "\n\n";

  return 0;
}
