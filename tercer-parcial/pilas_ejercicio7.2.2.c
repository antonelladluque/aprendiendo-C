typedef struct NodoPila {
    int dato;
    struct NodoPila* sgte;
} NodoPila;

void push(NodoPila** tope, int valor) {
    NodoPila* nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    nuevo->dato = valor;
    nuevo->sgte = *tope;
    *tope = nuevo;
}

int pop(NodoPila** tope) {
    if (*tope == NULL) return -1; 
    NodoPila* aux = *tope;
    int valor = aux->dato;
    *tope = aux->sgte;
    free(aux);
    return valor;
}

void Reemplazar(NodoPila** tope, int nuevo, int viejo) { // 
    NodoPila* pilaAux = NULL;
    
    // 1. Desapilar y buscar el valor viejo para cambiarlo por el nuevo
    while (*tope != NULL) {
        int valor Actual = pop(tope);
        if (valorActual == viejo) {
            push(&pilaAux, nuevo);
        } else {
            push(&pilaAux, valorActual);
        }
    }
    
    // 2. Reconstruir la pila original conservando el orden de los elementos
    while (pilaAux != NULL) {
        push(tope, pop(&pilaAux));
    }
}
