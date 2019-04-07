#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main ()
{
    char entrada[1001], saida[1000][1001];
    int inicio, final, i, j, x1, x2;
    
    scanf ("%[^\n]s", entrada);
    getchar();
    
    inicio = 0;        // Variável de início da palavra
    x1 = 0;        // Variável de percurso das Linhas da String de Saída
    
    // FOR do I: Percorrer a String de Entrada em busca de palavras pra separá-las numa lista...
    
    for (i = 0; i <= strlen (entrada); i++)
    {
        // IF: Aqui o filtro é o valor de uma posição da String não ser alfabético [a-z] e [A-Z]
        
        if (!isalpha (entrada[i]))
        {
            // IF: Caso exclusivo: Se uma Letra NÃO VIER depois de um caractere não-alfabético, pegaremos outra pra servir de início da palavra (que, espera-se, ser alfabético, pois caso contrário...)
            
            if (i == inicio)
            {
                inicio = i+1;
            }
            else
            {
                final = i-1;    // Variável de final da palavra
                x2 = 0;        // Variável de percurso das Colunas da String de Saída
                
                // FOR do J: Ir acrescentando letra por letra na String de Entrada na String de Saída
                
                for (j = inicio; j <= final; j++)
                {
                    saida[x1][x2] = entrada[j];
                    x2++;
                }
                
                saida[x1][x2] = '\0';
                x1++;
                inicio = i+1;
            }
        }
    }
    
    // FOR do I usando o X1: Impressão de todas as palavras a cada linha nova
    
    for (i = 0; i < x1; i++)
    {
        printf ("%s\n", saida[i]);    
    }
    
    return 0;
}
