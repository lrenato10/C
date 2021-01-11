#include <stdio.h>
#include <stdlib.h>

int main()
{   int x=1, y=1;
    float s=0,v;
    printf("o valor de 1/1+3/2+5/3+7/4+9/5+...+99/50 = ");
    while(x<=99 && y<=50){
        v=x/(float)y;
        x=x+2;
        y=y+1;
        s=s+v;}
    printf("%f",s);
    return 0;
}
