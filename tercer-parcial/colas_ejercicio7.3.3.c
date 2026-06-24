int* MergeColas(ColaInt* q1, ColaInt* q2, int* tamTotal) {
    // 1. Contar elementos totales para dimensionar el arreglo
    int n1 = 0, n2 = 0;
    NodoInt* aux = q1->frente;
    while (aux != NULL) { n1++; aux = aux->sgte; }
    
    aux = q2->frente;
    while (aux != NULL) { n2++; aux = aux->sgte; }
    
    *tamTotal = n1 + n2;
    int* arregloOrdenado = (int*)malloc((*tamTotal) * sizeof(int));
    
    int i = 0;
    // 2. Mezclar comparando los frentes mientras ambas colas tengan datos
    while (q1->frente != NULL && q2->frente != NULL) {
        if (q1->frente->dato <= q2->frente->dato) {
            arregloOrdenado[i] = desencolar(q1);
        } else {
            arregloOrdenado[i] = desencolar(q2);
        }
        i++;
    }
    
    // 3. Vaciar los elementos remanentes de la Cola 1 (si quedan)
    while (q1->frente != NULL) {
        arregloOrdenado[i] = desencolar(q1);
        i++;
    }
    
    // 4. Vaciar los elementos remanentes de la Cola 2 (si quedan)
    while (q2->frente != NULL) {
        arregloOrdenado[i] = desencolar(q2);
        i++;
    }
    
    return arregloOrdenado;
}
