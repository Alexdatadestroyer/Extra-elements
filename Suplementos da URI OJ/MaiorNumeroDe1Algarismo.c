/* ATUALIZADO EM 04 DE ABRIL DE 2019
   MOTIVO: ADIÇÃO DE MAIS COMENTÁRIOS PRA DEIXAR MAIS CLARO O QUE FOI FEITO.
   VERSÃO FINAL MELHORADA.
*/

#include <stdio.h>

int verificar2Numeros (char numeral[])
{
	int maiorAlgarismoNumero, somaNumero;
	int i;
	
	somaNumero = 0;
	
	for (i = 0; numeral[i] != '\0'; i++)
	{
		somaNumero += (int) (numeral[i] - 48);
	}
	
	/* Divide-se o Número por 9 e pega-se o seu Resto (Módulo) justamente pela GARANTIA DE 100% de obter a SOMA
	   DOS ALGARISMOS de qualquer Número, independentemente da sua quantidade de algarismos, de forma direta e
	   prática sem a necessidade da Divisão Individual dos Algarismos (Módulo 10) a somar um a um.
	   
	   Essa divisão por 9 para pegar o Resto (Módulo por 9) também vale para SOMA dos algaritmos pegos um a um
	   numa varredura num Vetor não valendo somente para um Número já formado. No caso desse exercício, como não
	   se pode pegar um Número inteiro formado, foi somado os algaritmos um a um, mas ainda não teremos o maior
	   algarismo em si, levando em consideração todos eles. Pra isso que será feito a divisão por 9 e extraído o
	   seu Resto. Essa também é outra forma de se obter o Maior Algarismo de um Número qualquer.
	   
	   Contudo, existe um Caso Especial quando esse Número for divisível por 9 (Número % 9 == 0) onde a SOMA
	   DOS ALGARISMOS tende a ser o próprio 9.
	*/
	
	maiorAlgarismoNumero = somaNumero % 9;
		
	/* Caso Especial de Módulo por 9 do Número em questão resultar em 0. Significa que a soma dos algarismos darão 9.
	   Exemplos: 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99 [...] COM EXCEÇÃO DO ZERO.
	   
	   Embora divisível por 9, o Número 0 se trata de um Algarismo NULO e, assim sendo, NÃO tem Valor significativo.
	*/
		
	if ((maiorAlgarismoNumero == 0) && (somaNumero != 0))
	{
		maiorAlgarismoNumero = 9;
	}
	
	return maiorAlgarismoNumero;
}

int main ()
{
	char numero1[102], numero2[102];
	int maiorAlgarismoN1, maiorAlgarismoN2;
	
	scanf ("%s %s", numero1, numero2);
	
	while ((numero1[0] != '0') || (numero2[0] != '0'))
	{
		maiorAlgarismoN1 = verificar2Numeros (numero1);
		maiorAlgarismoN2 = verificar2Numeros (numero2);
		
		if (maiorAlgarismoN1 > maiorAlgarismoN2)
		{
			printf ("1");
		}
		else if (maiorAlgarismoN1 < maiorAlgarismoN2)
		{
			printf ("2");
		}
		else if (maiorAlgarismoN1 == maiorAlgarismoN2)
		{
			printf ("0");
		}
		
		printf ("\n");
		scanf ("%s %s", numero1, numero2);
	}
	
	return 0;
}
