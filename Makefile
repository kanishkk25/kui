
default: build

buildex1:
	gcc testcases/eg1.c -o eg1.out -I include  -L testLib -lEkui

build:
	rm testLib/*
	gcc -c src/kui.c -I include/ -o Ekui.o
	ar rcs libEkui.a Ekui.o
	mv libEkui.a testLib/
	rm Ekui.o
