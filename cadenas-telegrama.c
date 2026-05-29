#include <stdio.h>
#include <string.h>

// PROCEDIMIENTO: Muestra la cadena en pantalla
void mostrarTelegrama(char texto[]) {
    printf("\n--- CONTENIDO DEL TELEGRAMA ---\n");
    printf("%s\n", texto);
}

int main()
{
    char frase[100];
    int letras = 0, palabra = 0, oracion = 0;
    int costo = 0;
    
    // CORRECCIÓN: Para el 'while' necesitamos una variable que sirva de índice (el contador de posición)
    int i = 0; 

    printf("Escribe el telegrama (usa '*' para palabras, '.' para oraciones y '-' al final):\n");
    fgets(frase, sizeof(frase), stdin);

    // CORRECCIÓN: El 'while' avanza mientras no lleguemos al final del texto y no encontremos el guión '-'
    while (frase[i] != '\0' && frase[i] != '-') {
        
        if (frase[i] == '*') {
            palabra++;
        }
        else if (frase[i] == '.') {
            oracion++;
        }
        else if (frase[i] != '\n' && frase[i] != ' ') {
            // REQUISITO: Si NO es asterisco, NI punto, NI un salto de línea/espacio, es una letra real.
            letras++;
        }

        // ¡IMPORTANTE EN EL WHILE!: Debemos sumar 1 a 'i' manualmente para avanzar al siguiente carácter
        i++; 
    }

    // Sumamos la última palabra que cierra con el punto final
    if (letras > 0) {
        palabra++;
    }

    // Tu lógica de costos
    if (palabra == 5 && oracion == 1) {
        costo = letras * 100;
    } 
    else if (oracion == 2 && palabra <= 10) {
        costo = letras * 500;
    } 
    else {
        costo = letras * 700;
    }

    // Llamamos al procedimiento para mostrar el telegrama
    mostrarTelegrama(frase);

    // Resultados finales
    printf("El telegrama tiene: %d oracion/es, %d palabras y %d letras reales (sin símbolos).\n", oracion, palabra, letras);
    printf("El costo total del telegrama es: $ %d\n", costo);

    return 0;
}
