#include <stdio.h>

int main() {
    int numeros[6] = {8, 14, 21, 14, 35, 42};
    int i;
    int buscado = 14;
    int posicion = -1;

    for (i = 0; i < 6; i = i + 1) {
        if (numeros[i] == buscado) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1) {
        printf("El valor %d se encontro en la posicion %d.\n", buscado, posicion);
    } else {
        printf("El valor %d no se encontro.\n", buscado);
    }

    return 0;
}
