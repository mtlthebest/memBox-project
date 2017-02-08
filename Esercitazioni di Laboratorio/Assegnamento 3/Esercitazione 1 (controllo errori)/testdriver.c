/* +-------------------------------+
 * | Esercizio 1: controllo errori |
 * +-------------------------------+
 * 
 * Scrivere una funzione macro 'CHECK_CALL_PTR' che prende due
 * argomenti, un puntatore ed una stringa, e stampa utilizzando
 * perror l'errno e la stringa passata come argomento prima di uscire
 * dal programma con EXIT_FAILURE. Esempio di utilizzo:
 * +----------------------------------------------------------------+
 * | FILE *fp;                                                      |
 * | CHECK_CALL_PTR(fp=fopen("fileprova.txt", "r"),                 |
 * |     opening fileprova.txt);                                    |
 * +----------------------------------------------------------------+
 * NOTA: per il secondo argomento della macro non ci sono le
 * virgolette!
 * Se il file 'fileprova.txt' non esiste il risultato sarà:
 * +----------------------------------------------------------------+
 * | opening fileprova.txt: No such file or directory               |
 * +----------------------------------------------------------------+
 * Stampare il valore di ritorno di un programma che testa la macro
 * 'CHECK_CALL_PTR' sia in caso di successo che di fallimento
 * (ricordare che il valore di ritorno dell'ultimo comando bash
 * eseguito si può avere accedendo alla variabile di ambiente bash
 * ?).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_CALL_PTR(PUNTATORE, STRINGA) \
  {					   \
    PUNTATORE;				   \
    perror(#STRINGA);			   \
  }

int
main ()
{
  char testo[] = "Pippo";
  char ge_uno[] = "Sharks";
  char *fla = malloc (7 * sizeof (char));
  strcpy (fla, ge_uno);
  printf ("%s\n", fla);
  FILE *foo = fopen ("5$3///", "r");
  if (foo == NULL)
    perror (fla);
  free (fla);
  if (foo != NULL)
    fclose (foo);

  FILE *fp;
  CHECK_CALL_PTR (fp = fopen ("fileprova.txt", "w"), opening fileprova.txt);
  if (fp != NULL)
    {
      fprintf (fp, "%s\n", testo);
      fclose (fp);
    }
  return 0;
}
