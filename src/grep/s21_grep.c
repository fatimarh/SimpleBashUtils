#include "s21_grep.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    Flags flag = {0};
    Tamplate text[BUFSIZ];
    if (check_flags(argv, &flag, argc) == 0) {
      check_options(argc, argv, flag, text);
    }
  }
  return 0;
}

void check_options(int argc, char **argv, Flags flag, Tamplate *text) {
  int n = 0;
  if (argv[1][0] != '-') {
    strcpy(text[0].name, argv[1]);
    for (int i = 2; i < argc; i++) {
      make_regex(argv[i], flag, text, argc, n);
    }
  } else {
    int k = 0, flag_1 = 0;
    char str[BUFSIZ] = {'\0'}, name[BUFSIZ] = {'\0'};
    FILE *file;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        if (flag.f) {
          strcpy(name, argv[2]);
          if ((file = fopen(name, "r")) == NULL) {
            if (!flag.s)
              printf("s21_grep: %s: No such file or directory\n", argv[2]);
          } else {
            while (fgets(str, BUFSIZ - 1, file) != NULL) {
              int len = strlen(str);
              if (str[len - 1] == '\n') str[len - 1] = '\0';
              strcpy(text[n].name, str);
              n++;
            }
            k = i;
            fclose(file);
          }
        } else {
          if (flag.e && !flag.i && !flag.v && !flag.c && !flag.l && !flag.n &&
              !flag.h && !flag.s && !flag.o)
            flag_1 = 0;
          if (flag_1 == 0) {
            strcpy(text[n].name, argv[i + 1]);
            n++;
            flag_1 = 1;
          }
          k += 1;
          if (n > 1) k += 1;
        }
      }
    }
    for (int i = k + 2; i < argc; i++) {
      int l = argc - (k + 2);
      make_regex(argv[i], flag, text, l, n);
    }
  }
}

void make_regex(char *name, Flags flag, Tamplate *text, int l, int n) {
  FILE *fp;
  regex_t regex;
  if ((fp = fopen(name, "r")) == NULL) {
    if (!flag.s) printf("s21_grep: %s: No such file or directory\n", name);
  } else {
    int fail_or_success, line = 0, number = 1, regflag = 0;
    char str[BUFSIZ] = {'\0'};
    if (flag.i) regflag = REG_ICASE;
    while (fgets(str, BUFSIZ - 1, fp) != NULL) {
      for (int i = 0; i < n; i++) {
        regcomp(&regex, text[i].name, regflag);
        fail_or_success = regexec(&regex, str, 0, NULL, 0);
        regfree(&regex);
        if (!fail_or_success) {
          break;
        }
      }
      if (!fail_or_success) line++;
      if (!flag.c && flag.v && fail_or_success == 1) printf("%s", str);
      if (!flag.l && !flag.c && !flag.v && fail_or_success == 0) {
        if (l >= 2 && !flag.h) printf("%s:", name);
        if (flag.n) printf("%d:", number);
        if (flag.o) {
          printf("%s\n", text[0].name);
        } else {
          printf("%s", str);
        }
      }
      if (flag.l && fail_or_success == 0) {
        printf("%s\n", name);
        break;
      }
      fail_or_success = 1;
      number++;
    }
    if (flag.c) printf("%d\n", line);
    fclose(fp);
  }
}

int check_flags(char **argv, Flags *flag, int argc) {
  int error = 0;
  for (int j = 1; j < argc; j++) {
    if (argv[j][0] == '-' && argv[j][1] != '-') {
      int i = 1;
      while (argv[j][i] != '\0' && error != 1) {
        switch (argv[j][i]) {
          case 'e':
            flag->e = 1;
            break;
          case 'i':
            flag->i = 1;
            break;
          case 'v':
            flag->v = 1;
            break;
          case 'c':
            flag->c = 1;
            break;
          case 'l':
            flag->l = 1;
            break;
          case 'n':
            flag->n = 1;
            break;
          case 'h':
            flag->h = 1;
            break;
          case 's':
            flag->s = 1;
            break;
          case 'f':
            flag->f = 1;
            break;
          case 'o':
            flag->o = 1;
            break;

          default:
            printf(
                "grep: invalid option -- %s\nusage: grep [-h, -s, -f, -o, -e, "
                "-i, -v, -c, -l, -n, -iv, -in]\n",
                argv[i]);
            error = 1;
            break;
        }
        i++;
      }
    }
  }
  return error;
}
