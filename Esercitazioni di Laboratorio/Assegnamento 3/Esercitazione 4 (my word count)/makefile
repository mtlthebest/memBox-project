my_word_count.o: my_word_count.c my_word_count.h
	indent my_word_count.c
	indent my_word_count.h
	gcc -c -g -pedantic -Wall my_word_count.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

my_word_count: my_word_count.o
	gcc my_word_count.o -o my_word_count.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
