#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   char s[20],S[20],k;
    int i,t;
    printf("digite um palavra\n");
    gets(s);
    t=strlen(s);
    for(i=0;i<t;i++){
        S[t-i-1]=s[i];
        if(strcmp(S,s)==0){
            i=t;
        }
        }
    S[i]='\0';

    if(strcmp(S,s)==0)
        printf("eh um palindromo\n");
    else
        printf("nao eh palindromo\n");

    return 0;
}
