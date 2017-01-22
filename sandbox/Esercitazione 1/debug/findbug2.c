/*
 * Trovare il bug. 
 *
 * COMPILAZIONE:
 *  gcc -std=c99 -Wall -g ./cstring1.c -o cstring
 *
 */


#include <stdio.h>
#include <ctype.h>

int main() {
    char str[]="questa e' una STRINGA non tanto Lunga che CONtiene 123 !";
    char *p = str;

    while(*p != '\0') 
	*p++ = (islower(*p)?toupper(*p):*p);
    printf("%s\n", str);
    return 0;
}
