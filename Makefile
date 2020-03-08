all: prog2 prog2_arq

prog2: prog2.c prog2.h
	gcc -Wall -Wextra -g prog2.c -o prog2

prog2_arg: prog2_arq.c prog2.h
	gcc -Wall -Wextra -g prog2_arg.c -o prog2_argc

clean:
	rm -f prog2 *~ *.swp
