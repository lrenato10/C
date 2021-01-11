#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n==0)
        return n;
    if(n==1)
        return n;

    return n=fibonacci(n-1)+fibonacci(n-2);
    }
int main()
{   int i;
    for(i=0;i<100;i++){
        printf("\n termo %d: %d",i,fibonacci(i));
    }
    return 0;
}
