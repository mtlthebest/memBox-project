#include <stdio.h>
#include <stdlib.h>		// inserito da MtL

#define N 128
int main()
{
    char *A = malloc(N * sizeof(char));	// modificato da MtL
    int i = -1;			// modificato da MtL
    do {
	A[++i] = !(i % 2);
    }
    while (i < N - 1);		// modificato da MtL

    printf("stampa ...\n");
    for (int i = 0; i < N; ++i)
	printf("%d ", A[i]);
    printf("\nesco\n");
    free(A);			// inserito da MtL
    return 0;
}
