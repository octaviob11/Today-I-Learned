/*
Autor: Octavio Bottoni Neto
data: 06/08/2024
Comentários adicionados da seguinte maneira:

//comentário em PT-BR
//Comment in EN
code 

Esse codigo realiza a soma de vários números passados sobre argumentos

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])	{

	
	//Menos de 3 argumentos finaliza o programa
    //less then 3 arguments the ends the program
	
	if (argc < 3)
	{
		printf("Poucos números, digite pelo menos dois\n");
		return 1 ;
	}
	
	//Variável que guardará o resultado da soma total
	// Var with final result of the sum
	long int resultado = 0;


	//Loop para somar todos os arqumentos
	//Loop to sum all arguments
	for(int i = 1; i<argc; i++)
	{
		resultado += strtol(argv[i], NULL, 0);
	}
	
	//Exibe o resultado
	//Print the result

	printf("Resultado da soma = %ld", resultado);
	return 0;
}
