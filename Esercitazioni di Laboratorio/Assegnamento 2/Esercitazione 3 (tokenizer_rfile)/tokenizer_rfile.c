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
#include <string.h>

#define LIMIT 1024

struct elemento_lista_doppia
{
  struct elemento_lista_doppia *precedente;
  char *stringa_1K;
  struct elemento_lista_doppia *successivo;
  int matricola;
};

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
	  // il file di input esiste, procedo con l'esecuzione del programma

	  // creazione delle variabili necessarie sullo stack
	  int parole = 0;
	  char *temp = malloc ((LIMIT + 1) * sizeof (char));	// max 1K caratteri + '\0
	  struct elemento_lista_doppia *base;
	  struct elemento_lista_doppia *cur;

	  // gestisco il primo elemento della lista doppia
	  char *feedback = NULL;
	  feedback = fgets (temp, LIMIT + 1, testo_in);
	  if (feedback != NULL)
	    {
	      // esiste almeno una parola, creo il primo elemento della
	      // lista doppia e popolo l'elemento di base
	      base = malloc (sizeof (struct elemento_lista_doppia));
	      base->precedente = NULL;
	      base->stringa_1K = malloc ((LIMIT + 1) * sizeof (char));
	      strcpy (base->stringa_1K, temp);
	      base->successivo = NULL;
	      parole++;
	      printf ("--> base content: %s\n", base->stringa_1K);	// debug
	      printf
		("Debug: elemento di base creato e popolato con successo.\n");
	    }

	  // proseguo iterativamente con la creazione degli elementi
	  // della lista doppia
	  cur = base;		// imposto il cursore  
	  while (fgets (temp, LIMIT + 1, testo_in) != NULL)
	    {
	      printf ("Debug: sono dentro il ciclo while.\n");
	      // allocazione memoria per l'elemento successivo
	      cur->successivo =
		malloc (sizeof (struct elemento_lista_doppia));

	      // popolamento dell'elemento successivo
	      cur->successivo->precedente = cur;
	      cur->successivo->stringa_1K =
		malloc ((LIMIT + 1) * sizeof (char));
	      strcpy (cur->successivo->stringa_1K, temp);
	      cur->successivo->successivo = NULL;

	      // debug
	      printf ("--> cursor content: %s\n",
		      cur->successivo->stringa_1K);

	      // definizione del nuovo cursore
	      cur = cur->successivo;

	      // incremento del contatore degli elementi della lista
	      parole++;
	    }
	  printf ("Numero di parole: %d\n", parole);

	  // operazioni finali
	  // chiusura del file di input
	  fclose (testo_in);

	  // libero la memoria dinamica assegnata alla lista doppia
	  free (temp);
	  while (0)
	    {
	      // libero iterativamente tutta la memoria assegnata agli elementi
	      // free();
	    }
	  if (feedback != NULL)
	    {
	      free (base->stringa_1K);
	      free (base);
	    }

	  return 0;
	}
    }
}
