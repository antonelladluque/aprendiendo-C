#include <stdio.h>
#include <string.h>

struct Alumno {
    int legajo;
    char nombre[30];
    float promedio;
    char estado; // 'R' para Regular, 'L' para Libre
};

// Prototipos
void listarAlumnosRegulares(struct Alumno lista[], int cantidad);
void ordenarAlumnosPorPromedio(struct Alumno lista[], int cantidad);
void mostrarAlumnosPorPromedio(struct Alumno lista[], int cantidad); 

int main() {
    struct Alumno lista[100];
    int cantidad = 0;
     mostrarAlumnosPorPromedio(lista, cantidad)    

return 0;


}

// ======= TU TURNO DE PROGRAMAR =======

// 1. Desarrolla la funcion listarAlumnosRegulares.
// Debe mostrar en pantalla con 'printf' unicamente a los alumnos 
// cuyo campo 'estado' sea exactamente igual al caracter 'R'.


void listarAlumnosRegulares(struct Alumno lista[], int cantidad) {
     printf("-- ALUMNOS REGULARES -- \n\n");
	 

	for (int i=0 ; i < cantidad ; i++) {
		if (lista[i].estado == 'R' || lista[i].estado == 'r') { 
		 	printf("El alumno/a %s esta en condicion de regular",lista[i].nombre);
}
}

}

// 2. Desarrolla la funcion ordenarAlumnosPorPromedio.
// Debe ordenar el arreglo de alumnos usando el Metodo de la Burbuja,
// pero esta vez de MAYOR A MENOR (los mejores promedios primero) mirando el campo 'promedio'.



void ordenarAlumnosPorPromedio(struct Alumno lista[], int cantidad) {
    struct Alumno aux;
  for (int i = 0; i < cantidad - 1; i++){
    for (int j = 0; j < cantidad - i - 1; j++){
      
      if (lista[j].promedio < lista[j + 1].promedio)
      {
        aux = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = aux;
      }
    }
  }
}


void mostrarAlumnosPorPromedio(struct Alumno lista[], int cantidad) {
	printf("-- ALUMNOS CON MEJORES PROMEDIOS -- \n\n");
	 
ordenarAlumnosPorPromedio(lista, cantidad);

	for (int i=0 ; i < cantidad ; i++) {
		
		 	printf("Alumno:  %s -- PROMEDIO: %.2f \n", 
                  lista[i].nombre, lista[j].promedio);
}
}
