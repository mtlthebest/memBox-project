#include <stdio.h>

int
main (int argc, char *argv[], char *envp[])
{
  int i;
  printf ("\n");
  printf ("+-----------+\n");
  printf ("| Argomenti |\n");
  printf ("+-----------+\n");
  printf ("%s", argv[0]);
  for (i = 1; i < argc; i++)
    printf ("\n%s", argv[i]);
  printf ("\n");
  i = 1;
  if (envp[0] != NULL)
    {
      printf ("\n");
      printf ("+----------------------+\n");
      printf ("| Variabili d'ambiente |\n");
      printf ("+----------------------+\n");
      printf ("%s", envp[0]);
    }
  while (envp[i] != NULL)
    {
      printf ("\n%s", envp[i]);
      i++;
    }
  printf ("\n\n");
  return 0;
}
