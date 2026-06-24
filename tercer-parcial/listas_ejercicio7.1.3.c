// Insertar al final
void insertarAlFinal(NodoSimple** inicio, char letra) { // 
    insertarSimple(inicio, letra); 
}

// Recuperar un elemento por posición (0-indexed)
char recuperarElemento(NodoSimple* inicio, int pos) { // 
    int cont = 0;
    while (inicio != NULL) {
        if (cont == pos) return inicio->letra;
        inicio = inicio->sgte;
        cont++;
    }
    return '\0'; // Retorna vacío si no existe la posición
}

// Devuelve el número de objetos en la lista
int contarElementos(NodoSimple* inicio) { // 
    int cont = 0;
    while (inicio != NULL) {
        cont++;
        inicio = inicio->sgte;
    }
    return cont;
}
