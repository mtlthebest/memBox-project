// conta il numero di parole contenute in un file

int main (){
  char file[] = "makefile";
  int parole = conta_parole(file);
  printf("%d %s\n", parole, file)
  return 0;
}

int conta_parole(char * nome_file){
  int conteggio = 0;
  FILE * temp = fopen(nome_file, "r");
  fread();
  return conteggio;
}
