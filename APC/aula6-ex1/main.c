#include <stdio.h>
#include <stdlib.h>

int main()
{   int x[10],i,r[10];
        printf("digite 10 numeros\n");
    for(i=0;i<10;i++){
        printf("digite um valor\n");
        scanf("%d",&x[i]);
        r[i]=x[i]%2;
    }

    printf("pares : ");
    for(i=0;i<10;i++){
        if(r[i]==0){
            printf("%d ",x[i]);
        }}
    printf("\n");

    printf("impares : ");
    for(i=0;i<10;i++){
        if(r[i]!=0){
            printf("%d ",x[i]);
    }}


    return 0;
}
