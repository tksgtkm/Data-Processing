#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

constexpr PartNumSize = 6;
constexpr MaxName = 24;
constexpr MaxRecords = 100;

struct PartRecord {
  char partnum[PartNumSize + 1];
  char name[MaxName + 1];
  int amtintstock;
  double unitprice;
};

struct IndexEntry {
  char partnum[partNumSize + 1];
  int recnum;
};

void CreateMaster(char *filename, IndexEntry index[], int maxrecords) {
  PartRecord part;
  int search_result, search(char[], IndexEntry[], int);
  int num_records = 0;

  std::ofstream ftxt("index.txt");

  if  (!ftxt) {
    std::cout << "don't open txt file.\n";
    return 1;
  }

  std::ofstream fbin("index.sst", std::ios::out | std::ios::binary);

  if (!fbin) {
    std::cout << " don't open bin file.\n";
    return 1;
  }


}
