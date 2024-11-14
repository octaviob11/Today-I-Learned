/*
Autor: Octavio Bottoni Neto
data: 06/08/2024
Comentários adicionados da seguinte maneira:
Comments added as follows:


//comentário em PT-BR
//Comment in EN
code 

Esse codigo exibe o valor inteiro da tabela ascci

char caractere : 8 

*/

#include <stdio.h>

int main () {

	char caractere = 0;

	for (int i = 0; i<256; i++){
		printf("Caractere %c = %d\n", caractere+i, caractere+i);
	}

	return 0;
}
