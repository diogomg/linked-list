CC = gcc

all: compile run clean

compile: *.c
	$(CC) -fprofile-arcs -ftest-coverage -g main.c list.c -lm -o list

valgrind: compile clean
	valgrind --tool=memcheck --leak-check=yes -v ./list

test: test.c list.c
	$(CC) -fprofile-arcs -ftest-coverage -g test.c list.c -lm -o test
	./test

coverage: list.gcda
	gcov list.gcda

run:
	./list

clean: *.o
	rm *.o *.gc* list test
