#ifndef C3_SIMPLEBASHUTILS_0_SRC_GREP_S21_GREP_H_
#define C3_SIMPLEBASHUTILS_0_SRC_GREP_S21_GREP_H_

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} Flags;

typedef struct {
  char name[BUFSIZ];
} Tamplate;

void check_options(int argc, char **argv, Flags flag, Tamplate *text);
void make_regex(char *name, Flags flag, Tamplate *text, int l, int n);
int check_flags(char **argv, Flags *flag, int argc);

#endif
