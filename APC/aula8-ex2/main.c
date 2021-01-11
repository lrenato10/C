

#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,j,x,y;

    printf("digiteo numero de linhas da matriz\n");
    scanf("%d",&x);
    printf("digiteo numero de colunas da matriz\n");
    scanf("%d",&y);
    printf("digite os valores da matriz Aixj\n");
    int A[x][y],V[y],R[x],r;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("digite o valor de A[%d][%d]",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<y;i++){
        printf("digite os valor de vetor V[%d]",i+1);
        scanf("%d",&V[i]);
    }

    for(i=0;i<x;i++){
        r=0;
        for(j=0;j<y;j++){
            r=r+(A[i][j]*V[j]);
        }
        R[i]=r;
    }
    for(i=0;i<x;i++)
    {
        printf("R[%d]=%d   ",i+1,R[i]);
    }
    system("pause");
    return 0;
}
