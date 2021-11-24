#include <iostream>
#include <cctype>

int main() {
  const char *str = "I have 30 apples and 12 pears. Do you have any?";
  int letters = 0, spaces = 0, punct = 0, digits = 0;

  std::cout << str << std::endl;

  while (*str) {
    if (isalpha(*str))
      ++letters;
    else if (isspace(*str))
      ++spaces;
    else if (ispunct(*str))
      ++punct;
    else if (isdigit(*str))
      ++digits;
    ++str;
  }

  std::cout << "アルファベット文字（Letter）: " << letters << std::endl;
  std::cout << "数値の文字（Digit）: " << digits << std::endl;
  std::cout << "スペース: " << spaces << std::endl;
  std::cout << "句読点: " << punct << std::endl;

  return 0;
}
