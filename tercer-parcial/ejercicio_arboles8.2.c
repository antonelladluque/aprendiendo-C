typedef struct NodoArbol {
    int info;
    struct NodoArbol* izq;
    struct NodoArbol* der;
} NodoArbol;

NodoArbol* buscarElemento(NodoArbol* raiz, int valor) { // 
    // Caso base: raíz nula o valor encontrado
    if (raiz == NULL || raiz->info == valor) {
        return raiz;
    }
    
    // Buscar en el subárbol izquierdo
    NodoArbol* encontradoIzq = buscarElemento(raiz->izq, valor);
    if (encontradoIzq != NULL) return encontradoIzq;
    
    // Si no estaba en la izquierda, buscar en la derecha
    return buscarElemento(raiz->der, valor);
}
