main.o: main.c
	gcc -c -g -pedantic -Wall main.c

clean:
	find . -name "*~" -type f -delete
	find . -name "*.*~" -type f -delete
	find . -name "\#*" -type f -delete

clean_all: clean
	find . -name "*.o" -type f -delete
	find . -name "*.run" -type f -delete

indent:
	indent main.c

main: indent main.o clean
	gcc main.o -o main.run
