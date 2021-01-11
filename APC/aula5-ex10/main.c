#include <stdio.h>
#include <stdlib.h>

int main()
{   int x,d=1,r,s=0;
    printf("digite um numero\n");
    scanf("%d",&x);
    while (d<x)
    {
        r=x%d;

        if(r==0)
            s=s+d;

        d=d+1;
    }
    printf("a soma eh %d", s);

    return 0;
}
