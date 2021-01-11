#include <stdio.h>
#include <stdlib.h>

float maior(float x,float y){
    if (x>y)
        return x;
    else
        return y;
}
int main()
{
    float x,y;
    printf("digite dois numeros\n");
    scanf("%f %f",&x,&y);
    printf("o maior numero entre %f e %f eh o %f", x, y, maior(x,y));

}
