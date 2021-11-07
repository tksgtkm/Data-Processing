#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void CreateMaster(char *filename, IndexEntry index[], int max_records) {
  FILE *ftxt, *fbin;
  PartRecord part;
  int search_result, search(char[], IndexEntry[], int);
  int num_records = 0;

  if ((ftxt = fopen("parts.txt", "r")) == NULL) {
    printf("Cannot open parts file\n");
    return;
  }

  if ((fbin = fopen("parts.bin", "wb")) == NULL) {
    printf("Cannot create file\n");
    return;
  }

  while (fscanf(ftxt, "%s %s %d %lf", part.partnum, part.name, &part.amt_in_stock, &part.unit_price) == 4) {
    search_result = search(part.partnum, index, num_records);
    if (search_result > 0) {
      printf("Duplicate part: %s ignored\n", part.partnum);
    } else {
      if (num_records == max_records) {
        printf("Too many records: only %d allowed\n", max_records);
        exit(1);
      }

      int j;
      for (j=num_records; j>=-search_result; j--)
        index[j + 1] = index[j];

      strcpy(index[-search_result].partnum, part.partnum);
      index[-search_result].recnum = ++num_records;
      if (fwrite(&part, sizeof(PartRecord), 1, fbin) != 1) {
        printf("Error in writing file\n");
        exit(1);
      }
      printf("%s %-11s %2d %5.2f\n", part.partnum, part.name, part.amt_in_stock, part.unit_price);
    }
  }

  index[0].recnum = num_records;
  fclose(fbin);
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

void SaveIndex(char *filename, IndexEntry index[], int max) {
  FILE *indexfile;
  if ((indexfile = fopen(filename, "wb")) == NULL) {
    printf("Cannot create file %s. Index not saved\n", filename);
    exit(1);
  }

  fwrite(&max, sizeof(int), 1, indexfile);
  fwrite(index, sizeof(IndexEntry), max, indexfile);
  fclose(indexfile);
}

int main() {
  IndexEntry index[MAX_RECORDS + 1];
  // void CreateMaster(char *, IndexEntry[], int);
  // void SaveIndex(char *, IndexEntry[], int);
  CreateMaster("parts.bin", index, MAX_RECORDS);
  SaveIndex("index.bin", index, MAX_RECORDS + 1);
}
