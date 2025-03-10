/* Esse código corrige alguns problemas do código "leitor.c"
* e adiciona o recurso de poder entrar com o nome do arquivo 
* como argumento
*
*/
#include <stdio.h>
#include <stdio.h> // printf
#include <fcntl.h> // File control options. Definição das flags e open() 
#include <unistd.h> // read() e STDOUT_FILENO 

#define BUFFER_SIZE 2048

int main(int argc, char ** argv){
	int flags = O_RDONLY;
	int FD=0;
	char buffer[BUFFER_SIZE];
	ssize_t numRead=0;
	// Os proxímos dois IFs irão verificar erros dos arumentos
	if(argc<2){
		printf("Falta o nome do arquivo!\n");
		return -1;
	}
	if(argc>2){
		printf("Muitos argumentos!\n");
		return -1;
	}
	//Chamada de sistema para abrir o aquivo
	FD = open(argv[1], flags); // 
	if(FD == -1){
		printf("Não foi possível abrir o arquivo\n");
	}
	//Chamada de sistema para ler e depois escrever na tela
	while((numRead = read( FD, buffer,BUFFER_SIZE))>0){
		// STDOUT_FILENO = 0 no caso é a tela da execução!
			write(STDOUT_FILENO,buffer,numRead);
	}

	if(close(FD) == -1){
		printf("Erro no close\n");
	}
	
	return 0;

}