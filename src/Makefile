TARGET = s21_matrix.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
OS = $(shell uname)
MODULES = $(wildcard modules/*.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck
endif

all: clean $(TARGET) test gcov_report

build: $(TARGET)

rebuild: clean $(TARGET)

$(TARGET): $(OBJECTS)
	@ar rcs $(TARGET) $(wildcard objects/*.o)

%.o: %.c
	@mkdir -p objects
	@$(CC) -c $(CFLAGS) $< $(LDLIBS) -o $(patsubst modules%, objects%, $@)

test: $(TARGET)
	@$(CC) $(CFLAGS) $(wildcard tests/*.c) $(LDLIBS) -L. $(TARGET) -o testing_exe
	@./testing_exe

gcov_report:

style_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	cp ../materials/linters/.clang-format ./modules
	cd modules && clang-format -n *.c && cd ..
	rm ./modules/.clang-format
	cp ../materials/linters/.clang-format ./
	clang-format -n *.h
	rm ./.clang-format

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	cp ../materials/linters/.clang-format ./modules
	cd modules && clang-format -i *.c && cd ..
	rm ./modules/.clang-format
	cp ../materials/linters/.clang-format ./
	clang-format -i *.h
	rm ./.clang-format


valgrind_check: $(TARGET)
	CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="vglog" -v --verbose -q --quiet -s ./testing_exe

clean:
	rm -rf objects *.a testing_exe *.txt *.dSYM *.log tests/*.log

.PHONY: all build rebuild clean test gcov_report style_check valgrind_check