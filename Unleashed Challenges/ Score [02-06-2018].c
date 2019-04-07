#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main ()
{
    char entrada[1001], saida[1001], processamento[1001];
    int primeiro, ultimo, x, y, z, scorePalavra, maiorScorePalavra;
    
    scanf ("%[^\n]s", entrada);
    getchar();
    primeiro = 0;
    maiorScorePalavra = 0;
    
    // FOR do X: Percorrer a String inteira em busca de palavras isoladas a calcular seus valores
    
    for (x = 0; x <= strlen (entrada); x++)
    {
        // IF: A cada espaço ou se chegar no final da frase, significa que já temos uma palavra isolada
        
        if ((entrada[x] == ' ') || (entrada[x] == '\0'))
        {
            ultimo = x-1;
            scorePalavra = 0;
            y = 0;
            
            // FOR do Z: Temos um início e um final, agora é calcular o valor de uma palavra com base em suas letras
            
            for (z = primeiro; z <= ultimo; z++)
            {
                if (isupper (entrada[z]))
                {
                    scorePalavra += (int) entrada[z] - 64;
                }
                else if (islower (entrada[z]))
                {
                    scorePalavra += (int) entrada[z] - 96;
                }

                processamento[y] = entrada[z];
                y++;
            }

            processamento[y] = '\0';
            
            // Se uma palavra tiver um valor maior que as anteriores, então copia-se a palavra para a String de Saída e atualiza-se o recorde de palavra com maior valor registrado
            
            if (scorePalavra > maiorScorePalavra)
            {
                strcpy (saida, processamento);
                maiorScorePalavra = scorePalavra;
            }
            
            primeiro = x+1;
        }
    }
    
    printf ("%s\n", saida);
    return 0;
}
