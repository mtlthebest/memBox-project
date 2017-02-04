tokenizer.o: tokenizer.c tokenizer.h
	indent tokenizer.c
	indent tokenizer.h
	gcc -c -g -Wall tokenizer.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer_r.o: tokenizer_r.c
	indent tokenizer_r.c
	gcc -c -g -Wall tokenizer_r.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

libtokenizer.a: tokenizer.o
	ar rvs libtokenizer.a tokenizer.o
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer_r: libtokenizer.a tokenizer_r.o
	gcc -g -Wall tokenizer_r.o -o tokenizer_r.run -L . -ltokenizer
	rm -f *~
	rm -f *.*~
	rm -f \#*
