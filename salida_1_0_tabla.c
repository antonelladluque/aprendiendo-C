/* salida 
  1 1 1 
  0 1 1 
  0 0 1 */

#include <stdio.h>

int main()
{
    
    int j, i ; 
    
    for (i=1 ; i<=3 ; i++){
        for (j=1 ; j<=3 ; j++){
            if (i <= j) {
                printf("1");
        }else {
            printf("0");
        }
    }
    printf ("\n");
    }

    return 0;
}
