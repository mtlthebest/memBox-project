/* Esercizio 2: matdump
 * Scrivere un programma che prende in ingresso un intero (piccolo, 
 * es. <=512), alloca in memoria una matrice di 512×512 elementi float 
 * in modo che siano contigui in memoria. Inizializzare tale matrice
 * (M1) in modo arbitrario (ad esempio M1(i,j) = (i+j)/2.0). Fare
 * quindi il dump della matrice in formato binario su un file il cui
 * nome è 'mat_dump.dat'. Rileggere quindi la matrice dal file
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
#include <string.h>
#include "matdump.h"

int
main (int argc, char *argv[])
{

  // dichiarazione variabili sullo stack
  int *dim = NULL;
  int i = 0;

  // dichiarazione variabili sullo heap
  dim = malloc (sizeof (int));
  float *matrice = NULL;

  // controllo input
  if (argc != 2)
    {
      printf
	(">>> Debug: eseguo main()... Errore: fornire uno e un solo argomento in ingresso.\n");
      return 1;
    }
  else
    {

      if (is_int (argv[1], dim) == 0)
	{
	  printf (">>> Debug: main, is_int eseguito con successo e == 0.\n");

	  if (*dim > 0 && *dim <= 512)
	    {
	      // OK. Creo la matrice (allocazione memoria)
	      matrice = malloc ((*dim) * (*dim) * sizeof (float));
	      if (matrice == NULL)
		{
		  printf
		    (">>> Debug: eseguo main()... Errore: malloc per memoria matrice ha avuto esito negativo.\n");
		}

	      else
		{
		  // inizializzo la matrice a valori arbitrari
		  for (i = 0; i < ((*dim) * (*dim)); i++)
		    matrice[i] = i;
		  // verifico il contenuto della matrice
		  stampaMatrice (matrice, *dim);
		}


	      printf ("OK, esec normale...\nIntero: %d\n", *dim);
	      return 0;
	    }
	  else
	    {
	      printf
		(">>> Debug: eseguo main()... Errore: fornire un numero intero compreso tra 1 e 512.\n");
	      return 1;
	    }
	}
      printf
	(">>> Debug: eseguo main()... Errore: fornire un numero intero valido.\n");
      return 1;
    }
}

int
is_int (char *p, int *size)
{
  // semantica: se intero, restituisce ZERO
  // altrimenti (numero non intero o in caso di problemi)
  // restituisce numero diverso da zero

  printf (">>> Debug: eseguo is_int()...\n");
  int result = 1;		// default: UNO, FALSO
  *size = atoi (p);
  printf (">>> Debug: *size aggiornato: valore %d\n", *size);
  char *pippo = malloc (4 * sizeof (char));
  int temp = sprintf (pippo, "%d", *size);
  if (temp <= 0)
    {
      if (temp == 0)
	{
	  printf
	    (">>> Debug: eseguo is_int()...\nErrore: lunghezza nulla.\n");
	  result = 1;
	}
      else
	{
	  result = temp;	// result e' minore di zero
	  printf
	    (">>> Debug: eseguo is_int()...\nErrore: il risultato di sprintf e' < 0.\n");
	}
    }
  else
    result = (strcmp (pippo, p));	// se stringhe identiche, ZERO (VERO)
  free (pippo);
  printf (">>> Debug: eseguita is_int(). OK.\n");
  return result;
}

void
stampaMatrice (float *primoElemento, int num)
{
  int i, j;
  for (i = 0; i < num; i++)
    {
      for (j = 0; j < num; j++)
	{
	  printf ("%2.1f ", primoElemento[num * i + j]);
	}
      printf ("\n");
    }
}
