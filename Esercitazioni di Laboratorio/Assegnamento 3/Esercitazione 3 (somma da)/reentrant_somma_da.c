/* +-----------------------+
 * | Esercizio 3: somma da |
 * +-----------------------+
 *
 * Scrivere un programma C che implementa una funzione somma con la
 * seguente segnatura:
 *
 * +----------------------------------------------------------------+
 * | int somma(int x);                                              |
 * +----------------------------------------------------------------+
 *
 * La funzione 'somma' aggiunge l'intero x (inserito dall'utente da
 * stdin) al valore calcolato fino a quel momento e ritornando la
 * somma algebrica. Il programma termina quando viene inserito
 * dall'utente un numero negativo. Il valore iniziale della somma
 * deve essere INIT_VALUE che viene definito a compilazione
 * utilizzando il flag -D. Il programma non deve fare uso di
 * variabili globali.
 *
 * Dare anche una implementazione rientrante della funzione 'somma'
 * ('somma_r').
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "reentrant_somma_da.h"

#define LENGTH_LIMIT 16

int
main ()
{
  // allocazione sullo stack delle variabili necessarie
  char input_string[LENGTH_LIMIT];
  int return_value = 0;
  int actual_value = INIT_VALUE;
  int input_integer;

  // stampo a video le istruzioni
  printf ("ISTRUZIONI:\n");
  printf
    ("1) Inserisci un numero intero maggiore o uguale a zero. Sara` sommato al valore precedente.\n");
  printf
    ("2) Inserisci un numero intero negativo per interrompere il programma.\n");
  printf
    ("3) La stringa fornita deve essere lunga al massimo %d caratteri.\n",
     LENGTH_LIMIT);

  // stampo a video il valore iniziale
  printf ("Valore di partenza: %d\n", actual_value);

  // ciclo principale del programma
  while (1)			// ciclo interrotto solo da errori o su comando dell'utente (input negativo)
    {
      // ricevo l'input dell'utente da stdin
      printf ("Inserisci un numero intero: ");
      fgets (input_string, LENGTH_LIMIT, stdin);

      // rimuovo il carattere di ritorno a capo dalla stringa
      strtok (input_string, "\n");

      // visualizzo la stringa inserita dall'utente
      if (DEBUG_MODE)
	printf ("Hai inserito la stringa: %s\n", input_string);

      // validazione dell'input: la stringa e` un numero intero valido?
      int valid = validate_integer (input_string);
      if (!valid)
	{
	  printf
	    ("Errore: stringa inserita non valida, devi inserire un numero intero. Interruzione.\n");
	  return_value = -1;
	  break;
	}
      else
	{
	  // converto la stringa in int
	  input_integer = atoi (input_string);

	  // eseguo la funzione rientrante somma_r
	  actual_value = somma_r (input_integer, actual_value);
	  printf ("Somma algebrica: %d\n", actual_value);

	  // controllo se il valore fornito dall'utente e` negativo
	  if (input_integer < 0)
	    {
	      printf ("Rilevato input negativo, uscita dal programma.\n");
	      break;
	    }
	}
    }				// end while

  // end main
  return return_value;
}

int
somma_r (int nuovo_addendo, int accumulatore)
{
  /* Versione rientrante della funzione 'somma' ('somma_r').
   * +----------------------+
   * | Rules for reentrancy |
   * +----------------------+
   *
   * 1) Reentrant code may not hold any static (or global)
   *    non-constant data;
   * 2) Reentrant code may not modify its own code;
   * 3) Reentrant code may not call non-reentrant computer programs
   *    or routines.
   */

  return accumulatore + nuovo_addendo;
}

int
validate_integer (char *input_string)
{
  int temp;
  if (input_string[0] == '-')
    {
      temp = 1;			// numero negativo
      if (DEBUG_MODE)
	printf ("Validate: numero negativo?\n");
    }
  else
    {
      temp = 0;			// numero positivo
      if (DEBUG_MODE)
	printf ("Validate: numero positivo?\n");
    }
  int result = 1;		// 1 significa numero intero valido
  while (input_string[temp] != '\0')
    {
      if (DEBUG_MODE)
	printf ("Validate: analizzo il carattere '%c'...\n",
		input_string[temp]);
      if (!isdigit (input_string[temp]))
	{
	  // questo carattere non e' una cifra
	  result = 0;		// 0 significa numero intero non valido
	  break;
	}
      temp++;
    }				// end while
  return result;
}
