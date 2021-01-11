#include <stdio.h>
#include <stdlib.h>
const int max=30;
void transposta (int M[max][max],int T[max][max],int c, int w);

int main()
{
    int x,y,i,j,m[max][max],t[max][max];
    printf("digite a primeira dimensao da matriz\n");
    scanf("%d",&x);
    printf("digite a segunda dimensao da matriz\n");
    scanf("%d",&y);
    if(x<=max && y<=max){
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("digite o valor de m[%d][%d]",i+1,j+1);
                scanf("%d",&m[i][j]);
            }
        }

        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("%d ",m[i][j]);
            }
            printf("\n");
        }
        transposta(m,t,x,y);
        for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                printf("%d ",t[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("a matriz eh maior que o limite %dx%d",max,max);

    return 0;

}
void transposta (int M[max][max],int T[max][max],int c, int w){
    int i,j;
    for(i=0;i<c;i++){
        for(j=0;j<w;j++){
        T[j][i]=M[i][j];

    }
}
}
