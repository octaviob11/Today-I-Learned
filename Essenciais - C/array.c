// Autor:Octavio Bottoni Neto


#include <stdio.h>
//Macro para calcular tamanho de arrays!
//Macro to calulate size of arrays
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof((arr)[0])

int main(){
	int array_num[] = {1,2,3,4,5};
	int size_array = ARRAY_SIZE(array_num);
	int sum =0;
	for(int i = 0; i<size_array; i++) {
		sum += array_num[i];
	}
	printf("Media = %d", sum/size_array);
	
	
	return 0;
}

