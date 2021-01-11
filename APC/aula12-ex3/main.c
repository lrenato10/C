#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char** s,c[20];
    int n,i,j;
    printf("digite o numero de strings\n");
    scanf("%d",&n);
    s=(char**) malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
        s[i]=(char*)malloc(20*sizeof(char));

    for(i=0;i<n;i++){
        setbuf(stdin,NULL);
        printf("digite um nome\n");
        fgets(s[i],20,stdin);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(s[i],s[j])>0){
                strcpy(c,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],c);
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%s",s[i]);

    for(i=0;i<n;i++)
        free (s[i]);
    free (s);
}

