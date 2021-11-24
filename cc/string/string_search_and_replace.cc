#include <iostream>
#include <string>

bool search_and_replace(std::string &str, const std::string &oldsubstr, const std::string &newsubstr) {
  std::string::size_type startidx;
  startidx = str.find(oldsubstr);
  if (startidx != std::string::npos) {
    str.replace(startidx, oldsubstr.size(), newsubstr);
    return true;
  }
  return false;
}

int main() {
  std::string str = "This is a test. So is this.";
  std::cout << "元の文字列: " << str << "\n\n";

  while(search_and_replace(str, "is", "was"))
    std::cout << str << std::endl;
  std::cout << std::endl;

  std::string oldstr("So");
  std::string newstr("Sp too");
  search_and_replace(str, oldstr, newstr);
  std::cout << str << std::endl;

  return 0;
}
