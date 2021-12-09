#include <iostream>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

constexpr int BUFFER_SIZE = (16 * 1024);

int main(int argc, char *argv[]) {
  char buffer[BUFFER_SIZE];
  int in_file;
  int out_file;
  int read_size;

  if (argc != 3) {
    std::cerr << "Errpr: wrong number of arguments\n";
  }

  in_file = ::open(argv[1], O_RDONLY);
  out_file = ::open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);

  while (true) {
    read_size = ::read(in_file, buffer, sizeof(buffer));
    if (read_size == 0)
      break;
    if (read_size < 0)
      std::cerr << "Error: read error\n";

    ::write(out_file, buffer, (unsigned int) read_size);
  }

  close(in_file);
  close(out_file);
  return 0;
}
