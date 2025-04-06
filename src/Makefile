СС=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
SRC_LINTER = ../materials/linters/.clang-format
SRC = s21_string.c s21_sprintf.c s21_sscanf.c s21_sspf.c
HEADER =  s21_string.h s21_sprintf.h s21_sscanf.h s21_sspf.h
TEST = test
TEST_SRC = ./tests/s21_tests.c  ./tests/s21_tests_string.c ./tests/s21_tests_sprintf_main_part.c ./tests/s21_tests_sscanf.c  ./tests/s21_tests_csharp.c
TEST_FLAGS =-L. -lcheck -lm ./s21_string.a
OS = $(shell uname)
ifeq ($(OS), Linux)
    TEST_FLAGS += -lpthread -lrt -lm -lsubunit
endif

ifeq ($(OS), Darwin)
    TEST_FLAGS += -I /opt/homebrew/Cellar/check/0.15.2/include -L /opt/homebrew/Cellar/check/0.15.2/lib
endif


all: s21_string.a

s21_string.a: compile_object_file
	ar rc s21_string.a s21_string.o s21_sprintf.o s21_sscanf.o s21_sspf.o\
	&& rm -f s21_string.o s21_sprintf.o s21_sscanf.o s21_sspf.o\
	&& ranlib s21_string.a

gcov_report: test
	mkdir -p coverage_report
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage -c $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) -o $(TEST) $(SRC) $(TEST_SRC) $(TEST_FLAGS) -fprofile-arcs -ftest-coverage
	./$(TEST) || true
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

test: $(TEST_SRC)
	$(СС) $(FLAGS) -o $(TEST) $(TEST_SRC) $(TEST_FLAGS)
	./$(TEST) || true

linter: $(SRC_LINTER)
	cp $(SRC_LINTER) .clang-format
	clang-format -i $(SRC) $(HEADER) $(TEST_SRC)

check: $(SRC_LINTER)
	cp $(SRC_LINTER) .clang-format
	clang-format -n $(SRC) $(HEADER)

clean:
	rm -f .clang-format $(TEST) coverage.info
	rm -rf coverage_report
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f *.a

compile_object_file:
	$(СС) $(FLAGS) -c $(SRC)