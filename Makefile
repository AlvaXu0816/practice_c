CFLAGS=-Wall -g

all: ex-1 ex-3

ex-1: ex1.c
	cc $(CFLAGS) ex-1.c -o ex1

ex-3: ex3.c
	cc $(CFLAGS) ex-3.c -o ex3

clean:
	rm -f ex-1 ex-3

