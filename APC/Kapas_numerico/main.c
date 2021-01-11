#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double t, double teta, double v){
    return v;
}
double f2(double t, double teta, double v, double w, double u){
    return -w*w*sin(teta)-u*v;
}
int main()
{
    //=======================================================================//
    //DECLARACAO DE VARIAVEIS
    //=======================================================================//
    double teta=-9999;    //Angulo do pendulo com a normal
    double v=-9999;       //Velocidade angular do pendulo
    double g=9.8;   //Aceleracao da gravidade
    double l=0.8;   //Complirmento do pendulo
    double w=sqrt(g/l); //Constante
    double u=2*w-0.5;   //Constante
    double h;   //Passo do Runge-Kutta
    double t=0; //Tempo
    int i,j,k; //Contadores

    //=======================================================================//
    //LEITURA DOS DADOS
    //=======================================================================//
    while(teta<-270 || teta>270){
        printf(" Digite o valor do angulo inicial em graus que o pendulo faz com a normal\n Esse valor deve estar entre -270 e 270 graus\n");
        scanf("%lf",&teta);
    }
    while(v<-4 || v>4){
    printf(" Digite a velocidade angular inicial do pendulo\n Esse valor deve estar entra -4 e 4 \n");
    scanf("%lf",&v);
    }


    //=======================================================================//
    //LOOP PARA GERAR OS KAPAS
    //=======================================================================//
    double k11,k12,k21,k22,k31,k32,k41,k42;

    while (0){
    k11=h*f1(t,teta,v);
    k12=h*f2(t,teta,v,w,u);
    k21=h*f1(t+0.5*h,teta+0.5*k11,v+0.5*k12);
    k22=h*f2(t+0.5*h,teta+0.5*k11,v+0.5*k12,w,u);
    k31=h*f1(t+0.5*h,teta+0.5*k21,v+0.5*k22);
    k32=h*f2(t+0.5*h,teta+0.5*k21,v+0.5*k22,w,u);
    k41=h*f1(t+h,teta+k31,v+k32);
    k42=h*f2(t+h,teta+k31,v+k32,w,u);

    //leitura dos arquivos

    teta=teta+(k11+2*k21+2*k31+k41)/6;
    v=v+(k12+2*k22+2*k32+k42)/6;

    }


    return 0;
}
