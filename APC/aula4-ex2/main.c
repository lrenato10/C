#include <stdio.h>
#include <stdlib.h>

int main()
{   float H,P;
    char ch;
    printf("digite h para homem e m para mulher\n");
    ch=getchar();
    printf("digite de altura em metros da pessoa\n");
    scanf("%f",&H);

    if(ch=='h'){
        P=(72.7*H)-58;
        printf("peso ideal=%f",P);
    }
    if(ch=='m'){
        P=(62.1*H)-44,7;
        printf("peso ideal=%f", P);
    }
    return 0;
}

