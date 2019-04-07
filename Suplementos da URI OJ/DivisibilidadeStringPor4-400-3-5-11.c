/* Ordem de Saída segundo o exercício, seguido das estratégias de cálculo:
		
	-> This is leap year. [Anos bissextos OU seculares divisíveis por 400 (ou seja, divisível por 4 e 100)]
	-> This is huluculu festival year. (Anos divisíveis por 15, ou seja, 3 E 5 ao mesmo tempo)
	-> This is bulukulu festival year. (Anos divisíveis por 55, ou seja, 11 E 5 ao mesmo tempo E Bissextos)
	-> This is an ordinary year. (Anos comuns que NÃO correspondem com as condições ACIMA)
		   
	Informações sobre divisibilidade aqui: [http://www.uel.br/projetos/matessencial/fundam/naturais/divisibilidade.htm]
		
		
	1) This is leap year. Começar a verificar divisibilidade 4 e depois pra 100 e 400 em anos seculares:
		
	   -> Divisibilidade de 4 se dá pela EXTRAÇÃO dos 2 ÚLTIMOS ALGARISMOS de um Número qualquer
	   -> Divisibilidade por 400 se dá pela EXTRAÇÃO dos 2 Algarismos correspondentes a Centena e Unidade de Milhar,
	      respectivamente, ou seja, Y00 e X000, onde X e Y serão os 2 Algarismos extraídos.
		      
	   Em ambas as condições acima desse sub-bloco, se os algarismos forem "00" será interpretado como:
		   
	   -> 100 pra caso de Divisibilidade por 4
	   -> 10000 pra caso de Divisibilidade por 400 (que também deverá ser divisível por 100)
		
		
	2) This is huluculu year. Começar a verificar divisibilidade por 3 e depois por 5:
		
	   -> Divisibilidade por 3 se dá quando a SOMA dos Algarismos é IGUAL a 3, 6 ou 9 (0), resumidamente.
	   -> Divisibilidade por 5 se dá quando o Número possui o ÚLTIMO Algarismo IGUAL a 5 ou 0.
	   
	   Para extração da SOMA dos Algarismos, pode ser usado o Módulo por 9 que sempre irá devolver a
	   SOMA dos Algarismos a verificar se é IGUAL a 3, 6 ou 9 (que dará 0 porque será divisível por 9).
		   
	   Contudo, como aqui NÃO sabemos o Número como um todo, o ideal seria mesmo percorrer o Vetor inteiro
	   e ir somando os Números um a um e DEPOIS retirar o resultado via Módulo 9 - que dará no mesmo resultado
	   proposto com a estratégia anterior desse sub-bloco.
		
		
	3) This is bulukulu year. Começar a verificar divisibilidade por 5 e 11 que compoem 55 E o Ano ser Bissexto:
		
	   -> Divisibilidade por 5 se dá quando o Número possui o ÚLTIMO Algarismo IGUAL a 5 ou 0.´
	   -> Divisibilidade por 11 se dá quando a DIFERENÇA da SOMA as ordens PARES e ÍMPARES (posições) do Número em si
	   SÃO IGUAIS a ZERO OU produz um resultado divisível por 11.
		   
	   Em outras palavras, trata-se de vasculhar o Número como se fosse um Vetor com um Algarismo em cada posição
	   ir somando as ordens ÍMPARES separadamente das ordens PARES até o final deste Número.
		   
	   Depois, a ideia é comparar a SOMA dessas ordens Pares e Ímpares e verificar se a DIFERENÇA entre elas é IGUAL a
	   ZERO ou irá produzir um Número que seja divisível por 11. Caso Positivo, o Número é divisível por 11.
	   
	   OBS: O Ano em questão DEVE ser Bissexto.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
	char anoGigante[1002], algarismosPra4[3], algarismosPra400[3];
	int anoTamanho, numeroPra4, numeroPra400, somaDiv3, somaParPos11, somaImparPos11, diferencaParImpar11;
	int i, anoComum, anoBissexto;
	
	anoTamanho = 0;
	
	while (scanf ("%s", anoGigante) != EOF)
	{
		anoComum = 1;
		anoBissexto = 0;
		
		if (anoTamanho != 0)
		{
			printf ("\n");
		}
		
		anoTamanho = strlen (anoGigante);
		
		algarismosPra4[0] = anoGigante[anoTamanho-2];
		algarismosPra4[1] = anoGigante[anoTamanho-1];
		algarismosPra4[2] = '\0';
		
		numeroPra4 = atoi (algarismosPra4);
		
		if (numeroPra4 == 0)
		{
			numeroPra4 = 100;
		}
		
		/* IF: Ano secular (divisível por 100) que PODE ou não ser divisível por 400
		   ELSE: Ano comum que PODE ser Bissexto ou não (divisível por 4)
		*/
		
		if ((algarismosPra4[0] == '0') && (algarismosPra4[1] == '0'))
		{
			algarismosPra400[0] = anoGigante[anoTamanho-4];
			algarismosPra400[1] = anoGigante[anoTamanho-3];
			algarismosPra400[2] = '\0';
		
			numeroPra400 = atoi (algarismosPra400) * 100;
			
			if (numeroPra400 == 0)
			{
				numeroPra400 = 10000;
			}
			
			if (numeroPra400 % 400 == 0)
			{
				printf ("This is leap year.\n");
				anoComum = 0;
				anoBissexto = 1;
			}
		}
		else
		{
			if (numeroPra4 % 4 == 0)
			{
				printf ("This is leap year.\n");
				anoComum = 0;
				anoBissexto = 1;
			}
		}
		
		/* Verificação da divisibilidade por 3 E 5 -> divisibilidade por 15 */
		
		somaDiv3 = 0;
		
		for (i = 0; anoGigante[i] != '\0'; i++)
		{
			somaDiv3 += (int) ((anoGigante[i]) - 48);
		}
		
		somaDiv3 %= 9;
		
		if (((somaDiv3 % 3 == 0)) && ((anoGigante[anoTamanho-1] == '5') || (anoGigante[anoTamanho-1] == '0')))
		{
			printf ("This is huluculu festival year.\n");
			anoComum = 0;
		}
		
		/* Verificação da divisibilidade por 11 E 5 -> divisibilidade por 55 */
		
		somaParPos11 = 0;
		somaImparPos11 = 0;
		
		for (i = 0; anoGigante[i] != '\0'; i++)
		{
			if (i % 2 == 0)
			{
				somaImparPos11 += (int) ((anoGigante[i]) - 48);
			}
			else
			{
				somaParPos11 += (int) ((anoGigante[i]) - 48);
			}
		}
		
		diferencaParImpar11 = abs (somaImparPos11 - somaParPos11);
		
		if (((diferencaParImpar11 % 11 == 0)) && ((anoGigante[anoTamanho-1] == '5') || (anoGigante[anoTamanho-1] == '0')) && ((anoBissexto)))
		{
			printf ("This is bulukulu festival year.\n");
			anoComum = 0;
		}
		
		if (anoComum)
		{
			printf ("This is an ordinary year.\n");
		}
	}
	
	return 0;
}
