#include <stdio.h>
#include <stdlib.h>

void vetor(int* v,int n,int*maior,int*menor);

int main()
{
    int maior,menor,n,i;
    printf("digite o tamanho do vetor\n");
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
        printf("digite o valor de v[%d]\n",i+1);
        scanf("%d",&v[i]);}
    vetor(v,n,&maior,&menor);

    printf("maior=%d,menor=%d", maior,menor);
    return 0;
}
void vetor(int* v,int n,int*maior,int*menor){
    int i;
    *maior=v[0];
    *menor=v[0];
    for(i=0;i<n;i++){
        if(v[i]>*maior)
            *maior=v[i];
        if(v[i]<*menor)
            *menor=v[i];
    }

}
