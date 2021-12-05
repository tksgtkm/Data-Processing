#include <iostream>
#include <fstream>

struct inventory {
  char item[20];
  int quantity;
  double cost;
};

int main() {
  std::ifstream fin("InvDat.sst", std::ios::in | std::ios::binary);

  if (!fin) {
    std::cout << "ファイルを開けません。\n";
    return 1;
  }

  inventory inv[3];

  for (int i=0; i<3; i++)
    fin.read((char *) &inv[i], sizeof(inventory));

  fin.close();

  if (!fin.good()) {
    std::cout << "ファイルエラーが発生しました。\n";
    return 1;
  }

  for (int i=0; i<3; i++) {
    std::cout << inv[i].item << "\n";
    std::cout << " 在庫数量：" << inv[i].quantity;
    std::cout << "\n 価格：" << inv[i].cost << "\n\n";
  }

  return 0;
}
