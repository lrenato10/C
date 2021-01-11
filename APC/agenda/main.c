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
    char status;
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
    p.status='v';
    fwrite(&p,sizeof(pessoa),1,arq);
    fflush(arq);
}
void Alterar (FILE*arq){
    printf("digite o numero do registro\n");
    int n;
    scanf("%d",&n);
    pessoa p;
    fseek(arq,(n-1)*sizeof(pessoa),SEEK_SET);
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
    p.status='v';
    fwrite(&p,sizeof(pessoa),1,arq);
    fflush(arq);
}
void Remover (FILE*arq){
    int n;
    pessoa p;
    printf("escolha o numero do registro\n");
    scanf("%d",&n);
    fseek(arq,(n-1)*sizeof(pessoa)+70,SEEK_SET);
    int status='f';
    fwrite(&status,sizeof(int),1,arq);
    fseek(arq,-sizeof(pessoa),SEEK_CUR);
    fread(&p,sizeof(pessoa),1,arq);
    printf("Registro[%d]: %s %s %s %s REMOVIDO COM SUCESSO", n, p.nome, p.email,p.cel, p.fixo);
}
void Buscar (FILE*arq){
    char aux[71];
    char busc[15];
    char* p;
    int  n=0,c=0;
    pessoa ps;
    rewind(arq);
    printf("digite uma palavra chave de busca\n");
    S();
    gets(busc);
    while(2){
        fread(aux,sizeof(char),71,arq);
        p=strstr(aux,busc);
        c++;
        if(feof(arq))
            break;
        if(p!=NULL){
            n++;
            fseek(arq,-sizeof(pessoa),SEEK_CUR);
            fread(&ps,sizeof(pessoa),1,arq);
            if(ps.status=='v')
                printf("Registro[%d]: %s %s %s %s\n",c, ps.nome, ps.email, ps.cel, ps.fixo);
            if(ps.status=='f')
                printf("Registro[%d]: Removido");
        }

    }
    if(n==0){
        printf("nao foi possivel encontrar\n");
    }


}
void Listar (FILE*arq){
    pessoa p;
    int n=1;
    rewind(arq);
    while(2){
        fread(&p,sizeof(pessoa),1,arq);
        if(feof(arq))
            break;
        if(p.status=='v')
            printf("Registro[%d]: %s %s %s %s",n,p.nome,p.email,p.cel,p.fixo);
        printf("\n");
        if(p.status=='f')
            printf("Registro[%d]: Removido\n",n);
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
        S();
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
