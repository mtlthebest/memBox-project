/* Scrivere una seconda versione del programma precedente che
 * implementa la funzione 'tokenizer_r' che ha la stessa
 * identica interfaccia, ma che utilizza al suo interno
 * strtok_r invece di strtok. Quali sono le principali
 * differenze tra 'tokenizer' e 'tokenizer_r' ? (Suggerimento:
 * leggere con attenzione il man di strtok_r).
 * NOTA: se si utilizza l'opzione -std=c99, per evitare i
 * warnings del tipo implicit declaration of function
 * 'strtok_r'… aggiungere la seguente opzione di compilazione
 * -D_POSIX_C_SOURCE=200112L. La funzione strtok_r fa parte
 * dello standard POSIX-2001.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer_r.h"

int
main (int argc, char *argv[])
{
  // nessuna stringa fornita
  if (argc <= 1)
    return 0;

  // fornita almeno una stringa
  else
    {
      int i;
      for (i = 1; i < argc; i++)
	tokenizer_r (argv[i], stdout);
      return 0;
    }
}

void
tokenizer_r (char *stringa, FILE * out)
{
  char delimitatore[] = " ";
  char *token;
  char **save_pointer = malloc (sizeof (char *));
  token = strtok_r (stringa, delimitatore, save_pointer);
  while (token != NULL)
    {
      fprintf (out, "%s\n", token);
      token = strtok_r (NULL, delimitatore, save_pointer);
    }
  free (save_pointer);
}
