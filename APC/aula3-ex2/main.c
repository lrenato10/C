#include <stdio.h>
#include <stdlib.h>

int main()
{
    float C1,C2,F,K;
    printf("jogue a temperatura em graus celsius que sera convertida em fahrenheit\n");
    scanf("%f",&C1);
    F=C1*9/5+32;
    printf("a temperatura em fahrenheit eh %.2f\n",F);

    printf("jogue a temperatura em grau celsius que sera convertida em kelvin\n");
    scanf("%f",&C2);
    K=C2+273.15;
    printf("a temperatura em kelvin eh %.2f\n",K);

    return 0;
}

