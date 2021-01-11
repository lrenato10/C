#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c;
    float delta,r1,r2;
    printf("digite o A da equacao do segundo grau\n");
    scanf("%d",&a);
    printf("digite o B da equacao do segundo grau\n");
    scanf("%d",&b);
    printf("digite o C da equacao do segundo grau\n");
    scanf("%d",&c);

    delta=b*b-4*a*c;

   if(delta<0)
        printf("nao existe raiz\n");
   if(delta>0) {
      r1=(-b+sqrt(delta))/(2*a);
      r2=(-b-sqrt(delta))/(2*a);
      printf ("as raizes são %.2f,%.2f\n", r1,r2);
   }
   if(delta==0){
      r1=(-b)/(2*a);
      printf ("a raiz eh %.2f\n",r1);
   }

    return 0;
}
