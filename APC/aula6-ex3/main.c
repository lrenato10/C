#include <stdio.h>
#include <stdlib.h>

int main()
{   int A[20],B[20],i;

    for (i=0;i<20;i++){
        printf("digite um numero do vetor A\n");
        scanf(" %d",&A[i]);
    }
    for (i=0;i<20;i++)
        B[19-i]=A[i];

    printf("vetor A: ");
    for (i=0;i<20;i++)
        printf("%d, ",A[i]);

    printf("vetor B: ");
    for (i=0;i<20;i++)
        printf("%d, ",B[i]);



    return 0;
}
