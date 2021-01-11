#include <stdio.h>
#include <stdlib.h>

int main()
{   int x;
    printf("digite o numero do dia da semana\n");
    scanf("%d",&x);
    switch(x) {
        case 1:
            printf("domingo\n");
            break;
        case 2:
            printf("segunda\n");
            break;
        case 3:
            printf("terca\n");
            break;
        case 4:
            printf("quarta\n");
            break;
        case 5:
            printf("quinta\n");
            break;
        case 6:
            printf("sexta\n");
            break;
        case 7:
            printf("sabado\n");
            break;

        default :
            printf("numero deve ser entre 1 e 7\n");


    }

        system("pause");
    return 0;
}
