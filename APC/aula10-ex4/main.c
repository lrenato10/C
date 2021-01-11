#include <stdio.h>
#include <stdlib.h>

void funcao(float n, int* k, float* w){
    *k=(int)n;
    *w=n-(int)n;
    }

int main()
{   float n,R;
    int I;
    printf("digite um numero\n");
    scanf("%f",&n);
    funcao(n,&I,&R);
    printf("parte inteira %d, parte imaginaria %f",I,R);
    return 0;
}
