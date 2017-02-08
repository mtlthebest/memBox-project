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

#define RAISE(error_text) {						\
    printf("%s%s%s", "(Debug) >>> Errore: ", error_text, ". Interruzione.\n"); \
    return -1;								\
  }

int
main (int argc, char *argv[])
{
  // dichiarazione delle variabili sullo stack
  int size_value;
  int *size_pointer = &size_value;

  // controllo preliminare degli argomenti passati
  if (args_OK (argc) == 0)
    RAISE ("e' necessario passare uno e un solo argomento");

  // prendo in ingresso un intero
  if (input_int_OK (argv[1], size_pointer) == 0)
    {
    RAISE
	("e' necessario che l'argomento fornito sia un numero naturale valido")}

  // verifico che il numero sia abbastanza piccolo
  if (size_value <= 0 || size_value > 1024)
    {
      RAISE ("e' necessario che (0 < num <= 1024)");
    }


  // corpo principale del programma
  printf
    ("Condizioni preliminari verificate, intero fornito: %d. Continuo...\n",
     size_value);

  // liberazione della memoria dinamica allocata sullo heap

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
