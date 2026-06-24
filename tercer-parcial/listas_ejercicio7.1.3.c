#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo para letras
typedef struct Nodo {
    char letra;
    struct Nodo* sgte;
} Nodo;

// Procedimiento para insertar al final
void insertarAlFinal(Nodo** inicio, char nuevaLetra) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->letra = nuevaLetra;
    nuevoNodo->sgte = NULL;

    if (*inicio == NULL) {
        *inicio = nuevoNodo;
    } else {
        Nodo* aux = *inicio;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoNodo;
    }
}

// Función para recuperar un elemento por su posición (índice 0-based)
char recuperarElemento(Nodo* inicio, int posicion) {
    Nodo* aux = inicio;
    int contador = 0;

    while (aux != NULL) {
        if (contador == posicion) {
            return aux->letra;
        }
        aux = aux->sgte;
        contador++;
    }
    return '\0'; // Retorna vacío si la posición no existe
}

// Función para contar los objetos de la lista
int contarElementos(Nodo* inicio) {
    int contador = 0;
    Nodo* aux = inicio;

    while (aux != NULL) {
        contador++;
        aux = aux->sgte;
    }
    return contador;
}

// Función auxiliar para mostrar la lista en pantalla
void mostrarLista(Nodo* inicio) {
    Nodo* aux = inicio;
    printf("\n--- ESTADO DE LA LISTA ---\n");
    if (aux == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        while (aux != NULL) {
            printf("[%c] -> ", aux->letra);
            aux = aux->sgte;
        }
        printf("NULL\n");
    }
    printf("--------------------------\n");
}

// Programa principal con Menú Interactivo
int main() {
    Nodo* miLista = NULL; // Inicializamos la lista vacía
    int opcion;
    char letraIngresada;
    int posicionBuscada;
    char letraRecuperada;

    do {
        printf("\n===== MENU DE OPCIONES =====\n");
        printf("1. Insertar una letra al final\n");
        printf("2. Mostrar lista completa\n");
        printf("3. Ver el numero de objetos (tamano)\n");
        printf("4. Recuperar un elemento por posicion\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion (1-5): ");
        scanf("%d", &opcion);
        fflush(stdin); // Limpia el buffer de entrada en Windows (o usar getchar() si estás en Linux)

        switch(opcion) {
            case 1:
                printf("Ingrese la letra que desea guardar: ");
                // El espacio antes de %c es un truco crucial en C para ignorar saltos de línea anteriores
                scanf(" %c", &letraIngresada); 
                insertarAlFinal(&miLista, letraIngresada);
                printf("¡Letra '%c' insertada correctamente!\n", letraIngresada);
                break;

            case 2:
                mostrarLista(miLista);
                break;

            case 3:
                printf("\nEl numero total de objetos en la lista es: %d\n", contarElementos(miLista));
                break;

            case 4:
                if (miLista == NULL) {
                    printf("\nLa lista esta vacia, no hay elementos para recuperar.\n");
                } else {
                    printf("Ingrese la posicion a consultar (0 para la primera letra): ");
                    scanf("%d", &posicionBuscada);
                    
                    letraRecuperada = recuperarElemento(miLista, posicionBuscada);
                    if (letraRecuperada != '\0') {
                        printf("-> El elemento en la posicion %d es: '%c'\n", posicionBuscada, letraRecuperada);
                    } else {
                        printf("-> Error: La posicion %d no existe en la lista.\n", posicionBuscada);
                    }
                }
                break;

            case 5:
                printf("Saliendo del programa de practica. ¡Exitos en el examen!\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while(opcion != 5);

    // Liberación de memoria antes de terminar (Buena práctica de la UTN)
    Nodo* actual = miLista;
    while (actual != NULL) {
        Nodo* proximo = actual->sgte;
        free(actual);
        actual = proximo;
    }

    return 0;
}
