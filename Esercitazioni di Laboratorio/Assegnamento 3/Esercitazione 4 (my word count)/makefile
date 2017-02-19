refactored_my_word_count.o: refactored_my_word_count.c refactored_my_word_count.h
	indent refactored_my_word_count.c
	indent refactored_my_word_count.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 refactored_my_word_count.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

refactored_my_word_count: refactored_my_word_count.o
	gcc refactored_my_word_count.o -o refactored_my_word_count.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
