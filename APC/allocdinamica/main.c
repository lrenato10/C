#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p = (int *) malloc(20*sizeof(int));
    if(p==NULL){
        printf("muito grande\n");
        exit(1);}
    int i;
    for(i=0;i<20;i++){
        printf("digite o valor\n");
        scanf ("%d", &p[i]);


    }
    return 0;
}
