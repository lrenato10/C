#include <stdio.h>
#include <stdlib.h>

float vetor (float* v,int n);

int main()
{   int tamanho,i;
    printf("digite o tamanho do vetor\n");
    scanf("%d",&tamanho);
    float v[tamanho];
    for(i=0;i<tamanho;i++){
        printf("digite o valor de v[%d]",i+1);
        scanf("%f",&v[i]);
    }
    vetor(v,tamanho);
    printf("%f",vetor(v,tamanho));

    return 0;
}
float vetor (float* v,int n){
    int i;
    float c=0;
    for(i=0;i<n;i++){
        c=c+v[i];}
    c=c/n;
    return c;
}
