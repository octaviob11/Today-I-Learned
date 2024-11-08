#include <stdio.h>
#include <math.h>
#define M_NUMBER 80
#define F_CORTE_1 430
#define F_CORTE_2 450
#define F_AMOSTRAGEM 5000
//Biblioteca filtro FIR


/*Janela de Hamming. Vamos
Um filtro passa baixa ideal possui uma resposta ao impulo = Sen(Omega*t)(PI*t)
Mas essa não pdoemos implantar essa resposta diretamente, temos que desloca-la e fazer
um janelamento. Para esse código vou utilizar o janelamento de Hamming

*/

typedef struct FIR_filtro {
	float buffer[M_NUMBER+1];
	int bufIndex;
	float saida;
} FIR_filtro;


float a[M_NUMBER+1];
float w[M_NUMBER+1];
float h[M_NUMBER+1];

void inicializa_coeficientes(void) {	
	for (int i=0; i<=(M_NUMBER); i++) {
		if( ((i-M_NUMBER/2) == 0 )){
			a[i]=1/M_PI;
		}else
		{
			a[i]=sin(2*M_PI*F_CORTE_1*(i-M_NUMBER/2)/(F_AMOSTRAGEM))/(M_PI*(i-M_NUMBER/2))
			- sin(2*M_PI*F_CORTE_2*(i-M_NUMBER/2)/(F_AMOSTRAGEM))/(M_PI*(i-M_NUMBER/2));
		}
	}

	for (int i=0; i<=(M_NUMBER); i++) {

		w[i]=0.54-0.46*cos(2*M_PI*i/M_NUMBER);
	}

	for (int i=0; i<=(M_NUMBER); i++) {

		h[i]=w[i]*a[i];
	}
}


/* A função Update_filtro retorna com o valor da saída y[n]
dada uma entrada de x[n].
A medida com que a função update_filtro é executada as entradas x[n], x[n-1]... são salvas 
no buffer
Para calcular y[n] é executado um loop que realiza a convolução
 dos x[n] com a resposta ao impulso do filtro h[n]
*/

float update_filtro(FIR_filtro * filtro, float entrada){
	//Pega a entrada e joga dentro do buffer
	filtro->buffer[filtro->bufIndex] = entrada;
	//Atualiza o indice que recebeu a última entrada
	filtro->bufIndex++;

	//Se for maior do que o tamanho real, começa em zero novamente
		if (filtro->bufIndex == M_NUMBER+1) {
		filtro->bufIndex = 0;
	}
// Calculo da nova saída
		filtro->saida = 0.0;

		int sumIndex = filtro->bufIndex;

	for (int n = 0; n < M_NUMBER+1; n++) {

		/* Decrement index and wrap if necessary */
		if (sumIndex > 0) {

			sumIndex--;

		} else {

			sumIndex = M_NUMBER;

		}

		/* Multiply impulse response with shifted input sample and add to output */
		filtro->saida += h[n] * filtro->buffer[sumIndex];

	}

	/* Return filtered output */
	return filtro->saida;

}

void inicializa_filtro(FIR_filtro * filtro) {
	for (int i =0; i>=M_NUMBER; i++){
		filtro->buffer[i]=0;
	}
	filtro->bufIndex=0;
	filtro->saida=0;
}

int main (){
	FIR_filtro filtro1;

	inicializa_coeficientes();
	inicializa_filtro(&filtro1);

	float sinal[301];
	float sinal_filtrado[301];

	for (int i =0; i<301; i++)
	{
		sinal[i]= sin(2*M_PI*1000*i/F_AMOSTRAGEM)+0.1*sin(2*M_PI*440*i/F_AMOSTRAGEM);
	}

	/*for (int i=0; i<=M_NUMBER; i++)
	{
		printf("%f,",i,h[i] );
	}*/
	for (int i =0; i<301; i++)
	{
		printf("%f,",sinal[i]);
	}

	for (int i =0; i<301; i++)
	{
		sinal_filtrado[i] = update_filtro(&filtro1, sinal[i]);

	}

	printf("\n");
	printf("\n");

	for (int i =0; i<301; i++)
	{
		printf("%f,",sinal_filtrado[i]);
	}
	printf("\n");
	printf("\n");


}
