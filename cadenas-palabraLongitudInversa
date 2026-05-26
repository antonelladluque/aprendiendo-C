/******************************************************************************
Programa: Contador e Inversor de Palabras
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char palabra[50];
    char palabra_inv[50];
    int longitud;
    int i,j;
  
    printf("Ingresa una palabra: ");
    // Usamos scanf con %s ya que pide una palabra
    scanf("%s", palabra); 

 
    // strlen() cuenta los caracteres reales sin incluir el caracter nulo '\0'
    longitud = strlen(palabra); 
    
    printf("\nLa palabra \"%s\" tiene %d letras.\n", palabra, longitud);

    j=0;
    for (i = longitud - 1; i >= 0; i--) {
        palabra_inv[j]= palabra[i];
        j++;
    }
    palabra_inv[j] = '\0';
  
    printf("Palabra invertida: %s ", palabra_inv);

    return 0;
}
