all: ordena gera
	clear; make clean --silent; ./run.sh; 

ordena: ordena.o arquivo.o sort.o 
	gcc ordena.o arquivo.o sort.o -o ordena

gera: arquivo.o gera.o
	gcc arquivo.c gera.c -o gera

ordena.o: ordena.c
	gcc -c ordena.c

arquivo.o: arquivo.c
	gcc -c arquivo.c 

gera.o: gera.c
	gcc -c gera.c 

sort.o: sort.c 
	gcc -c sort.c 

clean: ordena.o arquivo.o sort.o gera.o
	rm *.o
