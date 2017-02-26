CC = g++
CFLAGS = -O3 -Wall -pedantic

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

.PHONY: clean_all clean indent
