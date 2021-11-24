#include <iostream>
#include <cstring>

int main() {
  const char *url = "HerbSchildt.com";
  const char *url2 = "Apache.org";
  const char *emailaddr = "Herb@HerbSchildt.com";
  const char *tld[] = {".com", ".net", ".org"};
  const char *p;

  // 最初に、urlとurl2に、.com、.net、.orgが含まれるか調べる
  for (int i=0; i<3; i++) {
    p = strstr(url, tld[i]);
    if (p)
      std::cout << url << " はトップレベルドメインがある " << tld[i] << std::endl;
    p = strstr(url2, tld[i]);
    if (p)
      std::cout << url2 << " はトップレベルドメインがある " << tld[i] << std::endl;
  }

  // 特定の文字を検索する
  p = strchr(emailaddr, '@');
  if (p)
    std::cout << "Eメールアドレスのサイト名は " << p+1 << std::endl;

  p = strpbrk(emailaddr, "@.");
  if (p)
    std::cout << "Found " << *p << std::endl;

  return 0;
}
