CC = gcc
CFLAGS = -g -Wall


default: build

build:
	rm lib/* || echo "nothing to remove"
	$(CC) -c src/kui.c -I include/ -o kui.o
	ar rcs libkui.a kui.o
	mv libkui.a lib/
	rm kui.o

buildex1:
	$(CC) testcases/eg1.c -o eg1.out -I include/  -L lib -lkui



