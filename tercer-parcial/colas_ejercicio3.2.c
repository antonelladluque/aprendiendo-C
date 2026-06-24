typedef struct NodoInt {
    int dato;
    struct NodoInt* sgte;
} NodoInt;

typedef struct {
    NodoInt* frente;
    NodoInt* fin;
} ColaInt;

// Función desencolar auxiliar
int desencolar(ColaInt* q) {
    if (q->frente == NULL) return -1;
    NodoInt* aux = q->frente;
    int valor = aux->dato;
    q->frente = q->frente->sgte;
    if (q->frente == NULL) q->fin = NULL;
    free(aux);
    return valor;
}

// Implementación de la función pedida
int* obtenerPrimerosK(ColaInt* q, int k, int* tamResultado) {
    // 1. Contar cuántos elementos tiene la cola actualmente
    int contador = 0;
    NodoInt* actual = q->frente;
    while (actual != NULL) {
        contador++;
        actual = actual->sgte;
    }
    
    // 2. Si hay menos de k elementos, mostrar mensaje y retornar NULL
    if (contador < k) { [cite: 166]
        printf("Error: La cola posee menos de %d elementos (Tamano actual: %d).\n", k, contador); [cite: 166, 170]
        *tamResultado = 0;
        return NULL;
    }
    
    // 3. Alojar memoria para el arreglo de salida
    int* arregloK = (int*)malloc(k * sizeof(int));
    *tamResultado = k;
    
    // 4. Extraer los k elementos (saldrán en el orden original FIFO)
    for (int i = 0; i < k; i++) {
        arregloK[i] = desencolar(q); [cite: 165]
    }
    
    return arregloK;
}
