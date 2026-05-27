#include <stdio.h>

int main()
{
int i,j,suma;
int filas = 5;
int columnas = 3;
int matriz[5][2];
float prom;

suma=0;
prom=0;
int totalElementos = filas * columnas;

/*Cargar matriz mat*/
for (i = 0; i<5; i++)
{
    for (j=0; j<2; j++)
    {
        printf("Ingresar el elememto % i-%i= ", i, j);
        scanf("%d", &matriz[i][j]);
    }
}
printf (" matriz\n");
for (i = 0; i<5; i++)
{
    printf("| ");
for (j=0; j<2; j++)
{
    printf("%2d", matriz[i][j]);
}
printf("\t |");
printf("\n");
}

for (i = 0; i<5; i++)
{
    for (j=0; j<2; j++)
    {
         suma += matriz[i][j];
    }
}

prom= (float) suma / (float)totalElementos;

printf("La sumatoria de todos los elementos es: %d \n", suma);
printf("La promedio de todos los elementos es: %.2f \n", prom);

return 0;

}
