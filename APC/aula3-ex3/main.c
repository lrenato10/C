#include <stdio.h>
#include <stdlib.h>
int main() {
int x = 5, y = 10, z = 0;
if ( (x > 1) || (y / z == 1000) )
printf("Sucesso (divis�o por zero?)\n");/* o programa respondeu sucesso ao executar essa linha , pois a senten�a x>1 � verdadeira,
                                            embora n�o seja poss�vel fazer a divis�o por 0, mas como se trata de um caso de uni�o,
                                            a senten�a � verdadeira.*/

else
printf("Fracasso na divis�o por zero\n");
if ( (x > 1) && (y / z == 1000) )
printf("Sucesso (divis�o por zero?)\n");/*o programa n�o respondeu pois o programa n�o pode executar divis�es por 0,nesse caso as duas
                                            senten�as est�o ligadas por intersec��o, assim ambas precisam ser verdadeiras, o que n�o
                                            ocorre em virtude da divis�o por 0 ser imposs�vel de ser realizada */
else
printf("Fracasso na divis�o por zero\n");
return 0;
}

