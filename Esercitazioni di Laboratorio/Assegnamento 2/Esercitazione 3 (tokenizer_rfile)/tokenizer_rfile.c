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

#define LIMIT 1024

// definizione struttura per i singoli token
struct token_element
{
  struct token_element *precedente;
  char *stringa_1K_token;
  struct token_element *successivo;
};

// definizione struttura per le righe estratte
struct elemento_lista_doppia
{
  struct elemento_lista_doppia *precedente;
  char *stringa_1K;
  int token_count;
  struct token_element *token_list;
  struct elemento_lista_doppia *successivo;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer_rfile.h"

int
main (int argc, char *argv[])
{
  if (argc <= 2)
    {
      fprintf (stderr, "Errore: fornire almeno due argomenti.\n");
      return 0;
    }
  else if (argc >= 5)
    {
      fprintf (stderr, "Errore: fornire al piu' tre argomenti.\n");
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
	  // FASE 1: SEPARAZIONE DELLE RIGHE
	  // il file di input esiste, procedo con l'esecuzione del programma
	  printf ("File di input: \"%s\".\n", argv[1]);

	  // apro il file di output
	  FILE *testo_out;
	  if (argc == 4 && (strcmp (argv[3], "a") == 0))
	    {
	      testo_out = fopen (argv[2], "a");
	      printf
		("File di output: \"%s\" (utilizzato in modalita' append).\n",
		 argv[2]);

	    }
	  else
	    {

	      testo_out = fopen (argv[2], "w");
	      printf
		("File di output: \"%s\" (utilizzato in modalita' creazione/sovrascrittura).\n",
		 argv[2]);
	    }

	  // creazione delle variabili necessarie sullo stack
	  int numero_righe = 0;
	  char *temp = malloc ((LIMIT + 1) * sizeof (char));	// max 1K caratteri + '\0
	  struct elemento_lista_doppia *base;
	  struct elemento_lista_doppia *cur;
	  int i;

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
	      numero_righe++;
	    }

	  // proseguo iterativamente con la creazione degli elementi
	  // della lista doppia
	  cur = base;		// imposto il cursore  
	  while (fgets (temp, LIMIT + 1, testo_in) != NULL)
	    {
	      // allocazione memoria per l'elemento successivo
	      cur->successivo =
		malloc (sizeof (struct elemento_lista_doppia));

	      // popolamento dell'elemento successivo
	      cur->successivo->precedente = cur;
	      cur->successivo->stringa_1K =
		malloc ((LIMIT + 1) * sizeof (char));
	      strcpy (cur->successivo->stringa_1K, temp);
	      cur->successivo->successivo = NULL;

	      // incremento del contatore degli elementi della lista
	      numero_righe++;

	      // definizione del nuovo cursore
	      cur = cur->successivo;
	    }

	  // FASE 2: ESECUZIONE FUNZIONE TOKENIZER PER OGNI RIGA
	  // impostazione del cursore
	  cur = base;
	  for (i = 0; i < numero_righe; i++)
	    {
	      cur->token_list = malloc (sizeof (struct token_element));
	      cur->token_list->precedente = NULL;
	      cur->token_list->successivo = NULL;
	      cur->token_count =
		tokenizer_rfile (cur->stringa_1K, cur->token_list);
	      cur = cur->successivo;
	    }

	  // FASE 3: SCRITTURA OUTPUT (SENSO INVERSO)
	  // posizionamente cursore sull'ultimo elemento
	  cur = base;
	  for (i = 0; i < numero_righe - 1; i++)
	    cur = cur->successivo;
	  for (i = 0; i < numero_righe; i++)
	    {
	      reverse_write_tokens (cur->token_list, cur->token_count,
				    testo_out);
	      // printf ("debug: qui sono arrivato.\n");
	      cur = cur->precedente;
	    }

	  // FASE 4: OPERAZIONI FINALI
	  // chiusura dei file di input e output
	  fclose (testo_in);
	  fclose (testo_out);

	  // libero la memoria dinamica assegnata alla lista doppia
	  free (temp);
	  cur = base;
	  struct elemento_lista_doppia *prev = cur;

	  for (i = 0; i < numero_righe; i++)
	    {
	      prev = cur;	// prev e' il nodo su cui lavoro
	      cur = cur->successivo;	// metto cur al sicuro sull'elemento successivo
	      prev->precedente = NULL;	// prev: inizio la cancellazione dell'item
	      free (prev->stringa_1K);
	      free_memory (prev->token_list, prev->token_count);	// chiamo una funzione apposita
	      prev->successivo = NULL;
	      free (prev);
	    }

	  // end main
	  return 0;
	}
    }

}

int
tokenizer_rfile (char *riga_testo, struct token_element *base)
{
  int count = 0;
  struct token_element *cursore = base;
  char delimitatore[] = " ";
  char *token;
  char **save_pointer = malloc (sizeof (char *));
  char **save_pointer_bis = malloc (sizeof (char *));
  token = strtok_r (riga_testo, delimitatore, save_pointer);
  while (token != NULL)
    {
      if (count > 0)
	{			// gestione del cursore
	  cursore->successivo = malloc (sizeof (struct token_element));
	  cursore->successivo->precedente = cursore;
	  cursore->successivo->successivo = NULL;
	  cursore = cursore->successivo;
	}
      cursore->stringa_1K_token = malloc ((LIMIT + 1) * sizeof (char));
      strtok_r (token, "\n", save_pointer_bis);	// eliminina eventuali "\n"
      strcpy (cursore->stringa_1K_token, token);
      count++;
      // printf ("debug >>> Token: %s\n", cursore->stringa_1K_token);
      token = strtok_r (NULL, delimitatore, save_pointer);
    }
  free (save_pointer);
  free (save_pointer_bis);
  return count;
}

void
reverse_write_tokens (struct token_element *item, int numero_token,
		      FILE * output)
{
  struct token_element *cursore = item;
  int x;
  for (x = 0; x < numero_token - 1; x++)
    cursore = cursore->successivo;
  for (x = numero_token; x > 0; x--)
    {
      fprintf (output, "%s\n", cursore->stringa_1K_token);
      cursore = cursore->precedente;
    }
}

void
free_memory (struct token_element *item, int numero_token)
{
  struct token_element *cur = item;
  struct token_element *prev;
  int j;
  for (j = 0; j < numero_token; j++)
    {
      prev = cur;		// prev e' il nodo su cui lavoro
      cur = cur->successivo;	// metto cur al sicuro sull'elemento successivo
      prev->precedente = NULL;	// prev: inizio la cancellazione dell'item
      free (prev->stringa_1K_token);
      prev->successivo = NULL;
      free (prev);
    }
}
