/* Conviene usar el operador ternario cuando:

la condición es clara
solo hay dos posibles resultados
querés obtener un valor
la expresión sigue siendo fácil de leer */
#include <stdio.h>

int main() {
    int a = 12;
    int b = 5;
    int menor = a < b ? a : b;

    printf("El menor es: %d\n", menor);

    return 0;
}
