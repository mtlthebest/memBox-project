my_utils.o: libs/my_utils.c libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=0 libs/my_utils.c
	mv -f my_utils.o libs/

parsing_utils.o: libs/parsing_utils.c libs/parsing_utils.h libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=0 libs/parsing_utils.c
	mv -f parsing_utils.o libs/

utils_testdriver.o: testdrivers/utils_testdriver.c libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=0 testdrivers/utils_testdriver.c
	mv -f utils_testdriver.o testdrivers/

refactored_my_word_count.o: refactored_my_word_count.c refactored_my_word_count.h libs/parsing_utils.h libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=0 refactored_my_word_count.c

clean:
	find . -name "*~" -type f -delete
	find . -name "*.*~" -type f -delete
	find . -name "\#*" -type f -delete

clean_all: clean
	find . -name "*.o" -type f -delete
	find . -name "*.run" -type f -delete

indent:
	indent libs/my_utils.c
	indent libs/my_utils.h
	indent libs/parsing_utils.c
	indent libs/parsing_utils.h
	indent testdrivers/utils_testdriver.c
	indent refactored_my_word_count.c
	indent refactored_my_word_count.h

utils_testdriver: indent utils_testdriver.o my_utils.o parsing_utils.o clean
	gcc libs/my_utils.o libs/parsing_utils.o testdrivers/utils_testdriver.o -o testdrivers/utils_testdriver.run

refactored_my_word_count: indent refactored_my_word_count.o my_utils.o parsing_utils.o clean
	gcc refactored_my_word_count.o libs/my_utils.o libs/parsing_utils.o -o refactored_my_word_count.run
