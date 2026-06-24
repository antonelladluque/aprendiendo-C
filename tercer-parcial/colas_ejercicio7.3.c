typedef struct NodoCola {
    int dato;
    struct NodoCola* sgte;
} NodoCola;

typedef struct {
    NodoCola* frente;
    NodoCola* fin;
} Cola;

// Devuelve un arreglo dinámico con los primeros k elementos
int* obtenerKElementos(Cola* cola, int k, int* tamanoSalida) { // 
    // Primero contamos cuántos elementos reales hay para validar
    NodoCola* aux = cola->frente;
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->sgte;
    }
    
    if (cont < k) { // 
        printf("Mensaje: La cola tiene menos de %d elementos. El tamaño actual es %d.\n", k, cont); // 
        *tamanoSalida = 0;
        return NULL;
    }
    
    int* resultado = (int*)malloc(k * sizeof(int));
    *tamanoSalida = k;
    
    // Desencolamos los primeros k elementos
    for (int i = 0; i < k; i++) {
        NodoCola* borrar = cola->frente;
        resultado[i] = borrar->dato;
        cola->frente = cola->frente->sgte;
        if (cola->frente == NULL) cola->fin = NULL;
        free(borrar);
    }
    
    return resultado;
}
