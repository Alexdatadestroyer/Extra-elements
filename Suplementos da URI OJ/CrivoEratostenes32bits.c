/* VERSÃO FINAL DO ALGORITMO PARA IR PRA NUVEM E PRO HD EXTERNO NO FUTURO
   ATUALIZADO EM 10 DE MARÇO DE 2019 (EXERCÍCIO FEITO ORIGINALMENTE EM 2017)
   ESSA VERSÃO IRÁ CORRIGIR O ERRO DA VERSÃO EM C DESTE MESMO ALGORITMO ENVIADA NAQUELA ÉPOCA EM 2017
   A IDEIA É ELIMINAR A NECESSIDADE DE SE UTILIZAR UPLOADS DE CÓDIGOS FONTES EM C++ COMO CORREÇÃO
   JÁ QUE SE PODE FAZER O UPLOAD NOVAMENTE DO CÓDIGO FONTE EM C, ENTÃO SERÁ ASSIM DE AGORA EM DIANTE
*/

#include <stdio.h>
#include <math.h>

int main ()
{
	int num, div, testes, cont;
	double bigNum, smallNum;
	
	scanf ("%d", &testes);
	
	while (testes > 0)
	{
		scanf ("%d", &num);
		
		if (num % 2 == 0)
		{
			(num == 2) ? printf ("Prime") : printf ("Not Prime");
		}
		else
		{
			if ((num == 3) || (num == 5) || (num == 7))
			{
				printf ("Prime");
			}
			else
			{
				div = 3;
				cont = 0;
				
				bigNum = sqrt(num) + 1;
				modf (bigNum, &smallNum);
				
				while (div <= smallNum)
				{
					if (num % div == 0)
					{
						cont = 1;
						break;
					}
					
					div += 2;
				}
				
				(!cont) ? printf ("Prime") : printf ("Not Prime");
			}
		}
		printf ("\n");
		testes--;
	}
	
	return 0;
}
