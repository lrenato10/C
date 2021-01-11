#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a = 45, b = 18, mdc;
     while(a!=b) {
     if (a>b)
     a = a - b;
     else
     b = b - a;
     }
     mdc = a;


    printf("%d",mdc);
    return 0;
    }
