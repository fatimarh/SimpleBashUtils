# !/bin/bash

./s21_grep -f text.txt s21_grep.c > s21_grep.txt
grep -f text.txt s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -f text.txt s21_grep.c s21_grep.h > s21_grep.txt
grep -f text.txt s21_grep.c s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e int -e void s21_grep.c > s21_grep.txt
grep -e int -e void s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ne options s21_grep.c > s21_grep.txt
grep -ne options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vi options s21_grep.c > s21_grep.txt
grep -vi options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ni options s21_grep.c > s21_grep.txt
grep -ni options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e options s21_grep.c > s21_grep.txt
grep -e options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -i Options s21_grep.c > s21_grep.txt
grep -i Options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ie options s21_grep.c > s21_grep.txt
grep -ie options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -c options s21_grep.c > s21_grep.txt
grep -c options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -l options s21_grep.c > s21_grep.txt
grep -l options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -n options s21_grep.c > s21_grep.txt
grep -n options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -h options s21_grep.c > s21_grep.txt
grep -h options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -v options s21_grep.c > s21_grep.txt
grep -v options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e options -i s21_grep.c > s21_grep.txt
grep -e options -i s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -h options -i s21_grep.c > s21_grep.txt
grep -h options -i s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -s options s21_grep.c > s21_grep.txt
grep -s options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -o flags s21_grep.c > s21_grep.txt
grep -o flags s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -iv options s21_grep.c > s21_grep.txt
grep -iv options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -in options s21_grep.c > s21_grep.txt
grep -in options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt