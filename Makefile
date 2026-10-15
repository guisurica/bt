main: main.c
	gcc -Wextra -Wall -g -O0 main.c -lm -o main

run:
	./main