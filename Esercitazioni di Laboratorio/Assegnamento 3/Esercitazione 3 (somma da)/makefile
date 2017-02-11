somma_da.o: somma_da.c somma_da.h
	indent somma_da.c
	indent somma_da.h
	gcc -c -g -pedantic -Wall -DINIT_VALUE=1304 -DDEBUG_MODE=0 somma_da.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

somma_da: somma_da.o
	gcc somma_da.o -o somma_da.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
