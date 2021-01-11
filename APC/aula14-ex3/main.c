#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arq;

    arq=fopen("cemnumeros.bin","w+b");
    if(arq==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }

    int s=0,i,array[100];

    fwrite(array,sizeof(int),100,arq);
    fclose(arq);

    arq=fopen("cemnumeros.bin","r+b");
     if(arq==NULL){
        printf("ERRO\n");
        system("pause");
        exit(1);
    }
    fread(array,sizeof(int),100,arq);
    for(i;i<100;i++){
        s=array[i]+s;
    }
    printf("%d",&s);
    fclose(arq);
    return 0;
}
