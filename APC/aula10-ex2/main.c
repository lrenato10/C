#include <stdio.h>
#include <stdlib.h>

void volume(float h, float r){
    float v;
    v = 3.141592*r*r*h;
    printf("o volume do cilindro eh %f",v);}
int main()
{   float h,r;
    printf("digite a altura e o raio do cilindro\n");
    scanf("%f %f",&h,&r);
    volume(h,r);
    return 0;
}
