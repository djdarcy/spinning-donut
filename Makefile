all:
	gcc -O2 -o donut donut.c -lm

clean:
	rm -f donut
