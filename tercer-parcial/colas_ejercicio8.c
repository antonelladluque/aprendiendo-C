#include <stdlib.h>


typedef struct NodoArbol {
	int info;
	struct NodoArbol* izq;
	struct NodoArbol* der;
} NodoArbol;


NodoArbol* crearNodo(int valor) {
	NodoArbol* nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
	if (nuevo == NULL) {
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	nuevo->info = valor;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	return nuevo;
}

NodoArbol* construirArbolInteractivos() {
	int valor;
	char respuesta;
	
	printf("Ingrese el valor para este nodo (entero): ");
	scanf("%d", &valor);
	

	NodoArbol* nuevoNodo = crearNodo(valor);
	

	printf("¿El nodo [%d] tiene hijo IZQUIERDO? (s/n): ", valor);
	scanf(" %c", &respuesta);
	if (respuesta == 's' || respuesta == 'S') {
		nuevoNodo->izq = construirArbolInteractivos();
	}
	

	printf("¿El nodo [%d] tiene hijo DERECHO? (s/n): ", valor);
	scanf(" %c", &respuesta);
	if (respuesta == 's' || respuesta == 'S') {
		nuevoNodo->der = construirArbolInteractivos();
	}
	
	return nuevoNodo;
}


void preorden(NodoArbol* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->info);
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}


void inorden(NodoArbol* raiz) {
	if (raiz != NULL) {
		inorden(raiz->izq);
		printf("%d ", raiz->info);
		inorden(raiz->der);
	}
}


void postorden(NodoArbol* raiz) {
	if (raiz != NULL) {
		postorden(raiz->izq);
		postorden(raiz->der);
		printf("%d ", raiz->info);
	}
}


void liberarArbol(NodoArbol* raiz) {
	if (raiz != NULL) {
		liberarArbol(raiz->izq);
		liberarArbol(raiz->der);
		free(raiz);
	}
}

// --- FUNCIÓN PRINCIPAL MAIN ---
int main() {
	NodoArbol* miArbol = NULL;
	
	printf("---- CONSTRUCCIoN DEL ARBOL BINARIO ----\n");
	miArbol = construirArbolInteractivos();
	
	printf("\n----- RECORRIDOS DEL ARBOL RESULTANTE ----\n");
	
	printf("Preorden: ");
	preorden(miArbol);
	printf("\n");
	
	printf("Inorden: ");
	inorden(miArbol);
	printf("\n");
	
	printf("Postorden: ");
	postorden(miArbol);
	printf("\n");
	
	
	liberarArbol(miArbol);
	
	return 0;
}
