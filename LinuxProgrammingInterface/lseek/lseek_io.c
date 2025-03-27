/*Código baseado no lseek_io.c do livro TLPI 

Esse comando realiza operações de E/S em um arquivo! 
Cada uma dessas operações consiste em uma letra seguida 
por um valor associado (sem espaço):

-soffset: Procura o deslocamento de bytes do início do arquivo.
-rlength: Lê bytes de comprimento do arquivo, começando no deslocamento do arquivo atual, e exibe-os em forma de texto.
- Rlength: Lê bytes de comprimento do arquivo, começando no deslocamento do arquivo atual, e exibe-os em hexadecimal.
- wstr: Escreve a sequência de caracteres especificada em str no deslocamento do arquivo atual

exemplo lseek_io arq r10

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h> 
#include <string.h>


int main(int argc, char ** argv){

	
	size_t length; //"Type" do SUSv3 não possui sinal "Size of an object in bytes"
	off_t offset; // "File offset or size"
	int fd, ap, i,j;
	char * buffer = NULL;
	char * p;
	ssize_t numRead, numWritten; // Contagem de bytes
	const int openOrCreateflags = O_RDWR | O_CREAT;
	const mode_t modes = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	printf("Bem vindo ao lseek_io\n");

	//Poucos argumentos!
	if(argc < 3){
		printf("Poucos argumentos\n");
		printf("Modo de uso:  %s <file> {r<length>|R<length>|w<string>|s<offset>}...\n",argv[0]);
	}
	//abrindo o arquivo!
	if ((fd = open(argv[1], openOrCreateflags, modes )) == -1){
		printf("Erro ao abrir ou criar arquivo!\n");
		return -1;
	}

	for (ap = 2; ap < argc; ap++) {
		switch (argv[ap][0]){
			case 'r':
			case 'R':
			length = strtol(&argv[ap][1],&p,10);
			buffer = malloc(length);
			if (buffer == NULL){
    			printf("Erro no malloc\n");
    			return -1;
			}
			numRead = read(fd, buffer, length);
			if (numRead == -1){
    			printf("Erro no read\n");
    			return -1;
			}
			if (numRead == 0) {
				printf("%s: Fim do arquivo\n", argv[ap]);
			} 
			else {
				printf("%s: ", argv[ap]);
				for (j = 0; j < numRead; j++) {
					if (argv[ap][0] == 'r') {
						printf("%c", isprint((unsigned char) buffer[j]) ? buffer[j] : '?'); 
					}
					else {
					printf("%02x ", (unsigned int) buffer[j]);
					}
				             
				}
				printf("\n");
			}
			free(buffer);
			break;
			case 'w':
				numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
			if (numWritten == -1){
				printf("Erro na chamada de write\n");
				return -1;
			}
				printf("%s: escrito %ld bytes\n", argv[ap], (long) numWritten); 
			break;
		case 's':

			offset = (off_t)strtol(&argv[ap][1], &p,10); 
			if (lseek(fd, offset, SEEK_SET) == -1){
				printf("Erro na chamada de lseek\n");
				return -1;
			}
			printf("%s: seek realizado com sucesso\n", argv[ap]);
		break;
		default:
			printf("argumento deve inificar com [rRws]: %s\n", argv[ap]);

} /* fim do switch*/

} /* fim do for (antes do switch) */
} /*MAIN*/
