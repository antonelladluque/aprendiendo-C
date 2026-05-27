#include <stdio.h>

int main() {
    int numeros[5] = {10, 25, 30, 45, 50};
    int i;
    int buscado = 30;
    int encontrado = 0;

    for (i = 0; i < 5; i = i + 1) {
        if (numeros[i] == buscado) {
            encontrado = 1;
        }
    }

    if (encontrado == 1) {
        printf("El valor %d esta en el arreglo.\n", buscado);
    } else {
        printf("El valor %d no esta en el arreglo.\n", buscado);
    }

    return 0;
}
