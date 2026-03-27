
#include <stdio.h>
#include <math.h>

int main()
{
   //declaracion de variables 
   int cara, seca, contador, moneda;
   float porcentaje_cara, porcentaje_seca; 
   
   //inicializacion de variables
    contador = 0; 
    cara = 0;
    seca= 0;

    
    //proceso
    while ( contador<10){
        printf ("Ingrese 1-cara o 2- seca\n");
        scanf("%i", &moneda);
        
        if ((moneda != 1) && (moneda !=2)){
            printf("Dato incorrecto, por favor ingrese 1-cara 2-seca\n\n");
        }
        else{
            if (moneda==1){
                cara++;
            }
            else{
                seca++;
            }
            contador++;
        }
    }

porcentaje_cara = ((float) cara/contador)*100;
porcentaje_seca = ((float) seca/contador)*100;

printf("El porcentaje de cara fue %0.1f%% \n", porcentaje_cara);
printf("El porcentaje de seca fue %0.1f%% \n", porcentaje_seca);


    return 0;
}
