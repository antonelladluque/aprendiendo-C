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
Ejercicio 7.2.3: Verificar si una Pila está ordenada ascendentementeJustificación de Complejidad: El orden del algoritmo es $O(n)$ porque obligatoriamente debemos vaciar la pila entera para revisar cada elemento y luego volver a llenarla para dejarla en su estado original .Cint estaOrdenadaAscendente(NodoPila** tope) { // 
    if (*tope == NULL || (*tope)->sgte == NULL) return 1; // Vacía o con 1 elemento está ordenada
    
    NodoPila* pilaAux = NULL;
    int ordenado = 1;
    
    // El "tope" debe ser menor que el que le sigue (según la definición del enunciado)
    while (*tope != NULL && (*tope)->sgte != NULL) {
        int actual = pop(tope);
        int siguiente = (*tope)->dato; // Miramos el nuevo tope sin sacarlo
        
        push(&pilaAux, actual);
        
        if (actual >= siguiente) { 
            ordenado = 0; // Rompe la condición de "cada elemento menor al que le sigue" 
        }
    }
    
    // Si quedó el último elemento en la pila principal, lo pasamos a la auxiliar para restaurar todo completo
    if (*tope != NULL) {
        push(&pilaAux, pop(tope));
    }
    
    // Dejar la pila en el mismo estado original 
    while (pilaAux != NULL) {
        push(tope, pop(&pilaAux));
    }
    
    return ordenado;
}
