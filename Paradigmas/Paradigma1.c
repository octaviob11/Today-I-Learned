

 #include<stdio.h>
   
int main()
   {
   	//int possui 4 bytes, 00
    int d = 3*16+2; //= 0x00 0x00 0x00 0x32
    char *z = (char*)&(d);

    printf("d =  0x00 0x00 0x00 0x32\n");
    printf("Sizeof d = %lu\n", sizeof(d));
    //Portando *z está considerando apenas o primeiro byte
    printf("Sizeof *z = %lu\n", sizeof(*z));
    printf("Portando *z está considerando apenas o primeiro byte\n");
    printf("%d, %c\n", d, *z);
    d =0x32303235;

    printf("Agora\n");
    printf("d = 0x32 0x30 0x32 0x35 \n");
    printf("Repare que screvemos 2025 em ASCII\n");
    printf("Sizeof d = %lu\n", sizeof(d));
    printf("Sizeof *z = %lu\n", sizeof(*z));
    printf("%d, %c\n", d, *z);
    printf("Para imprimir o 2025 vamos usar:\n");
    /*
    *z = Endereço de d
	              = |0x35      |0x32      |0x30      |0x32      |
    Endereço de   = *z         *(z+1)     *(z+2)     *(z+3)
    */
    printf("Os bytes são armazenados na ordem Big Endian\n");
    printf("%c %c %c %c\n",*(z+3),*(z+2),*(z+1),*z);
    return 0;
}

