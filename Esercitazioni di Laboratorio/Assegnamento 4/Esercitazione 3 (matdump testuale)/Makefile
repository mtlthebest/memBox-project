CC = gcc
CFLAGS = -g -Wall -pedantic -DDEBUG=1

.PHONY: clean_all clean indent

testdrive: main
	valgrind -v --leak-check=full ./main.run 11 26

main: main.o clean
	$(CC) $< -o $@.run

main.o: indent main.c
	$(CC) $(CFLAGS) -c main.c

clean_all: clean
	find . -name "*.o" -type f -delete
	find . -name "*.run" -type f -delete

clean:
	find . -name "*~" -type f -delete
	find . -name "*.*~" -type f -delete
	find . -name "\#*" -type f -delete

indent:
	indent main.c
