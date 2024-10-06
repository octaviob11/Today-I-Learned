/*
Autor: Octavio Bottoni neto
Comentários adicionados da seguinte forma:

Comentário em PT-BR
comment in english
code

Esse código realzia a soma de dois números inteiros
This code do the sum of two numbers
*/
// inclusão da biblioteca padrao Standard IO
#include <stdio.h>



int main(){

	//Declaração e inicialização das variáveis num1 e num2.
	//Declaration and initialization of variables num1 and num2 
	int num1 = 0;
	int num2 = 0;
	
	//Pede o primeiro numero ao usuário
	//aks the first number
	printf("Digite o primeiro número: ");
	scanf("%d", &num1);
	//Pede o segundo número ao usuário
	//Ask the second number
	printf("Digite o segundo número: ");
	scanf("%d",&num2);

	//Print do resultado
	//Print the result
	printf("Soma = %d\n", num1+num2 );
}
