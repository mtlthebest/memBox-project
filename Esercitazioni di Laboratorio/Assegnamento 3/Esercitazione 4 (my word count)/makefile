my_utils.o: my_utils.c my_utils.h
	indent my_utils.c
	indent my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 my_utils.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

my_utils_testdriver.o: my_utils_testdriver.c my_utils.h
	indent my_utils_testdriver.c
	indent my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 my_utils_testdriver.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

my_utils_testdriver: my_utils_testdriver.o my_utils.o
	gcc my_utils.o my_utils_testdriver.o -o my_utils_testdriver.run
	rm -f *~
	rm -f *.*~
	rm -f \#*

parse_and_validate_input.o: parse_and_validate_input.c parse_and_validate_input.h my_utils.h
	indent parse_and_validate_input.c
	indent parse_and_validate_input.h
	indent my_utils.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 parse_and_validate_input.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

refactored_my_word_count.o: refactored_my_word_count.c refactored_my_word_count.h
	indent refactored_my_word_count.c
	indent refactored_my_word_count.h
	gcc -c -g -pedantic -Wall -DDEBUG=1 refactored_my_word_count.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

refactored_my_word_count: refactored_my_word_count.o my_utils.o parse_and_validate_input.o
	gcc refactored_my_word_count.o my_utils.o parse_and_validate_input.o -o refactored_my_word_count.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
