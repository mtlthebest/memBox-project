
void stampa(char *arch[], size_t sizeA)
{
    printf("i loro indirizzi sono:\n");

    for (size_t i = 0; i < sizeA; i++)
	printf("%p\n", (void *) &arch[i]);
    printf("----------------------\n");
}

void leggi(char *archivio[], size_t size)
{
    for (size_t i = 0; i < size; i++)
	printf("%s\n", archivio[i]);

    stampa(archivio, size);
}
