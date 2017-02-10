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
 * Dare anche una implementazione rientrante della funziona 'somma'
 * ('somma_r').
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "somma_da.h"

int
main (int argc, char *argv[])
{
  // controlli preliminari

  // ciclo principale del programma
  int current_value = INIT_VALUE;
  printf ("INIT_VALUE: %d\n", current_value);
  char *input = malloc (32 * sizeof (char));
  while (1)
    {
      printf ("Inserisci un numero intero: ");
      fgets (input, 32, stdin);
      printf ("Hai inserito questo numero: %s\n", input);
      if (!input_int_OK (input, &current_value))
	printf ("ERRORE!");
      if (exit_signal (input))
	break;
      // libero la memoria dinamica allocata sullo heap
      free (input);
      // end main
      return 0;
    }
}

int
somma (int x)
{
  int somma_algebrica = x;
  return somma_algebrica;
}

int
exit_signal (char *signal)
{
  if (signal[0] == '-')
    {
      printf ("Rilevato numero intero negativo. Uscita dal programma.\n");
      return 1;
    }
  else
    return 0;
}

int
input_int_OK (char *input_string, int *value)
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
  *value = *value + atoi (input_string);
  return result;
}
