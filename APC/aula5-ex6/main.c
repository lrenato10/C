#include <stdio.h>
#include <stdlib.h>

int main()
{   int x,y=1,n,maior,k;
    printf("digite quantos numeros voce pretender dar entrada\n");
    scanf("%d",&n);
    printf("digite um numero\n");
    scanf("%d",&k);
    maior=k;

    for(x=2;x<=n;x++){
        printf("digite um numero\n");
        scanf("%d",&k);
        if(k>maior){
            maior=k;
            y++;}
    }
    printf("o maior numnero eh %d, e o maior numero foi lido %d vezes",maior,y);
    return 0;

}
