/*Escribe un programa que lea caracteres uno por uno desde el teclado. Si el carácter es una letra minúscula, 
debe mostrarla en mayúscula. Si es cualquier otro carácter (número, símbolo o espacio), lo debe mostrar tal cual. 
El programa debe detenerse cuando el usuario presione la tecla Enter.*/

#include <stdio.h>

int main() {
    char c;

    printf("Escribe un mensaje en minusculas (presiona Enter para terminar):\n");

    // Leemos el primer caracter
    c = getchar();

    // Mientras el caracter no sea un salto de linea (Enter)
    while (c != '\n') {
        
        // Verificamos si es una letra minuscula (entre 'a' y 'z')
        if (c >= 'a' && c <= 'z') {
            c = c - 32; // Convertimos a mayuscula
        }

        // Imprimimos el caracter resultante
        putchar(c);

        // Leemos el siguiente caracter para la proxima vuelta
        c = getchar();
    }

    printf("\n\nPrograma finalizado.\n");
    return 0;
}
