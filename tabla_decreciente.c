#include <stdio.h>
int main(){
//diseñar un programa que solicite al usuario un valor n no negativo y visualice las siguiente tabla
/* 1 2 3 4 5 n
  1 2 3 4 5
  1 2 3 4
  1 2 3
  1 2
  1
*/

int c,i, j;

printf("Ingrese un valor mayor a 0: ");
scanf("%d", &c);

for (i=c ; i>=1 ; i--){
  for(j=1 ; j<=i ; j++){
    printf("%d", j);
  }
  printf("\n");
}

return 0;
}
