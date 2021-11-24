#include <iostream>
#include <cstring>

int main() {

  // 文に切り分けるためのデリミタを作成する
  char delims[] = ".,?;! "; // 末尾に半角スペースもデリミタとして追加

  char str[] = "I like apples, pears, and grapes. Do you?";

  char *tok;

  // トークンに切り分ける文字列を渡して最初のトークンを得る
  tok = strtok(str, delims);

  // 残りのすべてのトークンを得る
  while(tok) {
    std::cout << tok << std::endl;
    // 以降のstrtok()の呼び出しでは最初の引数にnullptrを指定する
    tok = strtok(nullptr, delims);
  }

  // 次に文字列の中のキーと値のペアの中のキーと値をstrtok()を使って取り出す
  char kvpairs[] = "count=10, name=\"Tom Jones, jr.\", max=100, min=0.01";

  // キーと値のペアのためのデリミタのリストを作成する
  char kvdelims[] = " =,";

  // 最初のキーを得る
  tok = strtok(kvpairs, kvdelims);

  // 残りのすべてのトークンを得る
  while(tok) {
    std::cout << "キー: " << tok << " ";

    /*
    値を得る
    最初にキーが名前である場合、値はくオーテーションで囲まれた文字列である。
    */
    if (!strcmp("name", tok)) {
      /*
      以下の関数呼び出しでデリミタはダブルクオーテーション(")だけである。
      これで任意の文字を含むダブルクオーテーションで囲まれた文字列を取り出すことができる。
      */
      tok = strtok(nullptr, "\"");
    } else {
      // そうでなければ、単純な値を取り出す
      tok = strtok(nullptr, kvdelims);
    }

    std::cout << "値は: " << tok << std::endl;

    // 次のキーを取り出す
    tok = strtok(nullptr, kvdelims);
  }

  return 0;
}
