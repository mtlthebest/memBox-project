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
#include <string.h>
#include <stdlib.h>

#define LENGTH_LIMIT 64

struct elemento_lista
{
  int conteggio;
  char nome_file[LENGTH_LIMIT];
  struct elemento_lista *next;
};

#include "my_word_count.h"

int
main (int argc, char *argv[])
{
  int lines = my_lines_count (argv[1]);

  struct elemento_lista fla;
  fla.conteggio = lines;
  strcpy (fla.nome_file, argv[1]);

  struct elemento_lista foo;
  foo.conteggio = 23;
  strcpy (foo.nome_file, "johnny.txt");

  struct elemento_lista bar;
  bar.conteggio = 5;
  strcpy (bar.nome_file, "pippo.bat");

  struct elemento_lista foo_bar;
  foo_bar.conteggio = 21;
  strcpy (foo_bar.nome_file, "mtl.java");

  fla.next = &foo;
  foo.next = &bar;
  bar.next = &foo_bar;
  foo_bar.next = NULL;

  show_results (&fla);

  return 0;
}

void
show_results (struct elemento_lista *lista)
{
  struct elemento_lista *cursore = lista;
  int total = 0;
  while (cursore != NULL)
    {
      total += cursore->conteggio;
      printf ("%4d ", cursore->conteggio);
      printf ("%s\n", cursore->nome_file);
      cursore = cursore->next;
    }
  printf ("%4d totale\n", total);
}

int
my_lines_count (char *file_name)
{
  int conteggio = 0;
  FILE *temp = fopen (file_name, "r");
  char *text_line = malloc (LENGTH_LIMIT * sizeof (char));	// MSG style
  char *fgets_result;
  int i = 0;
  do
    {
      i++;
      printf ("\nIterazione #%d\n", i);
      fgets_result = fgets (text_line, LENGTH_LIMIT, temp);
      printf ("Risultato di fgets: %s\n", fgets_result);
      if (fgets_result != NULL)
	{
	  strtok (fgets_result, "\n");	// rimozione newline
	  conteggio += tokenizer (text_line);
	}
      printf ("Conteggio attuale: %d\n", conteggio);
    }
  while (fgets_result != NULL);

  fclose (temp);
  free (text_line);
  return conteggio;
}

int
tokenizer (char *stringa)
{
  int count = 0;
  char delimitatore[] = " ";
  char *token;
  token = strtok (stringa, delimitatore);
  if (token == NULL)
    return 0;
  else
    {
      while (token != NULL)
	{
	  count++;
	  printf ("TOKEN: %s\n", token);
	  token = strtok (NULL, delimitatore);
	}
    }
  return count;
}
