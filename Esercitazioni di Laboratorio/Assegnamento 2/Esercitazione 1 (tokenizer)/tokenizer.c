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
main (int argc, char *argv[])
{

  // determino la lunghezza totale della stringa fornita
  int i;
  int lunghezza = 0;
  for (i = 1; i < argc; i++)
    lunghezza += strlen (argv[i]);

  printf ("Lunghezza: %d\n", lunghezza);

  // costruisco la stringa intera unendo gli elementi di argv
  if (argc <= 1)
    printf ("Numero di argomenti insufficiente.\n");
  else
    {
      char delimitatore[] = " ";
      char testo[lunghezza + 1];
      for (i = 0; i < (lunghezza + 1); i++)
	testo[i] = '\0';

      // copio solo il primo argomento
      strcat (testo, argv[1]);

      // copio i rimanenti
      for (i = 2; i < argc; i++)
	{
	  strcat (testo, delimitatore);
	  strcat (testo, argv[i]);
	}

      //char testo[] = "Hello, Operating Systems World!";
      char *token;

      token = strtok (testo, delimitatore);
      while (token != NULL)
	{
	  printf ("%s\n", token);
	  token = strtok (NULL, delimitatore);
	}
    }				// end big if
  return 0;
}

void
tokenizer (char *stringa, FILE * out)
{
}
