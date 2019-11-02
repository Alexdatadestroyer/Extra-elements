#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char *quantDiscos, *expoenteReduzidoChar;
	int i, j, k, x;
	int expoenteReduzidoIntPuro, *expoenteReduzidoIntArray, backupExpReduzIntPuro, valorFinal;
	int horas, minutos, segundos;
	
	quantDiscos = (char *) calloc (42, sizeof (char));
	
	scanf ("%s", quantDiscos);
			
	/* Conversão de Decimal pra Decimal de uma String por meio de um padrão em específico: Número MOD 86400 (24 horas)
		   
	   Este padrão (Número MOD 86400) possui a função de delimitar a futura procura de expoentes superiores a 86400.
		   
	   Assim, seria feita a procura de forma mais rápida por um expoente grande. Exemplo:
	   
	   --> [3000000000 mod 86400 = 19200] onde [2 ^ 3000000000 mod 86400] se torna equivalente a [2 ^ 19200 mod 86400].
	   
	   Assim, conclui-se que o resultado por um seria o MESMO do outro, sem a necessidade de realizar exponenciação
	   de um número tão grande!
		   
	   A linha marcada como "expoenteReduzidoIntPuro %= 86400" (expoenteReduzidoIntPuro = expoenteReduzidoIntPuro % 86400)
	   trata exatamente disso!
	   
	*/
	
	/* Informação dos Arrays utilizados na Operação de Redução do Expoente gigante:
	
	   a) expoenteReduzidoChar: Armazenará o valor do expoente dígito a dígito em formato String. A ideia é ir pegando
	                            dígito a dígito e ir verificando se o valor formado ultrapassa ou não 86400 (24 horas).
	
	   b) expoenteReduzidoIntPuro: É o valor formado na String "expoenteReduzidoChar" para verificação se ultrapassou 86400 ou não.
				       Caso positivo, o valor é delimitado (MOD 86400) e depois será retransferido para a String para
				       uma nova iteração de inserção de mais dígitos um a um.
	   
	   c) expoenteReduzidoIntArray: É o Vetor que irá hospedar o valor de "expoenteReduzidoIntPuro" da String "expoenteReduzidoChar"
					em formato de dígitos um a um. É daqui onde os dígitos serão repassados para uma nova String um
					a um após a destruição da antiga [free (expoenteReduzidoChar)], recriando o "expoenteReduzidoChar"
					a ser válido para a próxima iteração até o final da String de Entrada inserida.
									
					Sempre que o valor "expoenteReduzidoIntPuro" precisar de transformação, este Array será criado e
					destruído após cada iteração do FOR do I.
	*/
	
	expoenteReduzidoIntPuro = 0;
	expoenteReduzidoChar = (char *) calloc (42, sizeof (char));
	k = 0;
	
	/* PRIMEIRA FASE DO PROBLEMA: Encurtar o valor enorme do expoente da base 2 via MOD 86400.
				      É A FASE MAIS DIFÍCIL DE TODO O ALGORITMO!
	*/
	
	for (i = 0; quantDiscos[i] != '\0'; i++)
	{
		expoenteReduzidoChar[k] = quantDiscos[i];
		expoenteReduzidoChar[k+1] = '\0';			// Caractere finalizador para validação e reconhecimento em Strings.
		
		expoenteReduzidoIntPuro = atoi (expoenteReduzidoChar);
		
		if (expoenteReduzidoIntPuro >= 86400)
        	{
          		expoenteReduzidoIntPuro %= 86400;
            
         		backupExpReduzIntPuro = expoenteReduzidoIntPuro;
            
          		expoenteReduzidoIntArray = (int *) calloc (42, sizeof (int));
            
            		for (j = 0, x = 41; backupExpReduzIntPuro != 0; j++, x--)
			{
			        expoenteReduzidoIntArray[x] = backupExpReduzIntPuro % 10;
		        	backupExpReduzIntPuro /= 10;
		       	}
            
            		x++;
            
           		free (expoenteReduzidoChar);			// Destroi-se o Array de Char antigo para se criar um novo...
            
            		expoenteReduzidoChar = (char *) calloc (42, sizeof (char));
            
            		for (j = 0; x < 42; j++, x++)
		       	{
			       	expoenteReduzidoChar[j] = (char) (expoenteReduzidoIntArray[x] + 48);
		      	}
			
			expoenteReduzidoChar[j] = '\0';			// Caractere finalizador para validação e reconhecimento em Strings.
		       	k = j;
			free (expoenteReduzidoIntArray);
        	}
        	else
        	{
        		k++;
       		}
    	}
    
    	free (expoenteReduzidoChar);		// Não precisaremos mais do Array de Char criado...
    
    	/* SEGUNDA FASE DO PROBLEMA: Como elevar diretamente se torna impossível por gerar um número ainda grande, a ideia
    				     é ir multiplicando 2 por 2... até o valor do expoente reduzido obtido e, já, realizando
    				     a delimitação da variável "valorFinal" por 86400 novamente porque, qualquer número acima
    				     disso, seria um loop no relógio diário de 24 horas (86400 segundos).
    	*/
    
    	valorFinal = 1;
    
    	for (i = 0; i < expoenteReduzidoIntPuro; i++)
    	{
    		valorFinal *= 2;
    	
    		if (valorFinal >= 86400)
    		{
    			valorFinal %= 86400;
    		}
   	}
    
    	/* TERCEIRA FASE DO PROBLEMA: Transformação para Horas, Minutos e Segundos.
    				      (Segundos-1) devido à regra da Torre de Hanoi ser [(2^N) - 1].
   	*/
    
    	horas = (valorFinal / 3600);
    	minutos = (valorFinal % 3600 / 60);
    	segundos = (valorFinal % 3600 % 60) - 1;
    
    	if (horas == 24)
    	{
    		horas = 0;
    	}
    
    	/* QUARTA FASE DO PROBLEMA: Esquema de exibição dos 3 valores até com o "0" à esquerda (0 a 9) se necessário! */
    
    	((horas >= 0) && (horas <= 9)) ? printf ("0%d:", horas) : printf ("%d:", horas);
    
   	((minutos >= 0) && (minutos <= 9)) ? printf ("0%d:", minutos) : printf ("%d:", minutos);
    
    	((segundos >= 0) && (segundos <= 9)) ? printf ("0%d\n", segundos) : printf ("%d\n", segundos);
    
  	free (quantDiscos);				// Destruição da String de Entrada. Fim do algoritmo.
	
	return 0;
}
