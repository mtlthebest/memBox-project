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

#define FILENAME_MAX_LENGTH 255

struct lista
{
  char nomefile[64];
  struct lista *next;
};

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "refactored_my_word_count.h"

int
main (int argc, char *argv[])
{
  // controllo preliminari
  // 1) argc deve essere almeno uguale a 2
  if (DEBUG)
    printf ("argc = %d\n", argc);
  if (argc < 2)
    {
      fprintf (stderr, "Errore: numero di argomenti insufficiente.\n");
      return (-1);
    }

  // 2) deve essere passata almeno una stringa che non sia un'opzione (nome di file)
  int temp;
  int option_no = 0;

  // creo la lista vuota che conterra` i nomi dei file
  struct lista *file_list = malloc (sizeof (struct lista));

  for (temp = 1; temp < argc; temp++)
    {
      printf ("argv[%d] = %s\n", temp, argv[temp]);
      if (argv[temp][0] == '-')
	option_no++;
      else
	{
	  // inserisco il nome del file nella lista
	  enqueue (argv[temp], file_list);
	}
    }
  int file_no = argc - 1 - option_no;
  if (DEBUG)
    printf ("File_no = %d\n", file_no);
  if (file_no < 1)
    {
      fprintf (stderr,
	       "Errore: e` necessario indicare il nome di almeno un file.\n");
      return (-1);
    }

  // mostro la lista dei files
  printf ("************\n");
  show_file_list (file_list);

  // parsing delle opzioni
  int opt;
  int count_lines = 0;
  int count_words = 0;
  while ((opt = getopt (argc, argv, "lw")) != -1)
    {
      printf ("getopt_rv: %d\n", opt);
      switch (opt)
	{
	case 'l':
	  count_lines = 1;
	  break;
	case 'w':
	  count_words = 1;
	  break;
	default:
	  fprintf (stderr, "Uso: %s [-l -w] file1 [file2 file3 ...]\n",
		   argv[0]);
	  return (-1);
	}
    }
  if ((count_lines + count_words) == 0)
    {
      count_lines = 1;
      count_words = 1;
    }
  if (DEBUG)
    printf ("Conta linee: %d\n", count_lines);
  if (DEBUG)
    printf ("Conta parole: %d\n", count_words);

  // parsing della lista dei file
  parse_file_list (argc, argv, file_list);

  // libero la memoria allocata dinamicamente sullo heap
  free_mem (file_list);

  // end main
  return 0;
}

void
parse_file_list (int argc, char *argv[], struct lista *file_list)
{
}

void
enqueue (char *input, struct lista *lista_file)
{
  if (DEBUG)
    printf ("Inside enqueue()...\n");
  struct lista *cur = lista_file;

  // porto il cursore in fondo alla lista
  while (cur != NULL)
    cur = cur->next;

  // alloco la memoria necessaria
  cur = malloc (sizeof (struct lista));
  strcpy (cur->nomefile, input);
  cur->next = NULL;
}

void
free_mem (struct lista *to_empty)
{
  struct lista *prec;
  struct lista *cur = to_empty;
  do
    {
      prec = cur;
      cur = cur->next;
      free (prec);
    }
  while (cur != NULL);
}

void
show_file_list (struct lista *files)
{
  printf ("INSIDE SHOW FILE LIST\n");
  struct lista *cursore = files;
  while (cursore != NULL)
    {
      printf ("File: %s\n", cursore->nomefile);
      cursore = cursore->next;
    }
}
