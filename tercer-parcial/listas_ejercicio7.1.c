#include <stdio.h>
#include <stdlib.h>

// Nodo para Lista Simple
typedef struct NodoSimple {
    char letra;
    struct NodoSimple* sgte;
} NodoSimple;

// Nodo para Lista Doble
typedef struct NodoDoble {
    char letra;
    struct NodoDoble* ant;
    struct NodoDoble* sgte;
} NodoDoble;

// Funciones auxiliares para insertar al final
void insertarSimple(NodoSimple** inicio, char letra) {
    NodoSimple* nuevo = (NodoSimple*)malloc(sizeof(NodoSimple));
    nuevo->letra = letra;
    nuevo->sgte = NULL;
    if (*inicio == NULL) {
        *inicio = nuevo;
    } else {
        NodoSimple* aux = *inicio;
        while (aux->sgte != NULL) aux = aux->sgte;
        aux->sgte = nuevo;
    }
}

void insertarDoble(NodoDoble** inicio, char letra) {
    NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    nuevo->letra = letra;
    nuevo->sgte = NULL;
    nuevo->ant = NULL;
    if (*inicio == NULL) {
        *inicio = nuevo;
    } else {
        NodoDoble* aux = *inicio;
        while (aux->sgte != NULL) aux = aux->sgte;
        aux->sgte = nuevo;
        nuevo->ant = aux;
    }
}

// Eliminar posiciones múltiplos de 3 (1-based index)
void eliminarMultiplosDeTres(NodoSimple** inicio) {
    if (*inicio == NULL) return;
    
    NodoSimple* actual = *inicio;
    NodoSimple* anterior = NULL;
    int pos = 1;
    
    while (actual != NULL) {
        if (pos % 3 == 0) {
            NodoSimple* borrar = actual;
            if (anterior == NULL) { // Si fuera el primer elemento (no aplica para el 3, pero es buena práctica)
                *inicio = actual->sgte;
            } else {
                anterior->sgte = actual->sgte;
            }
            actual = actual->sgte;
            free(borrar);
        } else {
            anterior = actual;
            actual = actual->sgte;
        }
        pos++;
    }
}

void mostrarSimple(NodoSimple* inicio) {
    while (inicio != NULL) {
        printf("%c -> ", inicio->letra);
        inicio = inicio->sgte;
    }
    printf("NULL\n");
}

int main() {
    NodoSimple* listaSimple = NULL;
    NodoDoble* listaDoblePreservada = NULL;
    
    // 1. Cargar abecedario y preservar en Doble
    for (char c = 'A'; c <= 'Z'; c++) {
        insertarSimple(&listaSimple, c);
        insertarDoble(&listaDoblePreservada, c);
    }
    
    printf("Lista Simple Original (antes de eliminar):\n");
    mostrarSimple(listaSimple);
    
    // 2. Eliminar múltiplos de 3
    eliminarMultiplosDeTres(&listaSimple);
    
    printf("\nLista Simple Resultante (sin multiplos de 3):\n");
    mostrarSimple(listaSimple);
    
    return 0;
}
