#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <locale>

format_date_time(std::locale out) {
  const std::time_put<char>& date_writer = std::use_facet <std::time_put<char> >(out);

  return out;
}

std::string date_time_to_string(const tm& t, const char* format) {
  std::stringstream s;
  format_date_time(s, t, format);
  return s.str();
}

tm now() {
  std::time_t now = time(0);
  return *localtime(&now);
}

int main() {
  try {
    std::string s = date_time_to_string(now(), "%A %B, %d %Y %I:%M%p");
    std::cout << s << std::endl;
    s = date_time_to_string(now(), "%Y-%m-%d %H:%M:%S");
    std::cout << s << std::endl;
  } catch(...) {
    std::cerr << "failed to format date time" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
