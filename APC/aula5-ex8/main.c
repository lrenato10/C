#include <stdio.h>
#include <stdlib.h>

int main()
{   int n=0,l,x,y;
    printf("digite o numero de linhas do triangulo de floyd\n");
    scanf("%d",&l);
    for(x=1;x<=l;x++){
        for(y=1;y<=x;y++){
            n=n+1;
            printf("%d ",n);
        }


        printf("\n");
    }





    return 0;
}
