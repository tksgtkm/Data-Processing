#include <iostream>
#include <fstream>
#include <string>

constexpr int PartNumSize = 6;
constexpr int MaxName = 24;
constexpr int MaxRecords = 100;

struct PartRecord {
  char partnum[PartNumSize + 1];
  char name[MaxName + 1];
  int amtintstock;
  double unitprice;
};

int main() {
  PartRecord part[4];
  std::ifstream in{"parts.txt", std::ios::in};

  for(int i=0; i<4; i++) {
    in.read((char *) &part[i], sizeof(PartRecord));

    std::cout << part[i].partnum << std::endl;
  }
}
