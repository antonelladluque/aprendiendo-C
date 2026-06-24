#include <stdio.h>
#include <stdlib.h>

// Definición del nodo del árbol
typedef struct NodoArbol {
    int info;
    struct NodoArbol* izq;
    struct NodoArbol* der;
} NodoArbol;

// Función para crear un nodo rápidamente
NodoArbol* crearNodo(int valor) {
    NodoArbol* nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevo->info = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Recorrido Preorden - Recursivo (Raíz, Izq, Der)
void preorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

// Recorrido Inorden - Recursivo (Izq, Raíz, Der)
void inorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->info);
        inorden(raiz->der);
    }
}

// Recorrido Postorden - Recursivo (Izq, Der, Raíz)
void postorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->info);
    }
}
