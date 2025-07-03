all: compila
compila: main.o lista-dupla-enc.o registro-de-humor.o
	gcc main.o lista-dupla-enc.o registro-de-humor.o -o programaWindows
main.o: main.c
	gcc -c main.c
lista-dupla-enc.o: lista-dupla-enc.c
	gcc -c lista-dupla-enc.c
registro-de-humor.o: registro-de-humor.c
	gcc -c registro-de-humor.c
clean:
	rm main.o lista-dupla-enc.o registro-de-humor.o programaWindows.exe