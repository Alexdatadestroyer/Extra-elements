#include <stdio.h>

int main ()
{
    int alturaPiramide, pivo, i, j;
    
    scanf ("%d", &alturaPiramide);
    
    pivo = 0;
    
    for (i = alturaPiramide; i >= 3; i -= 2)
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
    
    for (i = 1; i <= alturaPiramide; i += 2)
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
    
    return 0;
}
