#include <stdio.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_LINE 101

int main() {
  char name1[MAX_NAME], name2[MAX_NAME];
  char line1[MAX_LINE], line2[MAX_LINE];
  FILE *file1, *file2, *Getfilename(char *, char *);
  char *eof1, *eof2;

  int linenum = 0;
  file1 = Getfilename("First file?", name1);
  file2 = Getfilename("Second file?", name2);

  while (((eof1 = fgets(line1, MAX_LINE, file1)) != NULL) && ((eof2 = fgets(line2, MAX_LINE, file2)) != NULL) && (strcmp(line1, line2) == 0))
    linenum++;

  if (eof1 == NULL) {
    if (fgets(line2, MAX_LINE, file2) == NULL)
      printf("\nFiles are idential\n\n");
    else
      printf("\n%s, with %d line(s), is a subset of %s\n", name1, linenum, name2);
  } else if (eof2 == NULL) {
    printf("\n%s, with %d line(s), is a subset of %s\n", name2, linenum, name1);
  } else {
    printf("\nThe files differ at line %d\n", ++linenum);
    printf("The lines are \n%s and \n%s", line1, line2);
  }
  fclose(file1);
  fclose(file2);
}

FILE *Getfilename(char *prompt, char *name) {
  FILE *fileptr;
  do {
    printf("%s ", prompt);
    gets(name);
    if ((fileptr = fopen(name, "r")) == NULL)
      printf("File does not exist or access denied\n");
  } while (fileptr == NULL);

  return fileptr;
}
