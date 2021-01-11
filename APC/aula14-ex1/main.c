#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arq1;
    FILE* arq2;
    FILE* arq3;

    arq1=fopen("texto1.txt","r");
     if(arq1==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }
    arq2=fopen("texto2.txt","r");
     if(arq2==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }
    arq3=fopen("texto3.txt","w+");
     if(arq3==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }

    char s[100];
    fgets(s,100,arq1);
    fputs(s,arq3);

    fgets(s,100,arq2);
    fputs(s,arq3);

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    return 0;
}
