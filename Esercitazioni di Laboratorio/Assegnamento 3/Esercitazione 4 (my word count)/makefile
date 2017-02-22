clean:
	find . -name "*~" -type f -delete
	find . -name "*.*~" -type f -delete
	find . -name "\#*" -type f -delete

indent:
	indent libs/my_utils.c
	indent libs/my_utils.h
	indent libs/parse_and_validate_input.c
	indent libs/parse_and_validate_input.h
	indent testdrivers/my_utils_testdriver.c
	indent refactored_my_word_count.c

my_utils.o: libs/my_utils.c libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 libs/my_utils.c
	mv -f my_utils.o libs/

my_utils_testdriver.o: testdrivers/my_utils_testdriver.c libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 testdrivers/my_utils_testdriver.c
	mv -f my_utils_testdriver.o testdrivers/

my_utils_testdriver: indent my_utils_testdriver.o my_utils.o clean
	gcc libs/my_utils.o testdrivers/my_utils_testdriver.o -o testdrivers/my_utils_testdriver.run

parse_and_validate_input.o: libs/parse_and_validate_input.c libs/parse_and_validate_input.h libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 libs/parse_and_validate_input.c
	mv -f parse_and_validate_input.o libs/

refactored_my_word_count.o: refactored_my_word_count.c libs/parse_and_validate_input.h libs/my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 refactored_my_word_count.c

refactored_my_word_count: indent refactored_my_word_count.o my_utils.o parse_and_validate_input.o clean
	gcc refactored_my_word_count.o libs/my_utils.o libs/parse_and_validate_input.o -o refactored_my_word_count.run
