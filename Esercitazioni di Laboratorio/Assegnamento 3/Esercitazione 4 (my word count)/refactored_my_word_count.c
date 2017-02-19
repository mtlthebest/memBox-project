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

struct lista
{
  char *nomefile;
  struct lista *next;
};

#include <unistd.h>
#include <stdio.h>
#include "refactored_my_word_count.h"

int
main (int argc, char *argv[])
{
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
  struct lista file_list;
  parse_file_list (argc, argv, &file_list);

  // end main
  return 0;
}

void
parse_file_list (int argc, char *argv[], struct lista *file_list)
{
}
