#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{   int A,B,C,D;
    printf("digite os dois catetos de valores inteiros do triangulo\n");
    scanf("%d%d",&A,&B);
    C=A*A+B*B;
    D=sqrt(C);
    printf("sqrt(%d)=%d que eh o valor da hipotenusa\n",C,D);
                                    /*como estamos trabalhando com vari�veis do tipo inteiro,
                                    o sistema arredendo a raizes que n�o s�o exatas para
                                    um valor inferior.*/
    float E,F,G,H;
    printf("digite os dois catetos do triangulo, de valores definidos nos numeros reais\n");
    scanf("%f%f",&E,&F);
    G=E*E+F*F;
    H=sqrt(G);
    printf("sqrt(%f)=%f que eh o valor da hipotenusa\n",G,H);
                                    /*como estamos trabalhando com variaveis do tipo reais,
                                    o sistema � capaz de realizar qualquer opera��o com
                                    precis�o simples, assim o arredondamento n�o � notado,
                                    exceto para escalas muito menores.*/

    return 0;
}
