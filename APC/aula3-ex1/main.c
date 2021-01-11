#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{   int A,B,C,D;
    printf("digite os dois catetos do triangulo\n");
    scanf("%d%d",A,B);
    C=A*A+B*B;
    D=sqrt(C);
    printf("a hipotenusa eh %d)\n,D");

    return 0;
}
