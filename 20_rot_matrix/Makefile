CFLAGS = -Wall -Werror -pedantic -std=gnu99
test.o: rotate.o read-matrix.o
	gcc -o test rotate.o read-matrix.o
rotate.o: rotate.c
	gcc $(CFLAGS) -c rotate.c

.PHONY: clean
clean:
	rm *.c~ *~
