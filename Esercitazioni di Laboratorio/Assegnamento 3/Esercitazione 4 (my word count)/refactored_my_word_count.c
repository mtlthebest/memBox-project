#include <stdio.h>
#include <stdlib.h>
#include "libs/my_utils.h"
#include "libs/parsing_utils.h"

int
main (int argc, char *argv[])
{
  struct input_data *queue = malloc (sizeof (struct input_data));
  int parse_result = parse_and_validate_args (argc, argv, queue);
  if (parse_result == -1)
    printf ("--- ERRORE ---\n");
  //  free_mem (queue);
  //free (queue);
  return 0;
}
