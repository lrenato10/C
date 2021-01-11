#include <stdio.h>
#include <stdlib.h>

int main()
{       char *s="palavra";
        char *s2 = s;
        while(*s2++);
        int x;
        x= s2-s-1;
        printf("s2 - s - 1=%d",x);
}

