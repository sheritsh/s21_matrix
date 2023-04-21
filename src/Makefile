# /* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */
TARGET = s21_matrix.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS = $(shell uname)
MODULES = $(wildcard modules/*.c)
OBJECTS = $(wildcard objects/*.o)

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck
endif

all: clean $(TARGET) test gcov_report

build: $(TARGET)

rebuild: clean $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs $(TARGET) $(OBJECTS)

$(OBJECTS): $(MODULES)
	$(CC) -c (CFLAGS) $(MODULES) $(LDLIBS)

# test:

# gcov_report:

style_check:
	cp ../materials/linters/.clang-format ./modules
	clang-format -n *.c
	rm ./modules/clang-format
	cp ../materials/linters/.clang-format .
	clang-format -n *.h
	rm ./.clang-format


format_style:
	cp ../materials/linters/.clang-format ./modules
	clang-format -i *.c
	rm ./modules/clang-format
	cp ../materials/linters/.clang-format .
	clang-format -i *.h
	rm ./.clang-format


# valgrind_check: $(TARGET)

clean:
	rm -rf objects

.PHONY: all build rebuild clean test gcov_report style_check valgrind_check