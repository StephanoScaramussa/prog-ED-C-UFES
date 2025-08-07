all: compila
compila: main.o ListaDuplamenteEnc.o RegistrodeHumor.o
	gcc main.o ListaDuplamenteEnc.o RegistrodeHumor.o -o main
	start "" cmd /k "chcp 65001 > nul && main.exe"

main.o: main.c 
	gcc -c main.c 
RegistrodeHumor.o: RegistrodeHumor.c
	gcc -c RegistrodeHumor.c
ListaDuplamenteEnc.o: ListaDuplamenteEnc.c
	gcc -c ListaDuplamenteEnc.c

run:all
	./main.exe

clean:
	del main.o ListaDuplamenteEnc.o RegistrodeHumor.o main.exe