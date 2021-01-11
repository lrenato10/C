#include <stdio.h>
#include <stdlib.h>

int main() {
int i, j, k = 5, n = 4;
int coef[5]={2,-3,1,0,2};
int x[5] = {1,3,5,7,9}, Px[5]={0};
for(i=1;i<=k;i++){
for(j=0;j<=n;j++) Px[i] += coef[j]*pow(x[i],j);
}
printf("%d %d %d %d %d %d", Px[0], Px[1], Px[2], Px[3], Px[4], Px[5]);
}
