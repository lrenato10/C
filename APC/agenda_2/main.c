#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void S(){
    setbuf(stdin,NULL);
    }
struct cadastro{
    char nome[20];
    char email[20];
    char cel[15];
    char fixo[15];
    //int status;
    };
    typedef struct cadastro pessoa;

void Inserir (FILE*arq){
    pessoa p;
    fseek(arq,0,SEEK_END);
    printf("digite nome:");
    S();
    gets(p.nome);
    printf("digite email:");
    S();
    gets(p.email);
    printf("digite telefone celular:");
    S();
    gets(p.cel);
    printf("digite telefone fixo:");
    S();
    gets(p.fixo);
    //p.status=1;
    fwrite(&p,sizeof(pessoa),1,arq);
    fflush(arq);
}
void Alterar (FILE*arq){
}
void Remover (FILE*arq){
    /*int n;
    printf("escolha o numero do registro\n");
    scanf("%d",&n);
    fseek(arq,n*sizeof(pessoa)+70,SEEK_SET);
    int status=0;
    fwrite(&status,sizeof(int),1,arq);
*/
}
void Buscar (FILE*arq){

}
void Listar (FILE*arq){
    pessoa p;
    int n=1;
    rewind(arq);
    while(!feof(arq)){
        fread(&p,sizeof(pessoa),1,arq);
        printf("Registro[%d]: %s  %s  %s  %s ",n,p.nome,p.email,p.cel,p.fixo);
        printf("\n");
        n++;
    }
}
int main()
{   FILE* arq;
    arq=fopen("agenda.txt","r+b");
    if(arq==NULL){
        arq=fopen("agenda.txt","w+b");
        if(arq==NULL){
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }

    }

    int opcao =-1,n;
    long int tamanho;
    char opc[10];
    while(opcao!=0){
        printf(" 0-sair\n 1-inserir\n 2-alterar\n 3-remover\n 4-buscar\n 5-listar\n");
        printf("NUM ou STR?\n");
        gets(opc);
        if(strcmp(opc,"NUM")==0 || strcmp(opc,"num")==0){
            scanf("%d",&opcao);
        }
        if(strcmp(opc,"STR")==0 || strcmp(opc,"str")==0){
            gets(opc);
            if(strcmp(opc,"sair")==0)
                opcao=0;
            if(strcmp(opc,"inserir")==0)
                opcao=1;
            if(strcmp(opc,"alterar")==0)
                opcao=2;
            if(strcmp(opc,"remover")==0)
                opcao=3;
            if(strcmp(opc,"buscar")==0)
                opcao=4;
            if(strcmp(opc,"listar")==0)
                opcao=5;
               }

        switch(opcao){
        case 1: Inserir(arq);break;
        case 2: Alterar(arq);break;
        case 3: Remover(arq);break;
        case 4: Buscar(arq);break;
        case 5: Listar(arq);break;
        }


        printf("\n\n");
    }
    fclose(arq);

    return 0;
}
