#include <stdio.h>

long long int calculaFatorial (int numero)
{
    long long int resultado = 1;
    
    while (numero > 1)
    {
        resultado *= numero;
        numero--;
    }
    
    return resultado;
}

int main ()
{
    int linhas, l, c;
    long long int linhasFatorial, cFatorial, linhascFatorial, elemento;
    
    scanf ("%d", &linhas);
    
    for (l = 0; l < linhas; l++)
    {
        for (c = 0; c < l+1; c++)
        {
            linhasFatorial = calculaFatorial (l);
            cFatorial = calculaFatorial (c);
            linhascFatorial = calculaFatorial (l - c);
            
            elemento = (linhasFatorial / (cFatorial * linhascFatorial));
            
            (c == 0) ? printf ("%lld", elemento) : printf (" %lld", elemento);
        }
        printf ("\n");
    }
    
    return 0;
}
