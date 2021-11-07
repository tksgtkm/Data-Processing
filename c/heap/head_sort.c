#include <stdio.h>

void ShiftDown(int key, int num[], int root, int last) {
  int bigger = 2*root;
  while (bigger <= last) {
    if (bigger < last)
      if (num[bigger + 1] > num[bigger])
        bigger++;
    if (key >= num[bigger])
      break;
    num[root] = num[bigger];
    root = bigger;
    bigger = 2*root;
  }
  num[root] = key;
}

void HeapSort(int num[], int n) {
  for (int h=n/2; h>=1; h--)
    ShiftDown(num[h], num, h, n);

  for (int k=n; k>1; k--) {
    int item = num[k];
    num[k] = num[1];
    ShiftDown(item, num, 1, k - 1);
  }
}

int main() {
  int num[] = {0, 37, 25, 43, 65, 48, 84, 73, 18, 79, 56, 69, 32};
  int n = 12;
  HeapSort(num, n);
  for (int h=1; h<=n; h++)
    printf("%d ", num[h]);

  printf("\n");
}
