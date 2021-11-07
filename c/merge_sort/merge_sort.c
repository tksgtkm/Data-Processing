#include <stdio.h>

#define MAX_SIZE 20

void Merge(int A[], int lo, int mid, int hi) {
  int T[MAX_SIZE];
  int i = lo;
  int j = mid + 1;
  int k = lo;
  while (i <= mid || j <= hi) {
    if (i > mid)
      T[k++] = A[j++];
    else if (j > hi)
      T[k++] = A[i++];
    else if (A[i] < A[j])
      T[k++] = A[i++];
    else
      T[k++] = A[j++];
  }
  for (j = lo; j <= hi; j++)
    A[j] = T[j];
}

void MergeSort(int A[], int lo, int hi) {
  if (lo < hi) {
    int mid = (lo + hi)/2;
    MergeSort(A, lo, mid);
    MergeSort(A, mid + 1, hi);
    Merge(A, lo, mid, hi);
  }
}

int main() {
  int num[] = {4,8,6,16,1,9,14,2,3,5,18,13,17,7,12,11,15,10};
  int n = 18;
  MergeSort(num, 0, n - 1);
  for (int h=0; h<n; h++)
    printf("%d ", num[h]);
  printf("\n\n");
}
