#include <stdio.h>
#include <stdlib.h>

struct atleta {
    char nome[20];
    char esporte[15];
    int idade;
    float peso;
    float altura;};

void func (struct atleta c , struct atleta* d){
    *d=c;
    }
int main()
{

    struct atleta a;
    struct atleta b;
            setbuf(stdin,NULL);
            printf("digite os dados do atleta:\n");
            printf("nome: ");
            setbuf(stdin,NULL);
            gets(a.nome);
            printf("esporte: ");
            setbuf(stdin,NULL);
            gets (a.esporte);
            printf("idade: ");
            setbuf(stdin,NULL);
            scanf("%d",&a.idade);
            printf("peso: ");
            setbuf(stdin,NULL);
            scanf("%f",&a.peso);
            printf("altura: ");
            setbuf(stdin,NULL);
            scanf("%f",&a.altura);

            setbuf(stdin,NULL);
            printf("digite os dados do atleta:\n");
            printf("nome: ");
            setbuf(stdin,NULL);
            gets(b.nome);
            printf("esporte: ");
            setbuf(stdin,NULL);
            gets (b.esporte);
            printf("idade: ");
            setbuf(stdin,NULL);
            scanf("%d",&b.idade);
            printf("peso: ");
            setbuf(stdin,NULL);
            scanf("%f",&b.peso);
            printf("altura: ");
            setbuf(stdin,NULL);
            scanf("%f",&b.altura);

    func(a,&b);
    printf( "Atleta A: %s,%s,%d,%f,%f. \n Atleta B: %s,%s,%d,%f,%f", a.nome,a.esporte,a.idade,a.peso,a.altura,b.nome,b.esporte,b.idade,b.peso,b.altura);
    return 0;
}

