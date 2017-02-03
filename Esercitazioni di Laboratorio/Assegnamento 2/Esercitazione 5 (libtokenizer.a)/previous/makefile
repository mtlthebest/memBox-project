tokenizer.o: tokenizer.c tokenizer.h
	indent tokenizer.c
	indent tokenizer.h
	gcc -c -g -Wall tokenizer.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer_r.o: tokenizer_r.c tokenizer_r.h
	indent tokenizer_r.c
	indent tokenizer_r.h
	gcc -c -g -Wall tokenizer_r.c
	rm -f *~
	rm -f *.*~
	rm -f \#*

tokenizer: tokenizer.o
	gcc tokenizer.o -o tokenizer.run
	rm -f *~
	rm -f *.*~
	rm -f *.o
	rm -f *.o~
	rm -f \#*

tokenizer_r: tokenizer_r.o
	gcc tokenizer_r.o -o tokenizer_r.run
	rm -f *~
	rm -f *.*~
	rm -f *.o
	rm -f *.o~
	rm -f \#*
