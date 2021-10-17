#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[] = "file_list/input.txt";

int main() {
  int  count = 0; // 文字の数
  FILE *in_file;  // 入力データを格納させるファイル

  int ch;         // 文字またはEOFフラグ

  /*fopenはファイルのファイル構造体を指すポインタを返す*/
  in_file = fopen(FILE_NAME, "r");
  if (in_file == NULL) { // エラーの検査
    printf("Cannot open %s\n", FILE_NAME);
    exit(8);
  }

  while (1) {
    // fgetcはファイルから1文字を読み出す
    ch = fgetc(in_file);
    if (ch == EOF)
      break;
    ++count;
  }

  printf("Number of charactes in %s is %d\n", FILE_NAME, count);

  fclose(in_file);

  return 0;
}
