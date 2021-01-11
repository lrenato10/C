#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char nome[100],palavra[20];
    printf("digite o nome de um arquivo\n");
    gets(nome);
    int n=0;
    FILE* arq;
    arq=fopen(nome,"r");

    if(arq==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }

    printf("digite a palavra\n");
    scanf("%s",palavra);
    char teste[30];
    while (!feof(arq)){
        fgets(teste,30,arq);
        strstr(teste,palavra);
        if(strstr(teste,palavra)!=NULL)
            n=n+1;
    }
    printf("a palavra %s apareceu %d vezes", palavra,n);
    fclose(arq);
    return 0;
}
