#include <stdio.h>
#include <stdlib.h>

int main()
{   int x,d=0,r;
    printf("digite um numero\n");
    scanf("%d",&x);
    while(d<x){
        d=d+1;

        r=x%d;
        if(r==0)
            printf("%d ",d);
    }


    return 0;
}
