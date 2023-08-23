CFLAGS=-g -c -Wall -Wextra -Werror -std=c11 -pedantic
FLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
ASAN=#-fsanitize=address -fanalyzer


all: s21_math.a

s21_math.a:
	gcc $(CFLAGS) -o s21_math.o -c s21_math.c
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

s21_math.a_for_tests:
	rm -f s21_math.a
	gcc $(CFLAGS) $(ASAN) -fprofile-arcs -ftest-coverage -o s21_math.o -c s21_math.c
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

clean:
	rm -f *.a *.o
	rm -f *.info *.gcda *.gcno *.gcov
	rm -rf coverage
	rm -f mytests

test: s21_math.a_for_tests
	gcc $(FLAGS) $(ASAN) -fprofile-arcs -ftest-coverage ./tests/tests.c -o mytests -lcheck -L. s21_math.a
	./mytests
	geninfo . -b . -o ./coverage.info
	genhtml coverage.info -o ./coverage

gcov_report:
	open coverage/index.html
