typedef struct NodoSimpleInt {
    int dato;
    struct NodoSimpleInt* sgte;
} NodoSimpleInt;

NodoDoble* MergeListas(NodoSimpleInt* lista1, NodoSimpleInt* lista2) {
    NodoDoble* listaResultado = NULL;
    
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->dato <= lista2->dato) {
            insertarDobleInt(&listaResultado, lista1->dato); // (Función de inserción similar a la anterior)
            lista1 = lista1->sgte;
        } else {
            insertarDobleInt(&listaResultado, lista2->dato);
            lista2 = lista2->sgte;
        }
    }
    
    // Si quedaron elementos en lista1
    while (lista1 != NULL) {
        insertarDobleInt(&listaResultado, lista1->dato);
        lista1 = lista1->sgte;
    }
    // Si quedaron elementos en lista2
    while (lista2 != NULL) {
        insertarDobleInt(&listaResultado, lista2->dato);
        lista2 = lista2->sgte;
    }
    
    return listaResultado;
}
