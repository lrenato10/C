#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,j,A[2][3], B[2][3], C[2][3];
    printf("digite os valores da matriz A2x3 \n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("digite o valor de A[%d][%d]",i+1,j+1);
            scanf("%d",&A[i][j]);
    }}
    printf("digite os valores da matriz B2x3 \n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("digite o valor de B[%d][%d]",i+1,j+1);
            scanf("%d",&B[i][j]);
    }}
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            C[i][j]=A[i][j]+B[i][j];
            printf("C[%d][%d]=%d ",i,j,C[i][j]);
    }
        printf("\n");}
    return 0;
    }
