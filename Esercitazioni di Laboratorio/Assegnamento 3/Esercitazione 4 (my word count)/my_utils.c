#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_utils.h"

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
  struct element *prec;
  struct element *cur = to_empty->primo;
  do
    {
      prec = cur;
      cur = cur->next;
      free (prec);
    }
  while (cur != NULL);
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
  for (x = 0; x < input->numero_file - 1; x++)
    cur = cur->next;		// qui vale (cur == NULL)

  // alloco la memoria necessaria
  cur->next = malloc (sizeof (struct element));

  // aggiorno i contenuti
  strcpy (cur->next->filename, stringa);
  cur->next->next = NULL;
  input->numero_file++;

  // info di debug
  printf ("... enqueue() eseguita.\n");
}
