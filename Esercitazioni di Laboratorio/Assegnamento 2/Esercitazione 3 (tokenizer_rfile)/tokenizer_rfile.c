/* Scrivere un programma C che prende in input 3 argomenti, i primi
 * due argomenti sono obbligatori, il terzo e' opzionale. Il primo
 * argomento è il nome di un file di input in formato testuale
 * contenente stringhe di parole. Ogni stringa ha una lunghezza
 * massima pari a 1024 caratteri. Il secondo argomento corrisponde ad
 * un file testuale di output che dovra' contenere tutte le parole
 * del primo file, scritte al contrario una per ogni riga. Se il file
 * di input non esiste, il programma dovrà ritornare un messaggio di
 * errore opportuno sullo standard error (stderr). Se il file di
 * output esiste questo dovra' essere sovrascritto se il terzo
 * argomento del programma non è stato specificato, oppure se tale
 * argomento è diverso dal carattere 'a'. Se il terzo argomento è
 * uguale al carattere 'a' l'output del programma dovrà essere appeso
 * in fondo al file.
 */

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  if (argc <= 2)
    {
      printf ("Errore: fornire almeno due argomenti.\n");
      return 0;
    }
  else if (argc >= 5)
    {
      printf ("Errore: fornire al piu' tre argomenti.\n");
      return 0;
    }
  else
    {
      // ciclo principale del programma
      FILE *testo_in = fopen (argv[1], "r");
      if (testo_in == NULL)
	{
	  fprintf (stderr, "Errore: il file di input \"%s\" non esiste.\n",
		   argv[1]);
	  return 0;
	}
      else
	{
	  // ogni stringa potra' occupare al massimo 1024 caratteri
	  char *a = malloc (1025 * sizeof (char));
	  int parole = 0;
	  while (fscanf (testo_in, "%s", a) != EOF)
	    {
	      printf ("--> fscanf content: %s\n", a);
	      parole++;
	    }
	  printf ("Numero di stringhe: %d\n", parole);
	  fclose (testo_in);
	  free (a);
	  return 0;
	}
    }
}
