/* Scrivere un programma che data una stringa come argomento, stampa
 * a video (stdout) le parole contenute nella stringa in input una
 * per ogni linea. Usare la funzione di libreria 'strtok' per
 * estrarre i token dalla stringa. Per realizzare il programma
 * implementare la funzione 'tokenizer' con la seguente segnatura:
 * +----------------------------------------------------------------+
 * | void tokenizer(char *stringa, FILE *out);                      |
 * +----------------------------------------------------------------+
 * Testare il programma con i seguenti casi (supponiamo che
 * l'eseguibile si chiami es1):
 * +----------------------------------------------------------------+
 * | ./es1 "ciao mondo"                                             |
 * | ./es1                                                          |
 * | ./es1 "questa e' una stringa di alcune parole!"                |
 * | ./es1 questa è un\'altra stringa                               |
 * +----------------------------------------------------------------+
 */

#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int
main (int argc, char *argv[])
{
  // nessuna stringa fornita
  if (argc <= 1)
    return 0;

  // fornita almeno una stringa
  else
    {
      int i;
      for (i = 1; i < argc; i++)
	tokenizer (argv[i], stdout);
      return 0;
    }
}

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
