#include <stdio.h>
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
	tokenizer_r (argv[i], stdout);
      return 0;
    }
}
