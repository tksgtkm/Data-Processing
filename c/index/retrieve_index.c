#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PART_NUM_SIZE 6
#define MAX_NAME      24
#define MAX_RECORDS   100

typedef struct part_record {
  char partnum[PART_NUM_SIZE + 1];
  char name[MAX_NAME + 1];
  int amt_in_stock;
  double unit_price;
} PartRecord;

typedef struct index_entry {
  char partnum[PART_NUM_SIZE + 1];
  int recnum;
} IndexEntry;

void RetrieveRecords(IndexEntry index[], FILE *pf) {
  char pnum[PART_NUM_SIZE*2]; // 入力された文字列に対して、余裕を見ておく
  PartRecord part;
  int search(char[], IndexEntry[], int);

  int num_records = index[0].recnum;
  printf("\nEnter a part number (E to end): ");
  scanf("%s", pnum);
  while (strcmp(pnum, "E") != 0) {
    int n = search(pnum, index, num_records);
    if (n < 0) {
      printf("Part not found\n");
    } else {
      fseek(pf, (index[n].recnum - 1)*sizeof(PartRecord), SEEK_SET);
      fread(&part, sizeof(PartRecord), 1, pf);
      printf("\nPart number: %s\n", part.partnum);
      printf("Part name: %s\n", part.name);
      printf("Amount in stock: %d\n", part.amt_in_stock);
      printf("Price s%3.2f\n", part.unit_price);
    }
    printf("\nEnter a part number (E to end): ");
    scanf("%s", pnum);
  }
}

void RetrieveIndex( char *filename, IndexEntry index[]) {
  FILE *indexfile;
  int maxrecords;

  if ((indexfile = fopen(filename, "rb")) == NULL) {
    printf("cannot open index file.\n");
    exit(1);
  }
  fread(&maxrecords, sizeof(int), 1, indexfile);
  fread(index, sizeof(IndexEntry), maxrecords, indexfile);
  fclose(indexfile);
}

int search(char key[], IndexEntry list[], int n) {
  int lo = 1;
  int hi = n;
  while (lo <= hi) {
    int mid = (lo + hi)/2;
    int cmp = strcmp(key, list[mid].partnum);
    if (cmp == 0)
      return mid;
    if (cmp < 0)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return -lo;
}

int main() {
  FILE *partfile;
  IndexEntry index[MAX_RECORDS + 1];

  if ((partfile = fopen("parts.bin", "rb")) == NULL) {
    printf("Cannot open file\n");
  }

  RetrieveIndex("index.bin", index);
  RetrieveRecords(index, partfile);
  fclose(partfile);
}
