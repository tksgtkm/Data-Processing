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

void UpdateRecord(int n, FILE *pf) {
  PartRecord part;
  int amtsold;

  fseek(pf, (n - 1)*sizeof(PartRecord), SEEK_SET);
  fread(&part, sizeof(PartRecord), 1, pf);
  printf("Enter amount sold: ");
  scanf("%d", &amtsold);
  if (amtsold > part.amt_in_stock) {
    printf("You have %d: cannot sell more, ignored\n", part.amt_in_stock);
  } else {
    part.amt_in_stock -= amtsold;
    printf("Amount remaining: %d\n", part.amt_in_stock);
    fseek(pf, (n - 1)*sizeof(PartRecord), SEEK_SET);
    fwrite(&part, sizeof(PartRecord), 1, pf);
    printf("%s %-11s %2d %5.2f\n", part.partnum, part.name, part.amt_in_stock, part.unit_price);
  }
}

void RetrieveIndex(char *filename, IndexEntry index[]) {
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
  char pnum[PART_NUM_SIZE + 1];

  if ((partfile = fopen("parts.bin", "rb+")) == NULL) {
    printf("Cannot open file\n");
    return -1;
  }

  RetrieveIndex("index.bin", index);
  int num_records = index[0].recnum;

  printf("\nEnter a part number (E to end): ");
  scanf("%s", pnum);
  while (strcmp(pnum, "E") != 0) {
    int n = search(pnum, index, num_records);
    if (n < 0)
      printf("Part not found\n");
    else
      UpdateRecord(index[n].recnum, partfile);
    printf("\nEnter a part number (E to end): ");
    scanf("%s", pnum);
  }
  fclose(partfile);
}
