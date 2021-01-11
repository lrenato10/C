#include <stdio.h>
#include <stdlib.h>

int main()
{   int x,y;
    printf("digite um numero\n");
    scanf("%d", &x);
    y=x%2;

    if(y==0)
        printf("o numero eh par\n");
    else
        printf("o numero eh impar\n");
    system("pause");

    return 0;
}
