#include <stdio.h>
#include <stdlib.h>

int main()
{   int c;
    float k,f;
    printf("jogue uma temperatura entre -10 e 100 graus Celsius\n");

    for(;c>=-10 && c<=100;printf("%d celsius = %.2f kelvin = %.2f fahrenheit\n",c,k,f)){
        scanf("%d",&c);
        k=273.15+c;
        f=c*9/5+32;
        if(c<-10 || c>100)
            return 0;
    }


    return 0;
}
