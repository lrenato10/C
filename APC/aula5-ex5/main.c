#include <stdio.h>
#include <stdlib.h>

int main()
{   int x=0,y=1,n,k=3,s;
    printf("digite a posicao do enesimo termo da sequencia de fibonacci\n");
    scanf("%d",&n);
    while (n>=k){
        s=x+y;
        x=y;
        y=s;
        k++;


    }

    if(n==1)
        s=0;

    if(n==2)
        s=1;
    printf("%d",s);

    return 0;
}
