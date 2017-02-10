refactored_somma_da.o: refactored_somma_da.c refactored_somma_da.h
	indent refactored_somma_da.c
	indent refactored_somma_da.h
	gcc -c -g -pedantic -Wall -DINIT_VALUE=1304 refactored_somma_da.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

refactored_somma_da: refactored_somma_da.o
	gcc refactored_somma_da.o -o refactored_somma_da.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
