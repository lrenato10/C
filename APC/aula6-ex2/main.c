#include <stdio.h>
#include <stdlib.h>

int main()
{   int n,m,i;
    printf("digite o tamanho do vetor\n");
    scanf(" %d",&n);
    int x[n];
    printf("digite um numero\n");
    scanf(" %d",&x[0]);
    m=x[0];
    for(i=1;i<n;i++){
        printf("digite um numero\n");
        scanf(" %d",&x[i]);

        if(x[i]>m)
            m=x[i];

    }
    printf("o maior valor eh %d",m);
    return 0;
}
