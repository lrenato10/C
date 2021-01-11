#include <stdio.h>
#include <stdlib.h>
int main() {
int x = 5, y = 10, z = 0;
if ( (x > 1) || (y / z == 1000) )
printf("Sucesso (divisão por zero?)\n");/* o programa respondeu sucesso ao executar essa linha , pois a sentença x>1 é verdadeira,
                                            embora não seja possível fazer a divisão por 0, mas como se trata de um caso de união,
                                            a sentença é verdadeira.*/

else
printf("Fracasso na divisão por zero\n");
if ( (x > 1) && (y / z == 1000) )
printf("Sucesso (divisão por zero?)\n");/*o programa não respondeu pois o programa não pode executar divisões por 0,nesse caso as duas
                                            sentenças estão ligadas por intersecção, assim ambas precisam ser verdadeiras, o que não
                                            ocorre em virtude da divisão por 0 ser impossível de ser realizada */
else
printf("Fracasso na divisão por zero\n");
return 0;
}

