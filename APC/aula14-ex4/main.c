#include <stdio.h>
#include <stdlib.h>

struct atleta {
    char nome[20];
    char esporte[10];
    int idade;
    float peso;
    float altura;
    };
int main(){
    struct atleta A[5];
    int i;
    for(i=0;i<5;i++){
        printf("digite o nome do atleta\n");
        setbuf(stdin,NULL);
        gets(A[i].nome);
        printf("digite o esporte\n");
        gets(A[i].esporte);
        printf ("digite a idade\n");
        scanf("%d",&A[i].idade);
        printf("digite o peso\n");
        scanf("%f",&A[i].peso);
        printf("digite a altura\n");
        scanf("%f",&A[i].altura);
    }
    FILE* arq;
    arq=fopen("arquivo.bin","w+b");
    fwrite(A,sizeof(struct atleta),5,arq);
    fclose(arq);
    arq=fopen("arquivo.bin","r+b");
    fseek(arq,2*sizeof(struct atleta),SEEK_SET);
    fread(&A[2].nome,sizeof(struct atleta),1,arq);
    printf(" %s\n %s\n %d\n %f\n %f\n", A[2].nome, A[2].esporte, A[2].idade, A[2].peso, A[2].altura);
    printf("modifique o nome do atleta 3\n");
    setbuf(stdin,NULL);
    gets(A[2].nome);
    fseek(arq,2*sizeof(struct atleta),SEEK_SET);
    fwrite(&A[2].nome,sizeof(char),20,arq);
    printf("modifique a idade do atleta 3\n");
    scanf("%d",&A[2].idade);
    fseek(arq,10*sizeof(char),SEEK_CUR);
    fwrite(&A[2].idade,sizeof(int),1,arq);
    rewind(arq);
    fread(&A[0].nome,sizeof(struct atleta),5,arq);
    for(i=0;i<5;i++){
        printf (" %s\n %s\n %d\n %f\n %f\n", A[i].nome, A[i].esporte, A[i].idade, A[i].peso, A[i].altura);
        printf("\n\n");
    }
    fclose(arq);
    system("pause");
    return 0;

}
