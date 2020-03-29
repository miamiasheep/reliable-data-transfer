all: prog2 prog2_arq prog2_gbn prog2_sr

prog2: prog2.c prog2.h
	gcc -Wall -Wextra -g prog2.c -o prog2

prog2_arg: prog2_arq.c prog2.h
	gcc -Wall -Wextra -g prog2_arq.c -o prog2_arq

prog2_gbn: prog2_gbn.c prog2.h
	gcc -Wall -Wextra -g prog2_gbn.c -o prog2_gbn

prog2_sr: prog2_sr.c prog2.h
	gcc -Wall -Wextra -g prog2_sr.c -o prog2_sr

run: 
	./prog2_arq > log_arq.txt
	./prog2_gbn > log_gbn.txt
	./prog2_sr > log_sr.txt

clean:
	rm -f prog2 prog2_arq prog2_gbn *~ *.swp
