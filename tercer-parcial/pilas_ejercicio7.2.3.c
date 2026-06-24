int estaOrdenadaAscendente(NodoPila** tope) { // 
    // Si está vacía o tiene un solo elemento, se considera ordenada
    if (*tope == NULL || (*tope)->sgte == NULL) {
        return 1; 
    }
    
    NodoPila* pilaAux = NULL;
    int ordenado = 1; // Bandera booleana
    
    // Desapilamos comparando el tope actual con el elemento que le sigue
    while (*tope != NULL && (*tope)->sgte != NULL) {
        int actual = pop(tope);
        int siguiente = (*tope)->dato; // 'Mapeamos' el valor del nuevo tope sin extraerlo
        
        push(&pilaAux, actual);
        
        // Si el actual NO es menor al que le sigue, se rompe el orden
        if (actual >= siguiente) { // 
            ordenado = 0; 
        }
    }
    
    // Si quedó el último elemento en la pila original, lo movemos a la auxiliar
    if (*tope != NULL) {
        push(&pilaAux, pop(tope));
    }
    
    // RESTAURACIÓN: Regresamos todos los elementos a la pila original [cite: 159]
    while (pilaAux != NULL) {
        push(tope, pop(&pilaAux));
    }
    
    return ordenado;
}
