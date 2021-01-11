#include <stdio.h>
#include <stdlib.h>

int main()
{   int x;
    printf("digite o numero de um mes\n");
    scanf("%d",&x);
    switch(x) {
        case 1:
            printf("janeiro\n");
            break;
        case 2:
            printf("fevereiro\n");
            break;
        case 3:
            printf("marco\n");
            break;
        case 4:
            printf("abril\n");
            break;
        case 5:
            printf("maio\n");
            break;
        case 6:
            printf("junho\n");
            break;
        case 7:
            printf("julho\n");
            break;
        case 8:
            printf("agosto\n");
            break;
        case 9:
            printf("setembro\n");
            break;
        case 10:
            printf("outubro\n");
            break;
        case 11:
            printf("novembro\n");
            break;
        case 12:
            printf("dezembro\n");
            break;
        default :
            printf("digite um numero de 1 a 12\n");


    }

        system("pause");
    return 0;
}

