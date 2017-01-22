#include<stdio.h>
#include<string.h>

#include <usodebugger.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
	fprintf(stderr, "Usa: %s stringa [stringa]\n", argv[0]);
	return -1;
    }
    char *a[3]={"alberello","rosea","roma"};

    leggi(a, 3);
    leggi(++argv, --argc);
    return 0;
}
