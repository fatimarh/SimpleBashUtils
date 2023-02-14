#ifndef C3_SIMPLEBASHUTILS_0_SRC_CAT_S21_CAT_H_
#define C3_SIMPLEBASHUTILS_0_SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <string.h>

typedef struct flags {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
  int check;
} flags;

void parsing_flags(char **argv, flags *options, int *error, int argc);
void read_and_print_file(char *file_name, flags *options);
void check_files(int argc, char **argv, flags options);

#endif