/* Set this on a command on Nightbot and give a 32-bit number (0 to 2³¹-1) and you will know if the number is Prime or not */ 

$(eval var p = 1; d = 3; var i; var n = Math.floor(Math.sqrt($(1))) + 1; if ($(1) == null) 'Digite um Número entre 1 e 2147483647'; else if ($(1) > 2147483647 || $(1) <= 0 ) 'Número digitado fora do intervalo permitido!'; else if ($(1) == 1) 'Número 1 possui apenas ELE como divisor!'; else {if ($(1) % 2 == 0 && $(1) != 2) $(1) + ' não é primo'; else {while (d <= n) {if ($(1) % d == 0) {p = 0; break;} else {d += 2;}} if (p == 1) $(1) + ' é PRIMO!'; else $(1) + ' não é primo';}})

/* Beautificado (Melhorado e identado). Agora é legível da seguinte forma: */

$(eval
    var p = 1; d = 3;
    var i;
    var n = Math.floor(Math.sqrt($(1))) + 1;
    if ($(1) == null) 'Digite um Número entre 1 e 2147483647';
    else if ($(1) > 2147483647 || $(1) <= 0) 'Número digitado fora do intervalo permitido!';
    else if ($(1) == 1) 'Número 1 possui apenas ELE como divisor!';
    else
    {
        if ($(1) % 2 == 0 && $(1) != 2) $(1) + ' não é primo';
        else
        {
            while (d <= n)
            {
                if ($(1) % d == 0)
                {
                    p = 0;
                    break;
                } 
                else
                {
                    d += 2;
                }
            }
            if (p == 1) $(1) + ' é PRIMO!';
            else $(1) + ' não é primo';
        }
	  }
)
