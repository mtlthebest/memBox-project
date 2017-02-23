#define MAX_LENGTH 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_utils.h"

void
show_all_contents (struct input_data *data)
{
  printf ("--- Inizio contenuti ---\n");
  printf ("Numero opzioni: %d\n", data->numero_opzioni);
  printf ("Numero file: %d\n", data->numero_file);
  printf ("Count lines: %d\n", data->count_lines);
  printf ("Count words: %d\n", data->count_words);
  show_file_list (data);
  printf ("--- Fine contenuti ---\n");
}

void
show_file_list (struct input_data *info)
{
  if (DEBUG)
    printf ("Eseguo show_file_list()...\n");
  struct element *cursore = info->primo;
  int i;

  for (i = 0; i < info->numero_file; i++)
    {
      printf ("File: %s\n", cursore->filename);
      cursore = cursore->next;
    }
  if (DEBUG)
    printf ("... show_file_list() eseguita.\n");
}

void
free_mem (struct input_data *to_empty)
{
  if (DEBUG)
    printf ("Eseguo free_mem()...\n");

  struct element *prec;
  struct element *cur = to_empty->primo;
  if (to_empty->numero_file == 0)
    {
      free (cur);
    }
  else
    do
      {
	prec = cur;
	cur = cur->next;
	free (prec);
      }
    while (cur != NULL);
  if (DEBUG)
    printf ("... free_mem() eseguita.\n");
}

void
enqueue (char *stringa, struct input_data *input)
{
  // info di debug
  if (DEBUG)
    printf ("Eseguo enqueue()...\n");

  // porto il cursore nella posizione corretta
  struct element *cur = input->primo;
  int x;
  if (input->numero_file != 0)
    {
      for (x = 0; x < input->numero_file - 1; x++)
	cur = cur->next;
      cur->next = malloc (sizeof (struct element));
      strcpy (cur->next->filename, stringa);
      cur->next->next = NULL;
    }
  else
    {
      strcpy (cur->filename, stringa);
      cur->next = NULL;
    }
  input->numero_file++;

  // info di debug
  printf ("... enqueue() eseguita.\n");
}

int
my_lc (char *f, int *totale)
{
  if (DEBUG)
    printf ("Esecuzione my_lc()...\n");

  // conta il numero di linee presenti in un file
  int i;
  int count = 0;
  char block[MAX_LENGTH];
  FILE *x = fopen (f, "r");
  if (DEBUG)
    printf ("my_lc(): aperto file %s in sola lettura.\n", f);
  while (fgets (block, MAX_LENGTH, x) != NULL)
    {
      if (DEBUG)
	printf ("my_lc(): dentro ciclo while...\n");
      for (i = 0; i < MAX_LENGTH; i++)
	{
	  if (DEBUG)
	    printf ("block[i] = %c\n", block[i]);
	  if (block[i] == '\0')
	    break;
	  else if (block[i] == '\n')
	    count++;
	}			// end for
    }				// end while

  // chiusura del file aperto
  fclose (x);
  if (DEBUG)
    printf ("my_lc(): chiuso file %s.\n", f);

  // aggiornamento accumulatore
  *totale += count;
  if (DEBUG)
    printf ("my_lc(): count = %d.\n", count);
  return count;
}

int
my_wc (char *f, int *totale)
{
  return 0;
}
