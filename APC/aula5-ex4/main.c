#include <stdio.h>
#include <stdlib.h>

int main()
{   int maior=0,menor=1000000000,n,s=0,x;
    float m;
        for(x=1;x<=10;x++){
            printf("digite um numero positivo\n");
            aqui:

            scanf("%d",&n);
            if(n<0)
                goto aqui;
            if(n>maior)
                maior=n;
            if(n<menor)
                menor=n;
            s=s+n;

        }
        m=s/10.0;
        printf("media:%.2f, maior:%d, menor:%d",m,maior,menor);




    return 0;
}
