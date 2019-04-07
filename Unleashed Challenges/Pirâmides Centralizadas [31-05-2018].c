#include <stdio.h>

int main ()
{
    int alturaPiramide, pivo, pivoMestre, i, j, k;
    
    scanf ("%d", &alturaPiramide);
    
    pivoMestre = ((alturaPiramide-1) / 2);
    
    for (k = 1; k <= alturaPiramide; k += 2)
    {
        pivo = pivoMestre;
        
        for (i = k; i >= 3; i -= 2)
        {
            for (j = 0; j < pivo; j++)
            {
                printf (" ");
            }
        
            for (j = 1; j <= i; j++)
            {
                printf ("*");
            }
            pivo++;
            printf ("\n");
        }
    
        for (i = 1; i <= k; i += 2)
        {
            for (j = 0; j < pivo; j++)
            {
                printf (" ");
            }
        
            for (j = 1; j <= i; j++)
            {
                printf ("*");
            }
            pivo--;
            printf ("\n");
        }
        pivoMestre--;
    }
    
    return 0;
}
