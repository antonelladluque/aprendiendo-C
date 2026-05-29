#include <stdio.h>
#include <string.h>

struct Videojuego {
    int codigo;
    char titulo[50];
    float precio;
    int stock;
};

// Prototipos (Las funciones que debes crear abajo)
void ordenarPorCodigo(struct Videojuego inventario[], int cantidad);
void listarSinStock(struct Videojuego inventario[], int cantidad);
void buscarVideojuegoPorCodigo(struct Videojuego inventario[], int cantidad);

int main() {
    struct Videojuego inventario[100];
    int cantidad = 0;
    
    // Imagina que aqui el inventario ya se lleno con datos...
    // Y aqui se llama a las funciones en un menu.
    
    return 0;
}

// ======= TU TURNO DE PROGRAMAR =======

// 1. Desarrolla la funcion ordenarPorCodigo usando el Metodo de la Burbuja.
// Debe ordenar el arreglo de menor a mayor segun el campo 'codigo'.

    void ordenarPorCodigo(struct Videojuego inventario[], int cantidad)
{
  struct Videojuego aux;
  for (int i = 0; i < cantidad - 1; i++)
  {
    for (int j = 0; j < cantidad - i - 1; j++)
    {
      if (inventario[j].codigo > inventario[j + 1].codigo)
      {
        aux = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = aux;
      }
    }
  }
}


// 2. Desarrolla la funcion listarSinStock.
// Debe recorrer el arreglo con un ciclo 'for' y mostrar con 'printf' 
// SOLO los videojuegos cuyo 'stock' sea igual a 0.

   
void listarSinStock(struct Videojuego inventario[], int cantidad) {
	//Ordenar primero llamando a la funcion que ya existe
    ordenarPorCodigo( inventario, cantidad)


	printf("\n--- LISTA siN stock---\n");	
	for (int i = 0; i < cantidad; i++){
 		if (inventario[i].stock ==0){
        	printf("Codigo %d - SIN STOCK",inventario[j].codigo);
}}

}

// 3. Desarrolla la funcion buscarVideojuegoPorCodigo (Usa el formato VOID que querías).
// Debe llamar primero a 'ordenarPorCodigo'. Luego pedir por teclado ('scanf') el codigo a buscar,
// realizar una BUSQUEDA BINARIA, y mostrar "Encontrado" (con sus datos) o "No encontrado".
void buscarVideojuegoPorCodigo(struct Videojuego inventario[], int cantidad) {
    
 ordenarPorCodigo( inventario, cantidad)

 int buscar;
    int inicio = 0;
    int fin = cantidad - 1;
    int mitad;
    int encontrado = 0; //0 = no, 1 = si

    
    printf("\nIngrese el codigo a buscar: ");
    scanf("%d", &buscar);

        while (inicio <= fin && encontrado == 0) {
        mitad = (inicio + fin) / 2;
        
        if (inventario[mitad].codigo == buscar) {
            encontrado = 1; 
        } 
        else if (inventario[mitad].codigo < buscar) {
            inicio = mitad + 1; 
        } 
        else {
            fin = mitad - 1;   
        }
    }
    
       if (encontrado == 1) {
        printf("\n[RESULTADO] Codigo Encontrado exitosamente.\n");
        printf("Codigo: %d - titulo: %s ", 
               inventario[mitad].codigo, 
               inventario[mitad].titulo);
    } else {
        printf("\n[RESULTADO] El el cdigo  %d no existe en el sistema.\n", buscar);
    }
}

	

