#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura con la información requerida
typedef struct {
    int dni;
    char nombreApellido[100];
    char linkProyecto[200];
} ProyectoAlumno;

// Nodo de la Cola
typedef struct NodoCola {
    ProyectoAlumno info;
    struct NodoCola* sgte;
} NodoCola;

// Estructura de control para la Cola
typedef struct {
    NodoCola* frente;
    NodoCola* fin;
} ColaProyectos;

// Función para inicializar la cola
void inicializarCola(ColaProyectos* q) {
    q->frente = NULL;
    q->fin = NULL;
}

// Función para encolar (Queue / Insertar al final)
void encolarProyecto(ColaProyectos* q, ProyectoAlumno proyecto) {
    NodoCola* nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    nuevo->info = proyecto;
    nuevo->sgte = NULL;
    
    if (q->fin == NULL) { // Si la cola estaba vacía
        q->frente = nuevo;
        q->fin = nuevo;
    } else {
        q->fin->sgte = nuevo;
        q->fin = nuevo;
    }
}
