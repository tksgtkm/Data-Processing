#include <iostream>
#include <fstream>
#include <cstring>

struct inventory {
  char item[20];
  int quantity;
  double cost;
};

int main() {
  std::ofstream fout("InvDat.sst", std::ios::out | std::ios::binary);

  if (!fout) {
    std::cout << "ファイルを開けません。\n";
    return 1;
  }

  inventory inv[3];
  std::strcpy(inv[0].item, "Hammers");
  inv[0].quantity = 3;
  inv[0].cost = 9.99;
  std::strcpy(inv[1].item, "Pliers");
  inv[1].quantity = 12;
  inv[1].cost = 7.85;
  std::strcpy(inv[2].item, "Wranches");
  inv[2].quantity = 19;
  inv[2].cost = 2.75;

  for (int i=0; i<3; i++)
    fout.write((const char *) &inv[i], sizeof(inventory));

  fout.close();

  if (!fout.good()) {
    std::cout << "ファイルエラーが発生しました。";
    return 1;
  }

  return 0;
}
