#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_utils.h"
#include "parse_and_validate_input.h"

int
parse_and_validate_args (int argc, char *argv[], struct input_data *coda)
{
  /* Questa funzione popola la coda. Effettua inoltre alcuni controlli.
   * Se e` tutto OK restituisce 0, altrimenti -1.
   */

  int return_value = 0;

  // 1) controllo che argc sia maggiore o uguale a 2
  if (argc_check (argc) != 0)
    {
      fprintf (stderr, "Errore: numero di argomenti insufficiente.\n");
      return_value = -1;
    }

  // 2) popolo la lista e, al contempo, conteggio il numero delle opzioni
  int temp;
  int option_no = 0;
  for (temp = 1; temp < argc; temp++)
    {
      printf ("argv[%d] = %s\n", temp, argv[temp]);
      if (argv[temp][0] == '-')
	option_no++;
      else
	{
	  enqueue (argv[temp], coda);
	}
    }

  // 3) verifico che sia passata almeno una stringa che non sia un'opzione (nome di file)
  int file_no = argc - 1 - option_no;
  if (DEBUG)
    printf ("File_no = %d\n", file_no);
  if (file_no < 1)
    {
      fprintf (stderr,
	       "Errore: e` necessario indicare il nome di almeno un file.\n");
      return_value = -1;
    }

  // 4) controllo che la lunghezza massima dei nomi dei file sia rispettata
  int length_OK = check_filename_length (coda);
  if (length_OK != 1)
    {
      fprintf (stderr,
	       "Errore: il nome di un file puo` essere lungo al massimo 255 caratteri.\n");
      return_value = -1;
    }

  // 5) mostro la lista dei files
  if (DEBUG)
    show_file_list (coda);

  // 6) parsing delle opzioni con getopt
  int opt;
  int count_lines = 0;
  int count_words = 0;
  while ((opt = getopt (argc, argv, "lw")) != -1)
    {
      printf ("getopt_rv: %d\n", opt);
      switch (opt)
	{
	case 'l':
	  coda->count_lines = 1;
	  break;
	case 'w':
	  coda->count_words = 1;
	  break;
	default:
	  fprintf (stderr, "Uso: %s [-l -w] file1 [file2 file3 ...]\n",
		   argv[0]);
	  return_value = -1;
	}
    }
  if ((coda->count_lines + coda->count_words) == 0)
    {
      coda->count_lines = 1;
      coda->count_words = 1;
    }
  if (DEBUG)
    printf ("Conta linee: %d\n", count_lines);
  if (DEBUG)
    printf ("Conta parole: %d\n", count_words);

  // 7) parsing della lista dei file (verifico che esistano)
  int all_present = parse_file_list (coda);
  if (all_present == 0)
    {
      fprintf (stderr,
	       "Errore: file non esistente tra quelli specificati.\n");
      return_value = -1;
    }

  return return_value;
}

int
parse_file_list (struct input_data *coda)
{
  // controllo che i singoli file esistano effettivamente
  return 9;
}

int
argc_check (int arg_no)
{
  if (arg_no < 2)
    return -1;
  else
    return 0;
}

int
check_filename_length (struct input_data *list)
{
  return 0;
}
