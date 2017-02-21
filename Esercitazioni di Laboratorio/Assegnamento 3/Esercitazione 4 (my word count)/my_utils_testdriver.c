#include <string.h>
#include <stdlib.h>
#include "my_utils.h"

int
main ()
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

  // end testdriver
  return 0;
}
