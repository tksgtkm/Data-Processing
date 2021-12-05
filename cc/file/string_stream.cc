#include <iostream>
#include <sstream>

int main() {
  char ch;
  std::ostringstream strout;

  strout << 10 << " " << -20 << " " << 30.2 << "\n";
  strout << "This is a test.";

  std::cout << strout.str() << std::endl;

  std::istringstream strin(strout.str());

  do {
    ch = strin.get();
    if (!strin.eof())
      std::cout << ch;
  } while (!strin.eof());
  std::cout << std::endl;

  std::stringstream strinout;

  strinout << 10 << " + " << 12 << " is " << 10+12 << std::endl;

  do {
    ch = strinout.get();
    if (!strinout.eof())
      std::cout << ch;
  } while (!strinout.eof());
  std::cout << std::endl;

  strinout.clear();

  do {
    ch = strinout.get();
    if (!strinout.eof())
      std::cout << ch;
  } while (!strinout.eof());
}
