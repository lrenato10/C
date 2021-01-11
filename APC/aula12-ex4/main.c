#include <stdio.h>
#include <stdlib.h>

int strlen (char *a);
void strcpy(char* a, char* b);
void strcat(char* a, char* b);
int main()
{   char str1[50],str2[50],str3[50];
    printf("digite a string 1\n");
    gets(str1);
    printf("digite a string 2\n");
    gets(str2);
    printf("digite a string 3\n");
    gets(str3);
    printf("strlen da string 1=%d\n",strlen(str1));
    strcpy(str1,str2);
    printf("copia da string 2 em 1=%s",str1);
    strcat(str2,str3);
    printf("concatenando a string 1 com a 2=%s",str2);

    return 0;
}
int strlen (char *a){
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
 void strcpy (char* a, char* b){
    int i;
    for(i=0;b[i]!='\0';i++){
        a[i]=b[i];
        }
    a[i]='\0';
 }
 void strcat(char* a, char* b){
    int i=0,j=0;
    for(i=0;a[i]!='\0';i++);
    while(b[j]!='\0'){
        a[i]=b[j];
        ++i;
        ++j;
    }
    a[i]='\0';


 }
