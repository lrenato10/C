#include <stdio.h>
#include <stdlib.h>

int main()
{   char x,y;
    float n;
    printf("Responda com \"s\" ou \"n\" ou \"numero com/sem ponto\"\n");
    printf("Hoje eh um dia especial para voce?\n");
    x=getchar();
    while(x!='s'){
        setbuf(stdin,NULL);
        printf("Nao esperava essa resposta\n");
        printf("Hoje eh um dia especial para voce?\n");
        x=getchar();
    }


    printf("Fazemos quantos anos hoje?\n");
    scanf("%f",&n);
    while(n!=1.5){
        if(n>1.5){
            printf("Tem menos tempo que %.1f\n",n);
            printf("Fazemos quantos anos hoje?\n");
            scanf("%f",&n);}
        if(n<1.5){
            printf("Tem mais tempo que %.1f\n",n);
            printf("Fazemos quantos anos hoje?\n");
            scanf("%f",&n);}
    }
    printf("Isso mesmo mor =)\n");


    printf("De uma nota de 0 a 10, como nos estamos?\n");
	scanf("%d",&x);
	if(x<=3)
		printf("Vish,nao estamos bem   =(");
	if(x>3 && x<=7)
		printf("Precisamos melhorar  :|");
	if(x>7)
		printf("Eba, estamos muito bem   =)");
	printf("\n");

    printf("Voce me ama  muito?\n");
    setbuf(stdin,NULL);
    y=getchar();

    while(y!='s'){
        setbuf(stdin,NULL);
        printf("Poxa mor\n");
        y=getchar();
    }
    printf("Tambem te amo muito\n");
    printf("Feliz 1.5 anos, uma vez que voce entrou na minha vida, nunca mais quero que saia <3\n");
    system("pause");

    return 0;
}
