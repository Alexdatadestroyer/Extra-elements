#include <stdio.h>

int verificaMatriz (int linhas, int colunas, char matriz[linhas][colunas])
{
    int l, c, x, contVogal, tem4Vogais;
    char quadrantes[4];

    for (l = 0; l < linhas-1; l++)
    {
        for (c = 0; c < colunas-1; c++)
        {
            quadrantes[0] = matriz[l][c+1];
            quadrantes[1] = matriz[l][c];
            quadrantes[2] = matriz[l+1][c];
            quadrantes[3] = matriz[l+1][c+1];

            contVogal = 0;
            tem4Vogais = 0;

            // Verificação de cada um dos 4 elementos do Vetor "quadrantes" em busca das letras a, e, i, o, u
            
            for (x = 0; x < 4; x++)
            {
                if ((quadrantes[x] == 'a') || (quadrantes[x] == 'e') || (quadrantes[x] == 'i') || (quadrantes[x] == 'o') || (quadrantes[x] == 'u'))
                {
                    contVogal++;
                }
            }

            // IF: Se acontecer de serem encontradas 4 vogais, então não há mais necessidade de continuar a busca.

            if (contVogal == 4)
            {
                tem4Vogais = 1;
                break;
            }
        }

        // IF: Se já encontramos um quadrado de 4 vogais, então para-se o processo de verificação linha a linha.

        if (tem4Vogais)
        {
            break;
        }
    }

    if (tem4Vogais)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    int linhas, colunas, l, c, retorno;

    scanf ("%d %d", &linhas, &colunas);
    getchar();

    char matriz[linhas][colunas];

    for (l = 0; l < linhas; l++)
    {
        for (c = 0; c < colunas; c++)
        {
            matriz[l][c] = getchar();
            getchar();
        }
    }

    retorno = verificaMatriz (linhas, colunas, matriz);

    // Verificação do retorno (1 ou 0) da função "verificaMatriz" acima

    (retorno) ? printf ("True\n") : printf ("False\n");

    return 0;
}
