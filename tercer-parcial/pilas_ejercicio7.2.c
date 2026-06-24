#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para los datos de la Factura
typedef struct {
    int nroFactura;       // [cite: 152]
    char tipoFactura;     // 'A' o 'B' [cite: 153]
    char nombreCliente[50]; // [cite: 155]
} Factura;

// Nodo de la Pila de Facturas
typedef struct NodoPilaFactura {
    Factura datos;
    struct NodoPilaFactura* sgte;
} NodoPilaFactura;

// Función para apilar (Push)
void pushFactura(NodoPilaFactura** tope, Factura f) {
    NodoPilaFactura* nuevo = (NodoPilaFactura*)malloc(sizeof(NodoPilaFactura));
    nuevo->datos = f;
    nuevo->sgte = *tope;
    *tope = nuevo;
}

// Función para clasificar un listado mezclado en dos pilas separadas
void clasificarFacturas(Factura listaMezclada[], int cantidad, NodoPilaFactura** pilaA, NodoPilaFactura** pilaB) {
    // Recorremos las facturas en el orden en que se emitieron
    for (int i = 0; i < cantidad; i++) {
        if (listaMezclada[i].tipoFactura == 'A' || listaMezclada[i].tipoFactura == 'a') {
            pushFactura(pilaA, listaMezclada[i]); // [cite: 150]
        } else if (listaMezclada[i].tipoFactura == 'B' || listaMezclada[i].tipoFactura == 'b') {
            pushFactura(pilaB, listaMezclada[i]); // [cite: 150]
        }
    }
}
