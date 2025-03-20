

#include<stdio.h>
#include<string.h>

int main()
   {

// Vamos escrever uma string em uma variável do tipo double

   	long unsigned int a;

   	char * s;
	   s = (char * )&a; 
   

   	/*Para funcionar na minha maquina que possui o seguinte compilador:
   	gcc -v
   	Apple clang version 14.0.0 (clang-1400.0.29.202)
    Target: x86_64-apple-darwin21.6.0

	uname -v
	Darwin Kernel Version 21.6.0: Mon Dec 19 20:44:01 PST 2022; root:xnu-8020.240.18~2/RELEASE_X86_64
   	
   	//Precisei escrever de forma invertida:
    //  '\o' '5'  '2'
   	// 0x00 0x35 0x32 0x30 0x32 0x20 0x69 0x4f
   	// para funcionar no
   	   	a =0x003532303220694f;
  */
  		

   
   	printf("Tamanho da variável do tipo unsigned long int = %lu\n", sizeof(a));


	
    printf("%s\n",s);
    return 0;
}

