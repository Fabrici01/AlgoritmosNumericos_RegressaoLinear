all: compila

compila: main.o eliminacaoDeGauss.o
	gcc main.o eliminacaoDeGauss.o -o prog

main.o: main.c
	gcc -c main.c

eliminacaoDeGauss.o: eliminacaoDeGauss.c
	gcc -c eliminacaoDeGauss.c

del:
	del main.o eliminacaoDeGauss.o prog.exe