#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    printf("digite 4 numeos aleatoris que serao ordenados\n");
    scanf("%d %d %d %d", &a,&b,&c,&d);
    for (a,b,c,d;;scanf("%d %d %d %d",&a,&b,&c,&d)){

    if((a<=b) && (b<=c) && (c<=d))
        printf("Em ordem:%d, %d, %d, %d \n", a,b,c,d);
    if((a<=c) && (c<=b) && (b<=d))
        printf("Em ordem:%d, %d, %d, %d \n", a,c,b,d);
    if((a<=b) && (b<=d) && (d<=c))
        printf("Em ordem:%d, %d, %d, %d \n", a,b,d,c);
    if((a<=c) && (c<=d) && (d<=b))
        printf("Em ordem:%d, %d, %d, %d \n", a,c,d,b);
    if((a<=d) && (d<=b) && (b<=c))
        printf("Em ordem:%d, %d, %d, %d \n", a,d,b,c);
    if((a<=d) && (d<=c) && (c<=b))
        printf("Em ordem:%d, %d, %d, %d \n", a,d,c,b);
    if((b<=a) && (a<=c) && (c<=d))
        printf("Em ordem:%d, %d, %d, %d \n", b,a,c,d);
    if((b<=a) && (a<=d) && (d<=c))
        printf("Em ordem:%d, %d, %d, %d \n", b,a,d,c);
    if((b<=c) && (c<=a) && (a<=d))
        printf("Em ordem:%d, %d, %d, %d \n", b,c,a,d);
    if((b<=c) && (c<=d) && (d<=a))
        printf("Em ordem:%d, %d, %d, %d \n", b,c,d,a);
    if((b<=d) && (d<=a) && (a<=c))
        printf("Em ordem:%d, %d, %d, %d \n", b,d,a,c);
    if((b<=d) && (d<=c) && (c<=a))
        printf("Em ordem:%d, %d, %d, %d \n", b,d,c,a);
    if((c<=b) && (b<=a) && (a<=d))
        printf("Em ordem:%d, %d, %d, %d \n", c,b,a,d);
    if((c<=b) && (b<=d) && (d<=a))
        printf("Em ordem:%d, %d, %d, %d \n", c,b,d,a);
    if((c<=a) && (a<=b) && (b<=d))
        printf("Em ordem:%d, %d, %d, %d \n", c,a,b,d);
    if((c<=a) && (a<=d) && (d<=b))
        printf("Em ordem:%d, %d, %d, %d \n", c,a,d,b);
    if((c<=d) && (d<=a) && (a<=b))
        printf("Em ordem:%d, %d, %d, %d \n", c,d,a,b);
    if((c<=d) && (d<=b) && (b<=a))
        printf("Em ordem:%d, %d, %d, %d \n", c,d,b,a);
    if((d<=b) && (b<=c) && (c<=a))
        printf("Em ordem:%d, %d, %d, %d \n", d,b,c,a);
    if((d<=b) && (b<=a) && (a<=c))
        printf("Em ordem:%d, %d, %d, %d \n", d,b,a,c);
    if((d<=a) && (a<=b) && (b<=c))
        printf("Em ordem:%d, %d, %d, %d \n", d,a,b,c);
    if((d<=a) && (a<=c) && (c<=b))
        printf("Em ordem:%d, %d, %d, %d \n", d,a,c,b);
    if((d<=c) && (c<=a) && (a<=b))
        printf("Em ordem:%d, %d, %d, %d \n", d,c,a,b);
    if((d<=c) && (c<=b) && (b<=a))
        printf("Em ordem:%d, %d, %d, %d \n", d,c,b,a);
    }

return 0;
}
