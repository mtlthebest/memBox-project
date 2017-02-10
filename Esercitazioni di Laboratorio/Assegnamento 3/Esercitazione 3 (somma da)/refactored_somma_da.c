#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "refactored_somma_da.h"

#define DEBUG_MODE 1
#define RAISE_ERROR(error_text) {			\
    printf("%s. Interruzione.\n", error_text);		\
    ret_val = -1;					\
    break;						\
  }

int
main ()
{
  // operazioni preliminari
  int current_value = INIT_VALUE;
  int ret_val = 0;
  int converted_input = 0;
  if (DEBUG_MODE)
    printf ("Valore: %d\n", current_value);
  preparaFileIniziale (&current_value);

  // blocco principale del programma
  char *input = malloc (32 * sizeof (char));
  while (converted_input >= 0)
    {
      printf ("Inserisci un numero intero: ");
      fgets (input, 32, stdin);
      strtok (input, "\n");	// rimuove il ritorno a capo
      if (validate (input) == 0)
	{
	  RAISE_ERROR ("Errore: input non valido");
	}
      else
	{
	  converted_input = atoi (input);
	  printf ("INPUT FORNITO: %d\n", converted_input);
	  current_value = somma (converted_input);
	  if (converted_input < 0)
	    {
	      RAISE_ERROR ("Rilevato valore negativo");
	    }
	  else
	    printf ("Valore: %d\n", current_value);
	}
    }

  // eliminazione dei file temporanei
  remove ("somma_da.dat");

  // liberazione della memoria dinamica allocata sullo heap
  free (input);

  // end main
  return ret_val;
}


int
somma (int nuovo_addendo)
{
  int new_value;
  FILE *storage_file = fopen ("somma_da.dat", "rb");
  int precedente;
  fread (&precedente, sizeof (int), 1, storage_file);
  fclose (storage_file);
  new_value = precedente + nuovo_addendo;
  storage_file = fopen ("somma_da.dat", "wb");
  fwrite (&new_value, sizeof (int), 1, storage_file);
  fclose (storage_file);
  return new_value;
}

void
preparaFileIniziale (int *init_value)
{
  // determino se esiste gia' un file...
  int exists;
  FILE *temp_file = fopen ("somma_da.dat", "rb");
  if (temp_file == NULL)
    exists = 0;
  else
    exists = 1;

  // ... e nel caso...
  if (exists)
    {
      printf ("Vecchio file 'somma_da.dat' gia` presente. Rimozione...\n");
      fclose (temp_file);
      temp_file = NULL;
      remove ("somma_da.dat");
    }
  else
    printf ("Nessun file 'somma_da.dat' gia` presente, OK.\n");

  // creo il file nuovo
  temp_file = fopen ("somma_da.dat", "wb");
  fwrite (init_value, sizeof (int), 1, temp_file);
  fclose (temp_file);
  printf ("Nuovo file binario 'somma_da.dat' creato (INIT_VALUE = %d).\n",
	  INIT_VALUE);
}

int
validate (char *input_string)
{
  int temp;
  if (input_string[0] == '-')
    {
      temp = 1;			// numero negativo
      printf ("Validate: numero negativo?\n");
    }
  else
    {
      temp = 0;			// numero positivo
      printf ("Validate: numero positivo?\n");
    }
  int result = 1;
  while (input_string[temp] != '\0')
    {
      printf ("Validate: analizzo il carattere '%c'...\n",
	      input_string[temp]);
      if (!isdigit (input_string[temp]))
	{
	  // questo carattere non e' una cifra
	  result = 0;
	  break;
	}
      temp++;
    }				// end while
  return result;
}
