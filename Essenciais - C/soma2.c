/*
Autor: Octavio Bottoni Neto
data: 06/08/2024
Comentários adicionados da seguinte maneira:

//comentário em PT-BR
//Comment in EN
code 


Soma dois números que foram passados via argumentos
sum of two numbers passed as arguments 
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	//Menos de 3 argumentos finaliza o programa
        //less then 3 arguments the ends the program
	if (argc < 3)
	{
		printf("Poucos números, digite dois\n");
		return 1 ;
	}

	//Mais de 3 argumentos finaliza o programa
	//more then 3 arguments ends the program

	if (argc > 3)
	{
		
		printf("Muitos numeros, digite apenas 2\n");
		return 1;
	}

	//Converte os números
	//converts the numbers 
	long num1 = strtol(argv[1], NULL, 0);
	long num2 = strtol(argv[2], NULL, 0);	
	
	// apresenta a soma
	// show the sum
	printf("Resultado da soma = %ld\n", num1+num2);
	return 0;
}
