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
    
    // Desapilar y reemplazar
    while (*tope != NULL) {
        int valor = pop(tope);
        if (valor == viejo) {
            push(&pilaAux, nuevo);
        } else {
            push(&pilaAux, valor);
        }
    }
    
    // Restaurar la pila original
    while (pilaAux != NULL) {
        push(tope, pop(&pilaAux));
    }
}
