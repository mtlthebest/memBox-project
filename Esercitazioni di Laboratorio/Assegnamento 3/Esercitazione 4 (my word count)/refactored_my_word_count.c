/* +----------------------------+
 * | Esercizio 4: my word count |
 * +----------------------------+
 *
 * Scrivere un programma che realizzi l'equivalente del comando Unix
 * wc limitatamente alle opzioni -l e -w (man 1 wc). Usare getopt per
 * il parsing degli argomenti (man 3 getopt). Se non vengono passate
 * opzioni, il programma stampa sia il numero di linee che il numero
 * di parole del/dei file i cui nomi sono passati come argomento
 * (mywc [-l -w] file1 [file2 file3 ...]).
 */

#include <stdio.h>
#include <stdlib.h>
#include "libs/my_utils.h"
#include "libs/parsing_utils.h"
#include "refactored_my_word_count.h"

int
main (int argc, char *argv[])
{
  // creazione struttura vuota, inizializzazione, allocazione su heap
  struct input_data queue;
  queue.numero_file = 0;
  queue.count_lines = 0;
  queue.count_words = 0;
  queue.primo = malloc (sizeof (struct element));

  // parsing e validazione dell'input
  int parse_result = parse_and_validate_args (argc, argv, &queue);
  if (parse_result == -1)
    {
      printf ("--- ERRORE ---\nInterruzione del programma.\n");
      free_mem (&queue);
      return -1;
    }

  // corpo principale del programma

  // liberazione memoria dinamica allocata sullo heap
  free_mem (&queue);

  // end main
  return 0;
}

int
parse_and_validate_args (int c, char **v, struct input_data *q)
{
  int temp;
  // controllo che argc sia maggiore o uguale a 2
  temp = step_one (c);
  // controllo lunghezza nomi file (max 255 caratteri)
  if (temp == 0)
    {
      temp = step_one_point_five (c, v);
      // popolo la lista e, al contempo, conteggio il numero delle opzioni
      if (temp == 0)
	{
	  temp = step_two (c, v, q);
	  // controllo che venga fornito il nome di almeno un file
	  if (temp == 0)
	    {
	      temp = step_three (c, q);
	      // parsing delle opzioni
	      if (temp == 0)
		{
		  temp = step_four (c, v, q);
		  // verifico l'esistenza dei file specificati
		  if (temp == 0)
		    temp = step_five (q);
		}
	    }
	}
    }
  if (DEBUG)
    printf ("Esito parsing: temp = %d\n", temp);
  return temp;
}
