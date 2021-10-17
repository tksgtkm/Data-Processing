/*********************************************************
*                                                        *
*1つのファイルをコピーする                                   *
*                                                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE (16*1024) // 16kb

int main(int argc, char *argv[]) {
  char buffer[BUFFER_SIZE]; // データ用バッファ
  int in_file;              // 入力ファイル記述子
  int out_file;             // 出力ファイル記述子
  int read_size;            // 最後に読まれたバイト数

  if (argc != 3) {
    fprintf(stderr, "Error:Wrong number of arguments\n");
    fprintf(stderr, "Usage is: copy <from> <to>\n");
    exit(8);
  }

  // コピー元のファイル
  in_file = open(argv[1], O_RDONLY);
  if (in_file < 0) {
    fprintf("Error:Unable to open %s\n", argv[1]);
    exit(8);
  }

  // コピー先のファイル
  out_file = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
  if (out_file < 0) {
    fprintf("Error:Unable to open %s\n", argv[2]);
    exit(8);
  }

  while (1) {
    read_size = read(in_file, buffer, sizeof(buffer));

    if (read_size == 0)
      break;

    if (read_size < 0) {
      fprintf(stderr, "Error:Read error\n");
      exit(8);
    }

    write(out_file, buffer, (unsigned int) read_size);
  }
  close(in_file);
  close(out_file);

  return 0;
}
