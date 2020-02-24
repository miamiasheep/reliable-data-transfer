all: prog2

prog2: prog2.c prog2.h
	gcc -Wall -Wextra -g prog2.c -o prog2

clean:
	rm -f prog2 *~ *.swp
