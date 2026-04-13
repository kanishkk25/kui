CC = gcc
CFLAGS = -g -Wall
DEPEND = -I include/ -L lib -lkui

default: build

build:
	rm lib/* || echo "nothing to remove"
	$(CC) -c src/kui.c -I include/ -o kui.o
	ar rcs libkui.a kui.o
	mv libkui.a lib/
	rm kui.o

clear:
	rm *.out || echo "nothing to remove"

buildeg1:
	$(CC) $(CFLAGS) testcases/eg1.c -o eg1.out $(DEPEND)

buildeg2:
	$(CC) $(CFLAGS) testcases/eg2.c -o eg2.out $(DEPEND)

buildeg3:
	$(CC) $(CFLAGS) testcases/eg3.c -o eg3.out $(DEPEND)

buildeg4:
	$(CC) $(CFLAGS) testcases/eg4.c -o eg4.out $(DEPEND)






