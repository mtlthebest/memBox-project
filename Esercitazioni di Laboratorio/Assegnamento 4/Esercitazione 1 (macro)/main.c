/* +--------------------+
 * | Esercizio 1: macro |
 * +--------------------+
 *
 * Dato il seguente codice main C:
 * +------------------------------------------------------+
 * | #define dimN 16                                      |
 * | #define dimM  8                                      |
 * | int main() {                                         |
 * |     long *M = (long*)malloc(dimN*dimM*sizeof(long)); |
 * |     assert(M);                                       |
 * |     for(size_t i=0;i<dimN;++i)                       |
 * |         for(size_t j=0;j<dimM;++j) {                 |
 * |             ELEM(M,i,j) = i+j;                       |
 * |         }                                            |
 * |                                                      |
 * |     PRINTMAT(M);                                     |
 * |     free(M);                                         |
 * |     return 0;                                        |
 * | }                                                    |
 * +------------------------------------------------------+
 *
 * scrivere le 2 macros ELEM e PRINTMAT. Al suo interno PRINTMAT usa
 * la macro ELEM per accedere agli elementi della matrice. Esempio di
 * output richiesto:
 * +------------------------------------------------------+
 * | Stampo la matrice M:                                 |
 * |    0    1    2    3    4    5    6    7              |
 * |    1    2    3    4    5    6    7    8              |
 * |    2    3 ....                                       |
 * +------------------------------------------------------+
 */

#define dimN 16
#define dimM  8

#define ELEM(matrice, x, y) *(matrice + (x * dimM) + y)
#define PRINTMAT(matrice)			\
  char name[] = #matrice;			\
  printf("Stampo la matrice %s:\n", name);	\
  for(int p = 0; p < dimN; p++)			\
    {						\
      for (int q = 0; q < dimM; q++)		\
	printf("%4d ", ELEM(matrice, p, q));	\
      printf("\n");				\
    }

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int
main ()
{
  int *M = (int *) malloc (dimN * dimM * sizeof (int));
  assert (M);
  for (size_t i = 0; i < dimN; ++i)
    for (size_t j = 0; j < dimM; ++j)
      {
	ELEM (M, i, j) = i + j;
      }
  PRINTMAT (M);
  free (M);
  return 0;
}
