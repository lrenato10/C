#include <stdio.h>
#include <stdlib.h>

int crescente(int n, int c);
int decrescente(int n);

int main()
{   int N,C=0;
    printf("digite o valor de n\n");
    scanf("%d",&N);

    printf("\n crescente:");
    crescente (N,C);
    printf("\n descrescente:");
    decrescente (N);

    return 0;

}

int crescente(int n, int c){
    printf("%d ",c);
        if(c==n)
        return printf("%d ",c);
    return crescente (n,c+1);
}
int decrescente(int n){
    printf("%d ", n);
    if (n==0)
        return n;
    return decrescente(n-1);}


