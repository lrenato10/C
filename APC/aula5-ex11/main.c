#include <stdio.h>
#include <stdlib.h>

int main()
{   int K=0,t=0,c=0,k=0,C=0 ,T=0,S=0;
    printf("soma dos numeros naturais menores que 1000 que sao multiplos de 3 ou 5 = ");
    while (c<1000){
        c=c+5;
        C=C+c;
            if(c==995)
                break;}
    while (t<1000){
        t=t+3;
        T=T+t;
            if(t==999)
                break;}
    while (k<1000){
        k=k+15;
        K=K+k;
            if(k==990)
                break;

    }
        S=C+T-K;

    printf("%d",S);
    return 0;
}



