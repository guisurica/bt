main: main.c
	gcc -Wextra -Wall -ggdb -O0 main.c -lm -o main

debug:
	gdb main

run:
	./main