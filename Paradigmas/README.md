<b>Explicação do código: Paradigma1.c</b>

Nesse código verificamos como o compilador irá manipular os endereços de memória, de uma variável do tipo inteiro a ser tratada como um char.

 - Primeiro declaramos uma várivel do tipo int;
 - Depois declaramos um ponteiro do tipo char e apontamos para o endereço da variável inteira fazendo um cast:
 <i>char *z = (char*)&(d);</i>

 - Como tratamos o endereço de d como um char, ale utiliza apenas um byte de 4 bytes do inteiro.
 Ao realizarmos a seguinte atribuição:
<i>d =0x32303235;</i>
Se chamarmos a função printf dessa maneira:
<i>printf("%c",*z);</i> 
o resultado seria a impressão do número 5 pois o endereço de d aponta para o byte que no momento armazena o valor 0x35 que equivale ao número 5 da tabela ASCII


Quando chamamos:
<i>printf("%c %c %c %c\n", *(z+3),*(z+2),*(z+1),*z);</i>

O resultado será a impressão:2 0 2 5

<b>Explicação do código: Paradigma2.c</b>

Utilizamos uma variável do tipo unsigned long int para escrever 
uma pequena string de 7 bytes + '\0'





