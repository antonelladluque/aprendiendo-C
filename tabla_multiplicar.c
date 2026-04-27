#include <stdio.h>
#include <stdio.h>

int main(){
//mostrar por pantalla una tabla de multiplicar , ingresar por teclado el limite, como minimo 1 y 2

/*
1 2 3 4 5 ....
1 1 2 3 4 5 ...
2 2 4 6 8 10 ...
3 3 6 9 12 15 ...
.
.
.

*/

int i, j , num;

printf("Ingrese un numero mayor o igual a 2 \n");
scanf("%d", &num);


for ( i = 1; i<=num ; i++){
  for ( j=1 ; j<=num ; j++){
    printf("%d \t", i*j);
  }
  printf("\n");
}

return 0;
}
