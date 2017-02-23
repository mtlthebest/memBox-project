/* Convenzione: se i controlli vanno a buon fine le funzioni
 * restituiscono 0, altrimenti restituiscono -1.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my_utils.h"
#include "parsing_utils.h"

int
step_one (int number_of_args)
{
  // controllo che argc sia maggiore o uguale a 2
  if (number_of_args < 2)
    {
      fprintf (stderr,
	       "step_one() >>> Errore: numero di argomenti insufficiente.\n");
      return -1;
    }
  else
    {
      if (DEBUG)
	fprintf (stderr, "step_one() >>> PASS.\n");
      return 0;
    }
}

int
step_one_point_five (int number_of_args, char **list_of_args)
{
  // controllo lunghezza nomi file (max 255 caratteri)
  int i, len;
  for (i = 1; i < number_of_args; i++)
    {
      if (list_of_args[i][0] == '-')
	continue;
      else
	{
	  len = strlen (list_of_args[i]);
	  if (DEBUG)
	    printf ("len: %d\n", len);
	  if (len > 255)
	    {
	      // nome troppo lungo
	      fprintf (stderr,
		       "step_one_point_five() >>> Errore: nome di file eccessivamente lungo.\n");
	      return -1;
	    }
	}
    }
  if (DEBUG)
    fprintf (stderr, "step_one_point_five() >>> PASS.\n");
  return 0;
}

int
step_two (int number_of_args, char **list_of_args, struct input_data *dati)
{
  // popolo la lista e, al contempo, conteggio il numero delle opzioni
  int temp;
  dati->numero_opzioni = 0;
  for (temp = 1; temp < number_of_args; temp++)
    {
      if (DEBUG)
	printf ("argv[%d] = %s\n", temp, list_of_args[temp]);
      if (list_of_args[temp][0] == '-')
	dati->numero_opzioni++;
      else
	{
	  enqueue (list_of_args[temp], dati);
	}
    }
  if (dati->numero_opzioni > 2)
    {
      fprintf (stderr,
	       "step_two() >>> Errore: numero di opzioni eccessivo. Specificare al piu` [-l] e [-w].\n");
      return -1;
    }
  else
    {
      if (DEBUG)
	fprintf (stderr, "step_two() >>> PASS.\n");
      return 0;
    }
}

int
step_three (int number_of_args, struct input_data *dati)
{
  // controllo che venga fornito il nome di almeno un file
  int file_no = number_of_args - 1 - dati->numero_opzioni;
  if (DEBUG)
    printf ("File_no = %d\n", file_no);
  if (file_no < 1)
    {
      fprintf (stderr,
	       "step_three() >>> Errore: e` necessario indicare il nome di almeno un file.\n");
      return -1;
    }
  else
    {
      if (DEBUG)
	fprintf (stderr, "step_three() >>> PASS.\n");
      return 0;
    }
}

int
step_four (int argc, char **argv, struct input_data *input)
{
// parsing delle opzioni
  int opt;
  input->count_lines = 0;
  input->count_words = 0;
  while ((opt = getopt (argc, argv, "lw")) != -1)
    {
      printf ("getopt_rv: %d\n", opt);
      switch (opt)
	{
	case 'l':
	  input->count_lines = 1;
	  break;
	case 'w':
	  input->count_words = 1;
	  break;
	default:
	  fprintf (stderr,
		   "step_four() >>> Errore, uso: %s [-l -w] file1 [file2 file3 ...].\n",
		   argv[0]);
	  return (-1);
	}
    }
  if ((input->count_lines + input->count_words) == 0)
    {
      input->count_lines = 1;
      input->count_words = 1;
    }
  if (DEBUG)
    printf ("Conta linee: %d\n", input->count_lines);
  if (DEBUG)
    printf ("Conta parole: %d\n", input->count_words);
  if (DEBUG)
    fprintf (stderr, "step_four() >>> PASS.\n");
  return 0;
}

int
step_five (struct input_data *lista)
{
  int x;
  struct element *cur = lista->primo;
  for (x = 0; x < lista->numero_file; x++)
    {
      if (DEBUG)
	printf ("Verifico l'esistenza del file %s...\n", cur->filename);
      FILE *temp = fopen (cur->filename, "r");
      if (temp == NULL)
	{
	  // il file non esiste   
	  fprintf (stderr,
		   "step_five() >>> Errore: il file %s non e` presente.\n",
		   cur->filename);
	  return (-1);
	}
      else
	{
	  fclose (temp);
	  cur = cur->next;
	}
    }
  if (DEBUG)
    fprintf (stderr, "step_five() >>> PASS.\n");
  return 0;
}
