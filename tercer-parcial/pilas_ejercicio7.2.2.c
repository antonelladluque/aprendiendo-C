int estaOrdenadaAscendente(NodoPila** tope) { // 
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
