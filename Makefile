main: main.c
	gcc -Wextra -Wall -ggdb -O0 main.c -lm -o main

debug:
	gdb main

memcheck:
	valgrind --show-leak-kinds=all --leak-check=full ./main

run:
	./main