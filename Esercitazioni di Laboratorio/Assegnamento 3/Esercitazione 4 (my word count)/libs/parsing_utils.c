/* Convenzione: se i controlli vanno a buon fine le funzioni
 * restituiscono 0, altrimenti restituiscono -1.
 */

#include <stdio.h>
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
