/******************************************************************************
Programa: Contador de letras en una frase
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100]; 
    char letra;      // letra a buscar
    int i;
    int contador = 0; // cuenta cuantas veces aparece la letra que queremos buscar

    //ingreso de frase al usuario
    printf("Escribe una frase: ");
    // Usamos fgets para permitir espacios. stdin significa "entrada estándar" (teclado).
    fgets(frase, sizeof(frase), stdin);

    // pedimos la letra al usuario
    printf("Escribe la letra que deseas buscar: ");
    // El espacio antes de %c limpia el "Enter" que quedó en el buffer de la lectura anterior
    scanf(" %c", &letra);

    // recorremos la cadena y contar
    // El bucle se ejecuta caracter por caracter hasta encontrar el final de la cadena ('\0')
    for (i = 0; frase[i] != '\0'; i++) {
        
        // Si el caracter actual de la frase es igual a la letra buscada, sumamos 1
        if (frase[i] == letra) {
            contador++;
        }
    }

    // Mostrar el resultado
    printf("\nLa letra '%c' aparece %d veces en la frase.\n", letra, contador);

    return 0;
}
