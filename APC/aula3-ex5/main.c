#include <stdio.h>
#include <stdlib.h>
int main(){
int i;
do {
printf("Escolha uma opcao:\n");
printf("(1) Op��o 1\n");
printf("(2) Op��o 2\n");
printf("(3) Op��o 3\n");
scanf("%d", &i);
} while ((i < 1) || (i > 3));
printf ("Voce escolheu a Opcao %d.\n",i);
system("pause");
return 0;
}
