/* +----------------------+
 * | Esercizio 2: matdump |
 * +----------------------+
 * Scrivere un programma che prende in ingresso un intero (piccolo, 
 * es. <=512), alloca in memoria una matrice di 512×512 elementi
 * float in modo che siano contigui in memoria. Inizializzare tale
 * matrice (M1) in modo arbitrario (ad esempio M1(i,j) = (i+j)/2.0).
 * Fare quindi il dump della matrice in formato binario su un file il
 * cui nome è 'mat_dump.dat'. Rileggere quindi la matrice dal file
 * 'mat_dump.dat' memorizzandola in una matrice differente da quella
 * di partenza (chiamata M2). Al termine dell'operazione di lettura
 * effettuare il confronto delle due matrici con la funzione
 * 'confronta'. Tale funzione deve essere implementata in modo
 * “generico” cioe' prende come argomenti un puntatore a funzione con
 * tipo opportuno, il puntatore alle due matrici da confrontare e la
 * size. Testare il programma passando alla funzione 'confronta' la
 * funzione di libreria memcmp (man 3 memcmp).
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matdump.h"


#define SIZE_LIMIT 31
#define RAISE(error_text) {						\
    printf("%s%s%s", "(Debug) >>> Errore: ", error_text, ". Interruzione.\n"); \
    return -1;								\
  }

int
main (int argc, char *argv[])
{
  // dichiarazione delle variabili sullo stack
  int size_value, i, j;
  int debug = 1;		// 1 per TRUE

  // controllo preliminare degli argomenti passati
  if (args_OK (argc) == 0)
    RAISE ("e' necessario passare uno e un solo argomento")
      // prendo in ingresso un intero
      if (input_int_OK (argv[1], &size_value) == 0)
      RAISE
	("e' necessario che l'argomento fornito sia un numero naturale valido")
	// verifico che il numero sia abbastanza piccolo
	if (size_value <= 0 || size_value > SIZE_LIMIT)
	RAISE ("e' necessario che (0 < num <= 31)")
	  // corpo principale del programma
	  if (debug)
	  printf
	    ("Condizioni preliminari verificate, intero fornito: %d. Continuo...\n",
	     size_value);

  // alloco in memoria una matrice M1 di num×num elementi
  // float in modo che siano contigui in memoria.
  float *M1 = malloc (size_value * size_value * sizeof (float));

  // inizializzare tale matrice (M1) in modo arbitrario
  // (ad esempio M1(i,j) = (i+j)/2.0).
  for (i = 0; i < size_value; i++)
    for (j = 0; j < size_value; j++)
      M1[size_value * i + j] = (i + j) / 2.0;
  if (debug)
    show_square_matrix (M1, size_value);

  // faccio quindi il dump della matrice in formato binario
  // su un file il cui nome è 'mat_dump.dat'.
  FILE *M1_bin = fopen ("mat_dump.dat", "wb");
  dump (M1, M1_bin, size_value);

  // chiusura dei file aperti
  fclose (M1_bin);

  // liberazione della memoria dinamica allocata sullo heap
  free (M1);

  // end main
  return 0;
}

int
args_OK (int args_no)
{
  return (args_no == 2);
}

int
input_int_OK (char *input_string, int *size)
{
  int temp = 0;
  int result = 1;
  while (input_string[temp] != '\0')
    {
      if (!isdigit (input_string[temp]))
	{
	  // questo carattere non e' una cifra
	  result = 0;
	  break;
	}
      temp++;
    }				// end while
  *size = atoi (input_string);
  return result;
}

void
show_square_matrix (float *firstElement, int dim)
{
  int x, y;
  for (x = 0; x < dim; x++)
    {
      for (y = 0; y < dim; y++)
	printf ("%4.1f ", firstElement[x * dim + y]);
      printf ("\n");
    }
}

void
dump (float *matrice, FILE * file_binario, int dim)
{
  int m, n;
  for (m = 0; m < dim; m++)
    for (n = 0; n < dim; n++)
      fwrite (matrice + (m * dim + n), sizeof (float), 1, file_binario);
}
