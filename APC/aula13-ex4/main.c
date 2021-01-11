#include <stdio.h>
#include <stdlib.h>
    struct ponto{
        int x;
        int y;
        };
    struct retangulo{
        struct ponto p1;
        struct ponto p2;
        };
int main()
{   struct retangulo r;
    int area, perimetro,diagonal;
    printf("digite as coordendas do retangulo\n");
    printf("digite a coordenada X do ponto superior esquerdo");
    scanf("%d",&r.p1.x);
    printf("digite a coordenada Y do ponto superior esquerdo");
    scanf("%d",&r.p1.y);
    printf("digite a coordenada X do ponto inferior direito");
    scanf("%d",&r.p2.x);
    printf("digite a coordenada X do ponto inferior direito");
    scanf("%d",&r.p2.y);

    area=(r.p2.x-r.p1.x)*(r.p1.y-r.p2.y);
    perimetro=2*(r.p2.x-r.p1.x)+2*(r.p1.y-r.p2.y);
    diagonal=sqrt((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x)+(r.p1.y-r.p2.y)*(r.p1.y-r.p2.y));
    printf("area = %d, perimetro = %d, diagonal = %d",area,perimetro,diagonal);
    return 0;
}
