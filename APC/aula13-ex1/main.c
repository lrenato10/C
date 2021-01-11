#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[20];
    int idade;
    char endereco[40];
};
int main()
{
    struct pessoa A;
    struct pessoa *B=(struct pessoa*)malloc(sizeof(struct pessoa));
    printf("digite o nome\n");
    gets(A.nome);
    printf("digite a idade\n");
    scanf("%d",&A.idade);
    setbuf(stdin,NULL);
    printf("digite o endereco\n");
    gets(A.endereco);
    printf (" nome:%s\n idade:%d\n endereco:%s\n", A.nome, A.idade, A.endereco);

    printf("digite o nome\n");
    gets(B->nome);
    printf("digite a idade\n");
    scanf("%d",&B->idade);
    setbuf(stdin,NULL);
    printf("digite o endereco\n");
    gets(B->endereco);
    printf (" nome:%s\n idade:%d\n endereco:%s\n", B->nome, B->idade, B->endereco);

    free(B);
    return 0;


}
