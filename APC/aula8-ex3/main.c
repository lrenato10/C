#include <stdio.h>
#include <stdlib.h>

int main()
{   int M[5][4],i,j;
    printf("digite os valores de uma matriz M5X4\n");
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("digite o valor de M[%d][%d]",i+1,j+1);
            scanf("%d",&M[i][j]);}}
    printf("digite o valor do numero da linha da matriz o qual se deseja saber o valor\n");
    scanf("%d",&i);
    i=i-1;
    for(j=0;j<4;j++)
        printf("%d ",M[i][j]);
    return 0;
}

