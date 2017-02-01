tokenizer.o: tokenizer.c tokenizer.h
	indent tokenizer.c
	indent tokenizer.h
	gcc -c -g -Wall tokenizer.c
	./clean_tilde

tokenizer_r.o: tokenizer_r.c tokenizer_r.h
	indent tokenizer_r.c
	indent tokenizer_r.h
	gcc -c -g -Wall tokenizer_r.c
	./clean_tilde

tokenizer: tokenizer.o
	gcc tokenizer.o -o tokenizer.run
	./clean_tilde
	./clean_object

tokenizer_r: tokenizer_r.o
	gcc tokenizer_r.o -o tokenizer_r.run
	./clean_tilde
	./clean_object
