/* Inserire nel file 'tokenizer.h' l'interfaccia delle due funzioni
 * 'tokenizer' e 'tokenizer_r' come descritte negli esercizi 1 e 2.
 * Inserire nel file 'tokenizer.c' l'implementazione delle due
 * funzioni. Creare quindi una librerie statica 'libtokenizer.a' e
 * riscrivere il programma dell'esercizio 2 in modo che il programma
 * main includa il file 'tokenizer.h' e linki la libreria.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
tokenizer (char *stringa, FILE * out)
{
  char delimitatore[] = " ";
  char *token;
  token = strtok (stringa, delimitatore);
  while (token != NULL)
    {
      fprintf (out, "%s\n", token);
      token = strtok (NULL, delimitatore);
    }
}

void
tokenizer_r (char *stringa, FILE * out)
{
  char delimitatore[] = " ";
  char *token;
  char **save_pointer = malloc (sizeof (char *));
  token = strtok_r (stringa, delimitatore, save_pointer);
  while (token != NULL)
    {
      fprintf (out, "%s\n", token);
      token = strtok_r (NULL, delimitatore, save_pointer);
    }
  free (save_pointer);
}
