#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int casos, i, j, a, b, c, valor, vdecimal;              // A: Anterior | B: Meio | C: Posterior (elemento-termo)
	char input[10001], output[4];				// Entrada: 10000 dígitos no Máximo | Saída: 3 dígitos
	
	scanf ("%d", &casos);
	
	/* Casos de testes a executar de acordo com o Valor da Variável "casos" */
	
	while (casos > 0)
	{
		scanf ("%s", input);
		
		/* RESET de Variáveis-chave em cada caso de teste */
			
		a = 1;
		b = 0;
		c = 0;
		vdecimal = 0;
			
		/* Conversão de Binário pra Decimal de uma String por meio de um padrão em específico: Número MOD 1500
		   
		   Este padrão (Número MOD 1500) possui a função de delimitar a futura procura de elementos da Sequência de
		   Fibonacci que retorne um NÚMERO CUJA SEQUÊNCIA seria igual a uma procura de elemento-termo por meios normais.
		   
		   Assim, seria feita a procura de forma mais rápida por um elemento-termo que possui o mesmo padrão dos 3 últimos
		   dígitos IGUAIS. Exemplo: O 1505º possui a mesma tríade do 5º termo que é o "005" como padrão. De 1500 em 1500,
		   a tríade de valores padronizados se repetirá.
			
		   Logo, NÃO há necessidade de pesquisar até o 1505º termo da Sequência de Fibonacci sabendo que o final dele
		   será "005" assim como o 5º termo. O que interessa aqui neste exercício NÃO É saber qual o elemento-termo
		   em específico da Sequência de Fibonacci, mas, SIM, qual a tríade específica em seu final - os últimos 3
		   dígitos do elemento-termo correspondente ao termo X da Sequência.
		   
		   A linha abaixo marcada como "vdecimal %= 1500 (vdecimal = vdecimal % 1500)" trata exatamente disso! */
			
		for (j = 0; input[j] != '\0'; j++)
		{
            		vdecimal *= 2;					// Multiplicação de 2 em 2 por se tratar de um Número Binário
            		vdecimal += (int) (input[j] - 48);
            
            		if (vdecimal >= 1500)
            		{
                		vdecimal %= 1500;			// Delimitando o termo a ser procurado na Sequência de Fibonacci
            		}
        	}
			
		/* Achando o Termo da Sequência de Fibonacci correspondente ao recebido na Variável "vdecimal" já delimitado.
		   
		   Anteriormente, delimitamos a procura de um Termo da Sequência de Fibonacci por meio de um padrão específico
		   onde [Número MOD 1500] seria o responsável por executar tal ação.
		   
		   Agora, devemos tratar o elemento-termo também que irá crescer uma quantidade astronômica na medida em que o
		   Termo correspondente da Sequência é encontrado. Contudo, NÃO EXISTEM variáveis numéricas que suportarão
		   tamanho Valor. Logo, a solução é delimitá-lo também deixando APENAS a tríade final deste elemento em
		   evidência para ser somado o ANTERIOR (a) e com o MEIO (b). O resultado NÃO SAIRÁ conforme o esperado, contudo
		   a tríade final PERMANECERÁ sem alteração.
		   
		   > Ex 1: 18º Termo (2584) sairá 1584, pois ainda herdará o Valor do 16º elemento que era MENOR QUE 1000 (987).
		   > Ex 2: 20º Termo (6765) sairá 765, já arrumado uma vez que Valores posteriores JAMAIS serão iguais a 1000. */
		
		for (j = 0; j < vdecimal; j++)
		{
			c = (a + b);
			
			if (c >= 1000)
			{
			    c %= 1000;
			}
			
			a = b;
			b = c;
		}
			
		/* Na Saída, devemos mostrar apenas os 3 últimos dígitos do elemento da Sequência de Fibonacci numa String */
			
		output[3] = '\0';
		for (j = 2; j >= 0; j--)
		{
			valor = c % 10;
			output[j] = (char) valor + 48;
			c /= 10;
		}
			
		printf ("%s\n", output);
		casos--;
	}
	return 0;
}
