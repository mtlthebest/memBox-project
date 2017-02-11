reentrant_somma_da.o: reentrant_somma_da.c reentrant_somma_da.h
	indent reentrant_somma_da.c
	indent reentrant_somma_da.h
	gcc -c -g -pedantic -Wall -DINIT_VALUE=1304 -DDEBUG_MODE=0 reentrant_somma_da.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

reentrant_somma_da: reentrant_somma_da.o
	gcc reentrant_somma_da.o -o reentrant_somma_da.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
