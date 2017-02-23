#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libs/my_utils.h"
#include "../libs/parsing_utils.h"

int
main (int argc, char *argv[])
{
  // dichiarazione struttura base
  struct input_data foo;

  // inizializzazione struttura base
  foo.numero_file = 0;
  foo.count_lines = 0;
  foo.count_words = 0;

  // allocazione memoria dinamica per gli elementi
  foo.primo = malloc (sizeof (struct element));
  struct element *secondo = malloc (sizeof (struct element));
  struct element *terzo = malloc (sizeof (struct element));

  // concatenazione
  foo.primo->next = secondo;
  secondo->next = terzo;
  terzo->next = NULL;

  // scrittura manuale dei nomi
  strcpy (foo.primo->filename, "pippo");
  strcpy (foo.primo->next->filename, "ciccio");
  strcpy (foo.primo->next->next->filename, "eugenio");
  foo.numero_file = 3;

  // accodamento automatico dei nomi
  enqueue ("FRANCOOOO", &foo);
  enqueue ("Fla", &foo);
  enqueue ("Penny!", &foo);

  // testo la funzione
  show_file_list (&foo);

  // libero la memoria allocata per gli elementi dentro la struttura
  free_mem (&foo);

  // --- fine test my_utils.c ---
  // --- inizio test parse_utils.c ---

  int temp;

  // provo check no. 1
  temp = step_one (argc);
  printf ("Esito step one: %d\n", temp);

  // provo check no. 1.5
  temp = step_one_point_five (argc, argv);
  printf ("Esito step one_point_five: %d\n", temp);

  // provo check no. 2
  struct input_data bar;
  bar.numero_file = 0;
  bar.count_lines = 0;
  bar.count_words = 0;
  bar.primo = malloc (sizeof (struct element));
  temp = step_two (argc, argv, &bar);
  show_all_contents (&bar);
  printf ("Esito step two: %d\n", temp);

  // provo check no. 3
  temp = step_three (argc, &bar);
  printf ("Esito step three: %d\n", temp);

  // provo check no. 4
  temp = step_four (argc, argv, &bar);
  printf ("Esito step four: %d\n", temp);

  // provo check no. 5
  temp = step_five (&bar);
  printf ("Esito step five: %d\n", temp);

  // libero la memoria allocata per gli elementi dentro la struttura
  free_mem (&bar);

  // end testdriver
  return 0;
}
