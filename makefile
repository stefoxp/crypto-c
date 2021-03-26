# compilazione: programma a file multiplo
crittografia: main.o crittografia.o
	gcc -ansi -Wall -O main.o crittografia.o -o crittografia
main.o: main.c crittografia.h
	gcc -ansi -Wall -O -c main.c
crittografia.o: crittografia.c
	gcc -ansi -Wall -O -c crittografia.c
# la parte seguente funziona solo sulla bash di Linux
pulisci:
	rm -f *.o
pulisci_tutto:
	rm -f file crittografia.exe *.o
