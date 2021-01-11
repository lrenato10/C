#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   char s[40],k;
    int t,i;
    printf("digite uma string\n");
    setbuf(stdin,NULL);
    gets(s);
    t=strlen(s);
    for(i=0;i<t/2;i++){
        k=s[i];
        s[i]=s[t-i-1];
        s[t-i-1]=k;
    }

    fputs(s,stdout);



    return 0;
}

