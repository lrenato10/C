#include <stdio.h>
#include <stdlib.h>

struct atleta {
    char nome[20];
    char esporte[15];
    int idade;
    float peso;
    float altura;};
int main()
{   struct atleta b[5];
    int i, maiorh=0, velho=0,h,v ;
        for(i=0;i<5;i++){
            setbuf(stdin,NULL);
            printf("digite os dados do atleta:\n");
            printf("nome: ");
            setbuf(stdin,NULL);
            gets(b[i].nome);
            printf("esporte: ");
            setbuf(stdin,NULL);
            gets (b[i].esporte);
            printf("idade: ");
            setbuf(stdin,NULL);
            scanf("%d",&b[i].idade);
            printf("peso: ");
            setbuf(stdin,NULL);
            scanf("%f",&b[i].peso);
            printf("altura: ");
            setbuf(stdin,NULL);
            scanf("%f",&b[i].altura);
                if(b[i].altura>maiorh){
                    maiorh=b[i].altura;
                    h=i;
                }
                if(b[i].idade>velho){
                    velho=b[i].idade;
                    v=i;
                }
        }
    printf("o atleta mais alto eh o %s, e o mais velho o %s", b[h].nome,b[v].nome);
    return 0;
}


