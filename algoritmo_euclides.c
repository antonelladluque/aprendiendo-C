/* resolver el algoritmo de euclides que encuentre el maximo comun divisor de enteros positivos
el algortimo transforma un par de enteros positivos (n,m) en (b,o)
diviendo repetidamente el entero mayor por el menor  y reemplanzando el mayor
con el resto es cero el otro entero de la pareja sera el maximo comun divisor*/
#include <stdio.h>

// Función que implementa el algoritmo de Euclides
int calcular_mcd(int n, int m) {
int resto;

while (m != 0) {
  resto = n % m;
  n = m;        
  m = resto;    
}

return n; // Cuando m es 0, n es el MCD
}

int main() {
  int n, m;

  printf("Introduce el primer número: ");
  scanf("%d", &n);
  printf("Introduce el segundo número: ");
  scanf("%d", &m);

  if (n <= 0 || m <= 0) {
    printf("Por favor, introduce solo números enteros positivos.\n");
  return 1;
}

  int resultado = calcular_mcd(n, m);
  printf("El Máximo Común Divisor de %d y %d es: %d\n", n, m, resultado);

  return 0;
}
