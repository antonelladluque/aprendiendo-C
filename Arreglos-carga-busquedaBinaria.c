/******************************************************************************
Ejercicio 5: Arreglos-Registros
5.1. Una empresa de servicios de limpieza necesita almacenar en un arreglo la
siguiente información:
• Nro de Cliente
• Tipo de Cliente ( E: Empresa – P: Particular)
• Nombre del Cliente
• Nro.Celular de Contacto

 Se pide:
• Cargar el arreglo.
• Ordenar el arreglo por Nro. de Cliente en orden ascendente.
• Mostrar por pantalla el listado de clientes ordenados con el siguiente
formato
• Realizar la búsqueda de un cliente por su número. Aplicar búsqueda
binaria.
• A partir del arreglo ordenado, generar dos arreglos, uno que contenga
los clientes tipo E y otro que contenga los clientes tipo P
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define TAM 5

int main()
{
struct estructura_cliente
{
int nro_cliente;
char tipoCliente;  
char nombre_cliente[40];
char telefono[15];
};
   int i,j;
   int totalClientes=0, totalClientes_E=0, totalClientes_P=0;

struct estructura_cliente clientes[TAM]; /* Declaramos la variable cliente con esa estructura */
struct estructura_cliente aux_ordenado;

// Arreglos adicionales para separar por tipo
    struct estructura_cliente clientes_E[TAM];
    struct estructura_cliente clientes_P[TAM];
    
    printf("--- CARGA DE CLIENTES ---\n");
        for (i = 0; i < TAM; i++) {
            printf("\n--- Cliente %d ---\n", i + 1);
       
            printf("Escribe el numero de cliente: ");  
            scanf("%d", &clientes[i].nro_cliente);
       
        do {
            printf("Escribe el tipo de cliente (E- Empresa | P- Particular): ");
            scanf(" %c", &clientes[i].tipoCliente);
    
    
             if (clientes[i].tipoCliente == 'E' || clientes[i].tipoCliente == 'e') {
                clientes[i].tipoCliente = 'E'; // Estandarizamos a mayúscula
                totalClientes_E++;
            } else if (clientes[i].tipoCliente == 'P' || clientes[i].tipoCliente == 'p') {
                clientes[i].tipoCliente = 'P'; // Estandarizamos a mayúscula
                totalClientes_P++;
        }
           
            totalClientes++;


            if (clientes[i].tipoCliente != 'E' && clientes[i].tipoCliente != 'P') {
                printf("Error: Entrada no valida. Por favor, ingresa solo 'E' o 'P'.\n");
            }

        } while (clientes[i].tipoCliente != 'E' && clientes[i].tipoCliente != 'P');
       
            printf("Escribe el nombre de cliente: ");  
            scanf("%s", clientes[i].nombre_cliente);
       
            printf("Escribe el numero de celular: ");  
            scanf("%s", clientes[i].telefono);
           
           
    }

//ordenar ascendentemente por numero de cliente
for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - i - 1; j++) {
            if (clientes[j].nro_cliente > clientes[j+1].nro_cliente) {
                aux_ordenado = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux_ordenado;
            }
        }
    }
//Mostramos por pantalla los registros con formato de informe
printf("\n\n------------------------------------------------\n");
printf("------------Listado de clientes -----------------\n");
printf("------------------------------------------------\n");
printf("-Nro de cliente ----Tipo de cliente -----Nombre -----Nro de contacto -\n");

for(i = 0; i < TAM; i++) {
     
        printf("%-15d | %-15c | %-20s | %-15s\n", clientes[i].nro_cliente, clientes[i].tipoCliente, clientes[i].nombre_cliente, clientes[i].telefono);
    }
    printf("---------------------------------------------------------------------\n");
    printf("Total de Clientes: %d\n", totalClientes);
    printf("Total de Clientes tipo E: %d\n", totalClientes_E);
    printf("Total de Clientes tipo P: %d\n", totalClientes_P);

//busqueda binaria por numero de cliente
    printf("\n--- BUSQUEDA DE CLIENTE ---\n");
    int buscar, inicio = 0, fin = TAM - 1, mitad, encontrado = 0;
    
    printf("Ingrese el numero de cliente a buscar: ");
    scanf("%d", &buscar);
    
    while (inicio <= fin && !encontrado) {
        mitad = (inicio + fin) / 2;
        
        if (clientes[mitad].nro_cliente == buscar) {
            encontrado = 1; // Lo encontramos
        } else if (clientes[mitad].nro_cliente < buscar) {
            inicio = mitad + 1; // Buscar en la mitad derecha
        } else {
            fin = mitad - 1; // Buscar en la mitad izquierda
        }
    }
    
    if (encontrado) {
        printf("\n¡Cliente Encontrado!\n");
        printf("Nombre: %s | Tipo: %c | Telefono: %s\n", clientes[mitad].nombre_cliente, clientes[mitad].tipoCliente, clientes[mitad].telefono);
    } else {
        printf("\nEl cliente con numero %d no existe.\n", buscar);
    }

    // arreglos de clientes tipo E y P
    int idx_E = 0, idx_P = 0;
    for (i = 0; i < TAM; i++) {
        if (clientes[i].tipoCliente == 'E') {
            clientes_E[idx_E] = clientes[i];
            idx_E++;
        } else if (clientes[i].tipoCliente == 'P') {
            clientes_P[idx_P] = clientes[i];
            idx_P++;
        }
    }

    //mostramos los arreglos divididos para verificar
    printf("\n--- CLIENTES TIPO E (EMPRESAS) ---\n");
    for(i = 0; i < idx_E; i++) {
        printf("Nro: %d - %s\n", clientes_E[i].nro_cliente, clientes_E[i].nombre_cliente);
    }

    printf("\n--- CLIENTES TIPO P (PARTICULARES) ---\n");
    for(i = 0; i < idx_P; i++) {
        printf("Nro: %d - %s\n", clientes_P[i].nro_cliente, clientes_P[i].nombre_cliente);
    }

return 0;
}
