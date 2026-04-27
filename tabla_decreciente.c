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

    int c, i, j;

    // El bucle "hacer-mientras" garantiza que se ejecute al menos una vez
    do {
        printf("Ingrese un valor mayor a 0: ");
        scanf("%d", &c);
        
        if (c <= 0) {
            printf("Error: El numero debe ser positivo.\n");
        }
    } while (c <= 0); // Se repite si el usuario pone 0 o negativos

    // lógica original del patrón
    for (i = c; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j); // Añadí un espacio para que no se amontonen
        }
        printf("\n");
    }

    return 0;
}
