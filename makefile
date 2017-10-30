all: randy_ran_dumb.c
	gcc -o fileio randy_ran_dumb.c
run: all
	./fileio

