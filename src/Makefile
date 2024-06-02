CC=gcc
CFLAGS=-Wall -Wextra -Werror
GCOV=-fprofile-arcs -ftest-coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	LEAKS=CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
	TESTS=$(CC) $(CFLAGS) -g test2.c my_math.a $(LIBS) -o test.out
else
	LIBS=-lcheck
	LEAKS=CK_FORK=no leaks --atExit -- ./test.out
	TESTS=$(CC) $(CFLAGS) -g test.c my_math.a $(LIBS) -o test.out
endif

all: clean my_math.a test
test: clean my_math.a
	$(TESTS)
	./test.out

gcov_report: my_math.a
	$(CC) --coverage -c my_math.c
	ar rc my_math.a *.o
	$(CC) test.c -L. my_math.a -lcheck -lpthread -lm -lgcov -o test_cov
	rm -rf *.o
	./test_cov
	gcov *.gcda
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	mkdir -p ./report
	genhtml -o report gcov_report.info
	open ./report/index.html

my_math.a:
	$(CC) $(CFLAGS) -c my_math.c -o my_math.o
	ar rcs my_math.a my_math.o

clean:
	rm -rf *.0 *.a *.gcno *.gcda *.info *.out report *.dSYM *.gch *.o test2.out .vscode .DS_Store my_math.c.gcov test_cov CPPLINT.cfg my_math ../.DS_Store ../.vscode a.out

leaks: clean test
	$(LEAKS)

codestyle:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	rm -rf CPPLINT.cfg

CPPcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem my_math.c *.c *.h

CH: clean leaks codestyle CPPcheck
	rm -rf *.0 *.a *.gcno *.gcda *.info *.out report *.dSYM test2.out *.gch *.o .vscode .DS_Store a.out my_math.c.gcov test_cov CPPLINT.cfg my_math ../.DS_Store ../.vscode 