#include <stdio.h>

int main() {
	//ingresar la tabla del uno al nueve
	
	int i, num,resul; 
	
	printf("Que tabla desea saber, del 1 al 9?\n");
	scanf("%i", &num);
	
	for(i=1; i<=10 ; i ++){
		resul=i*num;
		printf("%i x %i = %i\n", i , num, resul);
	}
	
	return 0;
}

