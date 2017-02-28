/* +-------------------------------+
 * | Esercizio 3: matdump testuale |
 * +-------------------------------+
 * Riscrivere l'Esercizio 2 dell'Assegnamento3 considerando matrici
 * NxM facendo il dump della matrice in un file testuale invece che
 * binario. Scrivere nelle prime due righe del file il numero di
 * righe (N) e di colonne (M), rispettivamente. Ogni riga del file
 * contiene 1 solo valore. Scrivere il Makefile per compilare il
 * programma.
 */

// --- consegne qui sotto ---

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

#define ELEM(matrice, x, y) *(matrice + (x * dimM) + y)
#define PRINTMAT(matrice)				\
  char name[] = #matrice;				\
  printf("Stampo la matrice %s:\n", name);		\
  for(int p = 0; p < dimN; p++)				\
    {							\
      for (int q = 0; q < dimM; q++)			\
	printf("%5.1f ", ELEM(matrice, p, q));		\
      printf("\n");					\
    }

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{

  /* +--------------------------+
   * | 1. Preparazione ambiente |
   * +--------------------------+
   */

  /* +--------------------------------+
   * | 2. Parsing e validazione input |
   * +--------------------------------+
   */
  // Prendo in ingresso due interi N e M (piccoli, ad es. 256 e 512)
  int dimN = atoi (argv[1]);
  int dimM = atoi (argv[2]);

  /* +-----------------------------------+
   * | 3. Corpo principale del programma |
   * +-----------------------------------+
   */
  // Alloco in memoria una matrice di N×M elementi float in modo che
  // siano contigui in memoria.
  float *M1 = (float *) malloc (sizeof (float) * dimN * dimM);

  // Inizializzo tale matrice (M1) in modo arbitrario (ad esempio
  // M1(i,j) = (i+j)/2.0).
  int i;
  int j;
  for (i = 0; i < dimN; i++)
    {
      for (j = 0; j < dimM; j++)
	{
	  ELEM (M1, i, j) = (i + j) / 2.0;
	}
    }
  if (DEBUG)
    {
      PRINTMAT (M1);
    }

  // Faccio quindi il dump della matrice in formato testuale su un
  // file il cui nome è 'mat_dump.txt'.



  /* +----------------------+
   * | 4. Operazioni finali |
   * +----------------------+
   */
  // liberazione memoria dinamica
  free (M1);

  // end main
  return 0;
}
