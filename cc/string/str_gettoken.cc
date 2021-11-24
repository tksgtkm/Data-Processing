#include <iostream>
#include <cstring>
#include <cctype>

#define MAX_TOK_SIZE 128

// とても単純なカスタム関数gettoken( )。
// トークンは英数字の文字列、数と1文字の句読点で構成されている。
// この関数はとても限定されているが、他の種類のトークンを取得するために
// 改良し拡張する可能性がある基本的なメカニズムを示す。
//
// 最初の呼び出しでは、トークンに切り分ける文字列へのポインタを渡す。
// 以降の呼び出しでは、NULLポインタを渡す。
// この関数は、現在のトークンへのポインタか、
// これ以上のトークンがない場合はNULLポインタを返す。
const char *gettoken(const char *str) {
  static char token[MAX_TOK_SIZE + 1];
  static const char *ptr;
  int count;
  char *tokptr;

  if (str) {
    ptr = str;
  }

  tokptr = token;
  count = 0;

  while(isspace(*ptr))
    ptr++;

  if (isalpha(*ptr)) {
    while(isalpha(*ptr) || isdigit(*ptr)) {
      *tokptr++ = *ptr++;
      ++count;
      if (count == MAX_TOK_SIZE)
        break;
    }
  } else if (isdigit(*ptr)) {
    while(isdigit(*ptr)) {
      *tokptr++ = *ptr++;
      ++count;
      if (count == MAX_TOK_SIZE)
        break;
    }
  } else if (ispunct(*ptr)) {
    *tokptr++ = *ptr++;
  } else {
    return nullptr;
  }

  *tokptr = '\0';

  return token;
}

int main() {
  char sampleA[] = "max=12+3/89;count27 = 19*(min+floor);";
  char sampleB[] = "while(i < max) i = counter * 2;";
  const char *tok;

  tok = gettoken(sampleA);
  std::cout << "トークンに切り分ける文字列: " << sampleA << std::endl;
  while(tok) {
    std::cout << tok << std::endl;
    tok = gettoken(nullptr);
  }
  std::cout << "\n\n";

  tok = gettoken(sampleB);
  std::cout << "トークンに切り分ける文字列: " << sampleB << std::endl;

  while(tok) {
    std::cout << tok << std::endl;
    tok = gettoken(nullptr);
  }
  return 0;
}
