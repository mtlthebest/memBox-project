tokenizer.o: tokenizer.c
	indent tokenizer.c
	gcc -c -g -pedantic -Wall tokenizer.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer_r.o: tokenizer_r.c tokenizer.h
	indent tokenizer_r.c
	indent tokenizer.h
	gcc -c -g -pedantic -Wall tokenizer_r.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

libtokenizer.a: tokenizer.o
	ar rvs libtokenizer.a tokenizer.o
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer_r: libtokenizer.a tokenizer_r.o
	gcc tokenizer_r.o -o tokenizer_r.run -L . -ltokenizer
	rm -f *~
	rm -f *.*~
	rm -f \#*
