all: prog2 prog2_arq

prog2: prog2.c prog2.h
	gcc -Wall -Wextra -g prog2.c -o prog2

prog2_arg: prog2_arq.c prog2.h helper.h
	gcc -Wall -Wextra -g prog2_arq.c -o prog2_arq

clean:
	rm -f prog2 prog2_arq *~ *.swp
