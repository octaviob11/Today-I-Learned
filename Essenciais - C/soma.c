/*
Esse código realzia a soma de dois números inteiros
*/
// inclusão da biblioteca padrao Standard IO
#include <stdio.h>



int main(){
	//Declaração e inicialização das variáveis num1 e num2.
	int num1 = 0;
	int num2 = 0;

	printf("Digite o primeiro número: ");
	scanf("%d", &num1);

	printf("Digite o segundo número: ");
	scanf("%d",&num2);

	//Print do resultado
	printf("Soma = %d\n", num1+num2 );
}
