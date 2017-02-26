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
  int i;
  int l_total = 0;
  int w_total = 0;
  struct element *cur = queue.primo;

  // calcolo l'ampiezza massima della mantissa
  int mantissa = 0;
  int foo = 0;
  for (i = 0; i < queue.numero_file; i++)
    {
      if (queue.count_lines)
	{
	  foo = calcola_cifre (my_lc (cur->filename, &l_total));
	  if (mantissa < foo)
	    mantissa = foo;
	}
      if (queue.count_words)
	{
	  foo = calcola_cifre (my_wc (cur->filename, &w_total));
	  if (mantissa < foo)
	    mantissa = foo;
	}
      cur = cur->next;
    }
  if (queue.numero_file > 1)
    {
      // stampo anche i totali nel caso di piu` file
      if (queue.count_lines)
	{
	  foo = calcola_cifre (l_total);
	  if (mantissa < foo)
	    mantissa = foo;
	}
      if (queue.count_words)
	{
	  foo = calcola_cifre (w_total);
	  if (mantissa < foo)
	    mantissa = foo;
	}
      if (DEBUG)
	printf ("Mantissa: %d\n", mantissa);
    }

  // per analogia con UNIX wc
  mantissa += 1;

  // stampa a video
  // reimposto cursore e accumulatori
  cur = queue.primo;
  l_total = 0;
  w_total = 0;
  int j;
  for (i = 0; i < queue.numero_file; i++)
    {
      if (queue.count_lines)
	{
	  foo = my_lc (cur->filename, &l_total);
	  for (j = 0; j < mantissa - calcola_cifre (foo); j++)
	    printf (" ");
	  printf ("%d ", foo);
	}			// end first if
      if (queue.count_words)
	{
	  foo = my_wc (cur->filename, &w_total);
	  for (j = 0; j < mantissa - calcola_cifre (foo); j++)
	    printf (" ");
	  printf ("%d ", foo);
	}			// end second if
      printf ("%s\n", cur->filename);
      cur = cur->next;
    }				// end for

  if (queue.numero_file > 1)
    {
      // stampo anche i totali nel caso di piu` file
      if (queue.count_lines)
	{
	  for (j = 0; j < mantissa - calcola_cifre (l_total); j++)
	    printf (" ");
	  printf ("%d ", l_total);
	}
      if (queue.count_words)
	{
	  for (j = 0; j < mantissa - calcola_cifre (w_total); j++)
	    printf (" ");
	  printf ("%d ", w_total);
	}
      printf ("totale\n");
    }				// end if

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
