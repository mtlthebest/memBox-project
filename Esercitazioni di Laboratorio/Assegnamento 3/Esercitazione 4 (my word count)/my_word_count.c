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

#define FILENAME_LENGTH_LIMIT 256

struct elemento_lista
{
  int conteggio;
  char nome_file[FILENAME_LENGTH_LIMIT];
  struct elemento_lista *next;
};

#include "my_word_count.h"

int
main (int argc, char *argv[])
{
  struct elemento_lista foo;
  foo.conteggio = 23;
  strcpy (foo.nome_file, "johnny.txt");

  struct elemento_lista bar;
  bar.conteggio = 5;
  strcpy (bar.nome_file, "pippo.bat");

  struct elemento_lista foo_bar;
  foo_bar.conteggio = 21;
  strcpy (foo_bar.nome_file, "mtl.java");

  foo.next = &bar;
  bar.next = &foo_bar;
  foo_bar.next = NULL;

  count_words (&foo);

  return 0;
}

void
count_words (struct elemento_lista *lista)
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
