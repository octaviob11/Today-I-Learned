/*
Criado por Octavio Bottoni Neto 

*/

#include <stdio.h> // printf
#include <fcntl.h> // File control options. Definição das flags e open() 
#include <unistd.h> // read()


#define BUFFER_SIZE  1024


int main(){
	int flags = O_RDONLY; // Podemos adicionar mais de uma flag de abertura
	
	int inputFD; // Não vamos utilizar a função fopen!
				 // por isso não precisamos de FILE * FD; 
	
	char buffer[BUFFER_SIZE];
	
	ssize_t numRead; // Numero de bytes lidos
	printf("Esse programa irá ler um arquivo!\n");

	inputFD = open("texto", flags); // file com nome "arquivo" foi previamente criado

	if(inputFD == -1) {   // Tratamento de erro
		printf("ERRO!\n"); 
		return -1; 
	}

	printf("Efetuando a leitura do arquivo\n");
	
	numRead = read(inputFD, buffer, BUFFER_SIZE); //Efetuando a leitura
	if (numRead == -1){
        printf("Erro de leitura!"); 
        return -1;
	}
	
	for(int i=0;i<numRead;i++){
	printf("%c", buffer[i]);

	}

	// fechando o inputFD;
	if(close(inputFD) == -1){
		printf("Erro ao fechar o arquivo");
		return -1;
	}

	return 0;
}

