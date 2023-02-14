#include "s21_cat.h"

int main(int argc, char **argv) {
  int flag_start = 1;
  struct flags flag = {0};

  if (argc > 1) {
    parsing_flags(argv, &flag, &flag_start, argc);
    if (flag_start) {
      check_files(argc, argv, flag);
    }
  }
  return 0;
}

void parsing_flags(char **argv, flags *flag, int *errors, int argc) {
  for (int i = 1; i < argc; i++) {
    for (size_t l = 1; l < strlen(argv[i]); l++) {
      if (argv[1][0] != '-') {
        flag->check = -1;
      }
      if (argv[i][0] == '-' && argv[i][1] != '-' && flag->check != -1) {
        switch (argv[i][l]) {
          case 'b':
            flag->b = 1;
            break;
          case 'e':
            flag->e = 1;
            flag->v = 1;
            break;
          case 'E':
            flag->e = 1;
            break;
          case 'v':
            flag->v = 1;
            break;
          case 'n':
            flag->n = 1;
            break;
          case 's':
            flag->s = 1;
            break;
          case 't':
            flag->t = 1;
            flag->v = 1;
            break;
          case 'T':
            flag->t = 1;
            flag->v = 1;
            break;

          default:
            *errors = 0;
            printf(
                "cat: illegal option -- %c\nusage: cat [-benstuv] [file ...]\n",
                argv[1][l]);
            l = strlen(argv[1]);
        }
      } else if (argv[1][0] == '-' && argv[1][1] == '-') {
        if (!strcmp("--number-nonblank", argv[1])) {
          flag->b = 1;
        } else if (!strcmp("--number", argv[1])) {
          flag->n = 1;
        } else if (!strcmp("--squeeze-blank", argv[1])) {
          flag->s = 1;
        } else {
          printf(
              "cat: illegal option -- -\nusage: cat [-benstuv] [file ...]\n");
          *errors = 0;
        }
      }
    }
  }
}

void check_files(int argc, char **argv, flags flag) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      read_and_print_file(argv[i], &flag);
    }
  }
}

void read_and_print_file(char *file_name, flags *flag) {
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    fprintf(stderr, "No such file or directory\n");
  } else {
    int ch;
    int line_count = 1, previous_ch = '\n', empty_line_count = 0;
    if (flag->b && flag->n) {
      flag->n = 0;
    }
    while ((ch = fgetc(fp)) != EOF) {
      if (flag->s && ch == '\n' && previous_ch == '\n') {
        empty_line_count++;
        if (empty_line_count > 1) {
          continue;
        }
      } else {
        empty_line_count = 0;
      }

      if (previous_ch == '\n' && ((flag->b && ch != '\n') || flag->n)) {
        printf("%6d\t", line_count++);
      }

      if (flag->e && ch == '\n') {
        printf("$");
      }

      if (flag->t && ch == '\t') {
        ch = '^';
        putchar(ch);
        ch = 'I';
      }

      if (flag->v && ch != '\n') {
        if ((ch >= 0 && ch < 9) || (ch > 10 && ch <= 31)) {
          ch += 64;
          printf("^");
        } else if (ch == 127) {
          ch -= 64;
          printf("^");
        } else if (ch >= 127 && ch <= 159) {
          ch -= 64;
          printf("M-^");
        }
      }

      putchar(ch);
      previous_ch = ch;
    }
    if (fclose(fp) != 0) {
      perror("fclose errors");
    }
  }
}
