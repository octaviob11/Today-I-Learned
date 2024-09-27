/*
Autor: Octavio Bottoni Neto
Exploração dos argumentos passados diretamente ao programa!
*/
#include <stdio.h>

int main (int argc, char *argv[]){

	printf("Foram passados %d argumentos\n", argc);
	
		
	for (int i=0; i<argc; i++)
	{
		printf("Argumento %d = %s\n", i, argv[i]);

	}


}
