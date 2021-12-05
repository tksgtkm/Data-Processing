#include <iostream>
#include <cstdio>

int main() {
  char ch;
  FILE *file;
  char filename[20];
  std::cout << "Enter the name of the file: " << std::endl;
  fgets(filename, 100, file);
  file = fopen(filename, "r");
  while (fread(&ch, 1, 1, file) != 0)
    fwrite(&ch, 1, 1, stdout);
  fclose(file);
}
