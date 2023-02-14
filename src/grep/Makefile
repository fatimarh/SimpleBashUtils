CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -std=c11
SOURSES = s21_grep.c
OBJECTS = s21_grep.o

.PHONY: s21_grep

all: clean s21_grep

s21_grep: $(OBJECTS)
	$(CC) $(OBJECTS) -o s21_grep

s21_grep.o: s21_grep.c
	$(CC) $(CC_FLAGS) -c s21_grep.c -g

clean:
	@rm -rf *.out
	@rm -rf *.out
	@rm -rf s21_grep
	@rm -rf .clang-format

test: s21_grep
	sh test_1_1.sh

leaks:
	@echo --------------------MEMORY_LEAKS-----------------------
	$(CC) $(CC_FLAGS)  $(SOURSES) -lgtest -o leaks -g
	CK_FORK=no leaks --atExit -- ./leaks
	@rm ./leaks


check: s21_grep
	@echo -------------------CLANG_FORMAT------------------------
	@echo -------------------------------------------------------
	@cp ../../materials/linters/.clang-format .clang-format
	@clang-format -style=file --dry-run --Werror $(SOURSES) s21_grep.c *.h
	@rm .clang-format  
	@make leaks
