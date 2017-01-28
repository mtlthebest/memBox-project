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

int
main ()
{
  char testo[] = "Hello, Operating Systems World!";
  char delimitatore[] = " ";
  char *token;

  token = strtok (testo, delimitatore);
  while (token != NULL) {
    printf ("%s\n", token);
    token = strtok (NULL, delimitatore);
  }

  return 0;
}

void
tokenizer (char *stringa, FILE * out)
{
}
