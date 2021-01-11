#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   int n,i,j;
    char s[100];
    printf("digite o numero de posicoes que ira regir esse codigo de Cesar\n");
    scanf("%d",&n);
    setbuf(stdin,NULL);
    gets(s);
    for(i=0;s[i]!='\0';i++){
        for(j=0;j<n;j++){
            if(s[i]!=' '){
                if(s[i]>='a' && s[i]<'z')
                    s[i]=s[i]+1;
                else
                    s[i]=s[i]-'z'+'a';}
        }

    }

    fputs(s,stdout);
    return 0;
}
