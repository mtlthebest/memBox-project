testdriver.o: testdriver.c
	indent testdriver.c
	gcc -c -g -pedantic -Wall testdriver.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

testdriver: testdriver.o
	gcc testdriver.o -o testdriver.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
