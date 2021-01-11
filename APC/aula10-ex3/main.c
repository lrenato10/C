#include <stdio.h>
#include <stdlib.h>

 int fatorial(int x){
        int f=1,i;
        for(i=2;i<=x;i++)
            f=f*i;
        return f;
        }

int combinacao (int n,int s){
    int c;
    c=(fatorial(n))/(fatorial(s)*fatorial(n-s));
    return c;}
int main()
{   int n,s;
    do { printf("digite o numero de elementos e o numero de elementos de cada grupo da combinacao");
        scanf("%d %d", &n,&s);}
    while (n<s || n<0);
    printf("o numero de combinacoes possiveis eh %d",combinacao(n,s));

    return 0;
}
