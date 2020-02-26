/*	Algoritmo para testes de execução em Complexidade Fatorial [O(n!)]

	Autor: Alexandre Gadelha da Silva Carvalho
	Data: 25 de Fevereiro de 2020
	
	Este algoritmo visa simular uma das complexidades raras de se encontrar em tempos de execução: Notação Big-O Fatorial
	
	Notação: O(n!)
	Valores recomendados: Até N = 10, onde irá executar em até 3,68 x 10^6 vezes cabendo em 1 segundo como Tempo Limite.
	
	A variável em questão, do tipo "long long int", suporta valores em até N = 20. Contudo, executar esse valor, fará com que o tempo
	de espera pelo resultado seja astronomicamente grande, não sendo recomendado a sua execução. Um aviso foi inserido no algoritmo
	para caso o valor de N seja igual ou maior que 13.
	
	Um método para exibição de valores de forma rápida foi inserida no algoritmo para funcionar entre os valores 13 e 20 para N. A
	complexidade foi baixada para Linear [O(n)], que, geralmente, é a forma preferida para solução de fatoriais.
*/

#include <stdio.h>

long long int executaFatorial13Ate20 (int numero)
{	
	if ((numero == 1) || (numero == 0))
	{
		return 1;
	}
	else
	{		
		return (numero * executaFatorial13Ate20 (numero-1));
	}
}

long long int executaFatorialAte12 (int numero)
{
	long long int resultado = 0;
	int i;
	
	if ((numero == 1) || (numero == 0))
	{
		return 1;
	}
	else
	{
		for (i = 0; i < numero; i++)
		{
			resultado += executaFatorialAte12 (numero-1);
		}
		
		return resultado;
	}
}

int main ()
{
	int numero, opcao;
	
	printf ("Informe um numero N qualquer: ");
	
	scanf ("%d", &numero);
	
	if ((numero >= 13) && (numero <= 20))
	{
		printf ("O tempo de resposta tende a ser astronomicamente GRANDE! Deseja realmente prosseguir? (1-sim)(2-nao)\n");
		
		scanf ("%d", &opcao);
		
		if (opcao == 1)
		{
			printf ("Resultado: %lld\n", executaFatorialAte12(numero));
		}
		else if (opcao == 2)
		{
			printf ("Preferindo o metodo mais simples e rapido, o resultado e: %lld\n", executaFatorial13Ate20(numero));
		}
		else
		{
			printf ("Opcao invalida!\n");
		}
	}
	else if ((numero >= 0) && (numero < 13))
	{
		printf ("Resultado: %lld\n", executaFatorialAte12(numero));
	}
	else
	{
		printf ("Numero Negativo OU Maior do que 20 detectado!\n");
	}
	
	return 0;
}
