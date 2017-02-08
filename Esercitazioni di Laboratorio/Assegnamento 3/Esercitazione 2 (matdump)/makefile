matdump.o: matdump.c
	indent matdump.c
	gcc -c -g -pedantic -Wall matdump.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

matdump: matdump.o
	gcc matdump.o -o matdump.run
	rm -f *~
	rm -f *.*~
	rm -f \#*
