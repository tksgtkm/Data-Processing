#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
  std::time_t now = time(0);

  tm* localtm = localtime(&now);
  std::cout << "The local date and time is: " << asctime(localtm) << std::endl;

  tm* gmtm = gmtime(&now);
  if (gmtm != nullptr) {
    std::cout << "The UTC date and time is: " << asctime(gmtm) << std::endl;
  } else {
    std::cerr << "Failed to get the UTC date and time" << std::endl;
    return EXIT_FAILURE;
  }
}
