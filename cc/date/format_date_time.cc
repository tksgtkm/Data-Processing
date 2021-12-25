#include <iostream>
#include <ctime>

int main() {
  std::time_t t = time(nullptr);
  char buf[256]{};
  strftime(buf, sizeof(buf), "%A %B, %d %Y %I:%M%p", localtime(&t));

  std::cout << "time: " << buf << '\n';
}
