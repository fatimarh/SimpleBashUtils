CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -std=c11
SOURSES = s21_cat.c
OBJECTS = s21_cat.o

.PHONY: s21_cat

all: clean s21_cat

s21_cat: $(OBJECTS)
	$(CC) $(OBJECTS) -o s21_cat

s21_cat.o: s21_cat.c
	$(CC) $(CC_FLAGS) -c s21_cat.c -g

clean:
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf s21_cat
	@rm -rf .clang-format

test: s21_cat
	sh test_func_cat.sh

leaks:
	@echo --------------------MEMORY_LEAKS-----------------------
	$(CC) $(CC_FLAGS)  $(SOURSES) -lgtest -o leaks -g
	CK_FORK=no leaks --atExit -- ./leaks
	@rm ./leaks


check: s21_cat
	@echo -------------------CLANG_FORMAT------------------------
	@echo -------------------------------------------------------
	@cp ../../materials/linters/.clang-format .clang-format
	@clang-format -style=file --dry-run --Werror $(SOURSES) s21_cat.c *.h
	@rm .clang-format  
	@make leaks
