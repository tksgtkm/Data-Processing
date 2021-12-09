#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

constexpr int PartNumSize = 6;
constexpr int MaxName = 24;
constexpr int MaxRecords = 100;

struct PartRecord {
  char partnum[PartNumSize + 1];
  char name[MaxName + 1];
  int amtintstock;
  double unitprice;
};

struct IndexEntry {
  char partnum[PartNumSize + 1];
  int recnum;
};

void SaveIndex(char *filename, IndexEntry index[]) {
  std::ofstream findex(filename, std::ios::out | std::ios::binary);

  findex.write((const char *) index, sizeof(IndexEntry));
  findex.close();
}


int main() {
  IndexEntry index[MaxRecords + 1];
  std::ifstream fin("parts.txt", std::ios::in | std::ios::binary);
  std::ofstream fout("parts.dat", std::ios::out | std::ios::binary);
  PartRecord inv[4];

  for (int i=0; i<4; i++) {
    fin.read((char *) &inv[i], sizeof(PartRecord));

    fout.write((const char *) &inv[i], sizeof(PartRecord));
  }

  SaveIndex("index.bin", index);

  fin.close();
  fout.close();

  return 0;
}
