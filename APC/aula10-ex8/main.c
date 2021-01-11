#include <stdio.h>
#include <stdlib.h>

int cubo(int n){
    if (n==1)
        return 1;
    return pow (n,3)+cubo(n-1);

    }


int main()
{   int a;
    printf("digite o valor do numero de termos da soma de cubos\n");
    scanf("%d",&a);
    printf("%d",cubo(a));
    return 0;
}
