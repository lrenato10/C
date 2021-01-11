#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define g  9.81                                     //Aceleracao da gravidade [m/s^2]
#define l 0.80                                     //Comprimento do pendulo [m]
#define w  3.50178525897862560                      //w=sqrt(g/l)
double u = 6.50357051795725121 ;                     //u=2*w-0.5

double absoluto(double x){
    return sqrt(x*x);
}


double h1(double t, double x1, double x2, double x3, double x4){     //f1 é a gerada a partir da derivada de x1
    return -2.0*x1-x2-x3-2.0*x4;
}
double h2(double t, double x1, double x2, double x3, double x4){     //f1 é a gerada a partir da derivada de x2
    return x1-2.0*x2+2.0*x3-x4;
}
double h3(double t, double x1, double x2, double x3, double x4){     //f1 é a gerada a partir da derivada de x3
    return -x1-2.0*x2-2.0*x3-x4;
}
double h4(double t, double x1, double x2, double x3, double x4){     //f1 é a gerada a partir da derivada de x4
    return 2.0*x1-x1+x3-2.0*x4;
}
double h1e(double t){
    return exp(-t)*sin(t)+exp(-3.0*t)*cos(3.0*t);
}
double h2e(double t){
    return exp(-t)*cos(t)+exp(-3.0*t)*sin(3.0*t);
}
double h3e(double t){
    return -exp(-t)*sin(t)+exp(-3.0*t)*cos(3.0*t);
}
double h4e(double t){
    return -exp(-t)*cos(t)+exp(-3.0*t)*sin(3.0*t);
}





double g1_tst4(double t, double v, double z){                                  //E.D.O do teste1
    return z;
}

double g2_tst4(double t, double v, double z){
    return (-40.0*z - 400.0*v);
}

double tst4e(double t){                                  //Solução analítica da E.D.O do teste1
    return ( -12.0*exp(-20.0*t) - 240*t*exp(-20.0*t) );
}



double tst2(double t, double x){                                  //E.D.O do teste1
    return -1.0*sqrt(1.0-(x*x));
}

double tst2e(double t){                                  //Solução analítica da E.D.O do teste1
    return cos(t);
}



double tst1(double t, double x){                                  //E.D.O do teste1
    return t-x;
}

double tst1e(double t){                                  //Solução analítica da E.D.O do teste1
    return t-1.0+2.0*exp( 1.0 - t );
}


double f1(double t, double teta, double v){     //f1 é a gerada a partir de  da sustituição de v = dteta/dt
    return v;
}



double f2(double t, double teta, double v){     //f2 é a equação diferncial de ordem reduzida e duas varaiveis
    return -w*w*sin(teta)-u*v;
}












int main()
{


    char teste1, teste2, teste3, teste4, teste5;
    int menu;


    printf("O que deseja?\n0-Resolver E.D.O do exercicio\n1-Teste1\n2-Teste2\n3-Teste3\n4- Teste extra\n5-Teste de energia para o caso não amortecido\n\n-?-EXIT\n");
    scanf("%d",&menu);
    switch(menu)
        {
            case(0):teste1=0; teste2=0; teste3=0 ;teste4=0 ; teste5=0;break;
            case(1):teste1=1; teste2=0; teste3=0 ;teste4=0 ; teste5=0;break;
            case(2):teste1=0; teste2=1; teste3=0 ;teste4=0 ; teste5=0;break;
            case(3):teste1=0; teste2=0; teste3=3 ;teste4=0 ; teste5=0;break;
            case(4):teste1=0; teste2=0; teste3=0 ;teste4=1 ; teste5=0;break;
            case(5):teste1=0; teste2=0; teste3=0 ;teste4=0 ; teste5=1;break;
            default:exit(0);
        }

    if(teste1){

        FILE *arq;
        double x_init = 2.0;
        double t_init = 1.0;
        double t_end = 2.0;
        int np = 50;
        double h;
        double x, x_real;
        double t;
        double erro_old ;
        double erro = 0.0;
        double ordem=0.0;
        double k1, k2, k3, k4;
        double x_real_t;
        int i=0,n=0;

        arq = fopen("Relatorio do teste1.txt","w");

        for(i=0;i<6;i++){
            fprintf(arq,"\n\n\n\t\tnp = %d\n\n",np);
            erro_old=erro;
            x = x_init;
            h = (t_end - t_init)/np ;
            t = t_init;
            x_real_t = tst1e(t_init);
            for( n=1 ; n <= np  ; n++ ){



                fprintf(arq,"%.10f\t%.10f\t%.10f\n",t,x,x_real_t);
                //printf("%lf\t%lf\t%lf\n",t,x,x_real_t);

                k1= h*tst1( t, x);
                k2= h*tst1( t + 0.5*h, x + 0.5*k1 );
                k3= h*tst1( t + 0.5*h, x + 0.5*k2 );
                k4= h*tst1( t + h , x + k3);

                x = x + ( k1 + 2.0*k2 + 2.0*k3 + k4 )/6.0;
                t = n*h + t_init;
                x_real_t = tst1e(t);
            }
            fprintf(arq,"%.10f\t%.10f\t%.10f\n",t,x,x_real_t);
            erro = absoluto( x_real_t - x );
            ordem = log2(erro_old/erro);
            if (i>=1)
                printf("Ordem = %f  np = %d->%d\n",ordem,np/2,np);
            np=np*2.0;
        }


        fclose(arq);



        exit(0);
    }








    if(teste2){

        FILE *arq;
        double x_init = cos(0.1);
        double t_init = 0.1;
        double t_end = 1.0;
        int np = 50;
        double h;
        double x, x_real;
        double t;
        double erro_old ;
        double erro = 0.0;
        double ordem=0.0;
        double k1, k2, k3, k4;
        double x_real_t;
        int i=0,n=0;

        arq = fopen("Relatorio do teste2.txt","w");

        for(i=0;i<6;i++){
            fprintf(arq,"\n\n\n\t\tnp = %d\n\n",np);
            erro_old=erro;
            x = x_init;
            h = (t_end - t_init)/np ;
            t = t_init;
            x_real_t = tst2e(t_init);
            for( n=1 ; n <= np  ; n++ ){



                fprintf(arq,"%.10f\t%.10f\t%.10f\n",t,x,x_real_t);
                //printf("%lf\t%lf\t%lf\n",t,x,x_real_t);

                k1= h*tst2( t, x);
                k2= h*tst2( t + 0.5*h, x + 0.5*k1 );
                k3= h*tst2( t + 0.5*h, x + 0.5*k2 );
                k4= h*tst2( t + h , x + k3);

                x = x + ( k1 + 2.0*k2 + 2.0*k3 + k4 )/6.0;
                t = n*h + t_init;
                x_real_t = tst2e(t);
            }
            fprintf(arq,"%.10f\t%.10f\t%.10f\n",t,x,x_real_t);
            erro = absoluto( x_real_t - x );
            ordem = log2(erro_old/erro);
            if (i>=1)
                printf("Ordem = %f  np = %d->%d\n",ordem,np/2,np);
            np=np*2.0;
        }


        fclose(arq);



        exit(0);
    }














    if(teste3){

    FILE *arq;                           //Ponteiro para manipulação de arquivos
    char name_arq[20];                   //Nome do arquivo maximo de 19 characters
    double h;
    int np=500;                            //Passo do Runge-Kutta
    double t_final=-9999.0;                      //Tempo final
    double t_inicial=0;                          //Tempo
    double t=t_inicial;
    int k,j,i;
    int n;

    while(t_final<0){
        printf(" Digite o tempo final (maior que zero): \n");
        scanf("%lf",&t_final);
    }

    //printf(" Digite o valor do passo inicial 'h': \n");
    //scanf("%lf",&h);

    double k11,k12,k13,k14,k21,k22,k23,k24,k31,k32,k33,k34,k41,k42,k43,k44;   //Aplicação do metodo Runge-Kutta de quarta ordem.

    double x1 = 1.0;  //x do range-kutta
    double x2 = 1.0;
    double x3 = 1.0;
    double x4 = -1.0;

    double x1e =  h1e(t_inicial); //x da solucao exata no tempo final
    double x2e =  h2e(t_inicial);
    double x3e =  h3e(t_inicial);
    double x4e =  h4e(t_inicial);

    double sold, snew;  //Variaveis de somatorio para norma euclidiana
    double r;   //var aux
    double ordem; //ordem o metodo
    arq = fopen("Relatorio do teste3.txt","w");                //Abrir arquivo "arq" com o nome "name_arq" como escrita de dados

    h=(t_final-t_inicial)/np;

    for (j=0; j<6; j++){
        fprintf(arq,"\n\n\n\t\t\t\t\t\t\t\t\t     np = %d\n\n",np);

        for(n=1; n <= np; n++){

            fprintf(arq,"%lf\t%lf\t%lf\t%lf\t%lf\t||\t",t,x1,x2,x3,x4);    //Escrita de arquivo: t//x1//x2//x3//x4
            fprintf(arq,"%lf\t%lf\t%lf\t%lf\t%lf\t\n",t,x1e,x2e,x3e,x4e);
            //printf("%f\t%f\t%f\t%f\t%f\t\n",t,x1,x2,x3,x4);

            k11= h*h1( t,x1, x2, x3, x4);
            k12= h*h2( t,x1, x2, x3, x4);
            k13= h*h3( t,x1, x2, x3, x4);
            k14= h*h4( t,x1, x2, x3, x4);

            k21= h*h1( t + 0.5*h, x1 + 0.5*k11, x2+ 0.5*k12, x3 + 0.5*k13, x4 + 0.5*k14 );
            k22= h*h2( t + 0.5*h, x1 + 0.5*k11, x2+ 0.5*k12, x3 + 0.5*k13, x4 + 0.5*k14 );
            k23= h*h3( t + 0.5*h, x1 + 0.5*k11, x2+ 0.5*k12, x3 + 0.5*k13, x4 + 0.5*k14 );
            k24= h*h4( t + 0.5*h, x1 + 0.5*k11, x2+ 0.5*k12, x3 + 0.5*k13, x4 + 0.5*k14 );

            k31= h*h1( t + 0.5*h, x1 + 0.5*k21, x2+ 0.5*k22, x3 + 0.5*k23, x4 + 0.5*k24 );
            k32= h*h2( t + 0.5*h, x1 + 0.5*k21, x2+ 0.5*k22, x3 + 0.5*k23, x4 + 0.5*k24 );
            k33= h*h3( t + 0.5*h, x1 + 0.5*k21, x2+ 0.5*k22, x3 + 0.5*k23, x4 + 0.5*k24 );
            k34= h*h4( t + 0.5*h, x1 + 0.5*k21, x2+ 0.5*k22, x3 + 0.5*k23, x4 + 0.5*k24 );

            k41= h*h1(t+h, x1+k31, x2+k32, x3+k33, x4+k34);
            k42= h*h2(t+h, x1+k31, x2+k32, x3+k33, x4+k34);
            k43= h*h3(t+h, x1+k31, x2+k32, x3+k33, x4+k34);
            k44= h*h4(t+h, x1+k31, x2+k32, x3+k33, x4+k34);

            x1 = x1 + ( k11 + 2.0*k21 + 2.0*k31 + k41 )/6.0;
            x2 = x2 + ( k12 + 2.0*k22 + 2.0*k32 + k42 )/6.0;
            x3 = x3 + ( k13 + 2.0*k23 + 2.0*k33 + k43 )/6.0;
            x4 = x4 + ( k14 + 2.0*k24 + 2.0*k34 + k44 )/6.0;

            t= n*h + t_inicial;

            x1e=h1e(t);
            x2e=h2e(t);
            x3e=h3e(t);
            x4e=h4e(t);

        }
        fprintf(arq,"%lf\t%lf\t%lf\t%lf\t%lf\t||\t",t,x1,x2,x3,x4);    //Escrita de arquivo: t//x1//x2//x3//x4
        fprintf(arq,"%lf\t%lf\t%lf\t%lf\t%lf\t\n",t,x1e,x2e,x3e,x4e);
        snew=(x1-x1e)*(x1-x1e)+(x2-x2e)*(x2-x2e)+(x3-x3e)*(x3-x3e)+(x4-x4e)*(x4-x4e);
        if(j>=1){
        r=sqrt(sold/snew);
        ordem=log2(r);
        printf("Ordem = %f  np = %d->%d\n",ordem,np/2,np);
        }
        np=np*2.0;
        t=t_inicial;
        h=(t_final-t_inicial)/np;
        x1 = 1.0;  //x do range-kutta
        x2 = 1.0;
        x3 = 1.0;
        x4 = -1.0;
        x1e =  h1e(t_inicial); //x da solucao exata no tempo final
        x2e =  h2e(t_inicial);
        x3e =  h3e(t_inicial);
        x4e =  h4e(t_inicial);
        sold=snew;
        }

    fclose(arq);

    exit(0);
    }



















    if(teste4){
        //

        FILE *arq;                           //Ponteiro para manipulação de arquivos
        char name_arq[20];                   //Nome do arquivo maximo de 19 characters
        double v_init=-12.0;            //Angulo do pendulo com a normal inicial
        double z_init = 0.0;               //Velocidade angular do pendulo inicial
        double v;                         //Angulo do pendulo com a normal
        double z;                            //Velocidade angular do pendulo
        double h;                            //Passo do Runge-Kutta
        double v_real_t;
        double t_final= 1.0 ;                      //Tempo final
        double t=0;                          //Tempo
        double erro_old, erro=0, ordem;
        int np = 50;
        int n,i;

        printf("Digite o nome do arquivo ao qual os dados serao salvos [max 19 char]: \n");
        scanf("%s",name_arq);


        double k11,k12,k21,k22,k31,k32,k41,k42;   //Aplicação do metodo Runge-Kutta de quarta ordem.
        arq = fopen(name_arq,"w");                //Abrir arquivo "arq" com o nome "name_arq" como escrita de dados




        for(i=0;i<6;i++){

            erro_old = erro;
            v = v_init;
            v_real_t = v_init;
            z = z_init;
            h = (t_final)/np;
            t=0.0;
            for(n=1; n <= np; n++){

                fprintf(arq,"%f\t%f\t%f\t%f\n",t,v,z,v_real_t);    //Escrita de arquivo: t//teta//v
                //printf("%f\t%f\t%f\t%f\n",t,v,v_real_t, z);

                k11= h*g1_tst4( t, v, z);
                k12= h*g2_tst4( t, v, z);
                k21= h*g1_tst4( t + 0.5*h, v + 0.5*k11, z+ 0.5*k12 );
                k22= h*g2_tst4( t + 0.5*h, v + 0.5*k11, z+ 0.5*k12 );
                k31= h*g1_tst4( t + 0.5*h, v + 0.5*k21, z+ 0.5*k22 );
                k32= h*g2_tst4( t + 0.5*h, v + 0.5*k21, z+ 0.5*k22 );
                k41= h*g1_tst4( t + h , v + k31 , z + k32 );
                k42= h*g2_tst4( t + h , v + k31 , z + k32 );

                v = v + ( k11 + 2.0*k21 + 2.0*k31 + k41 )/6.0;
                z = z + ( k12 + 2.0*k22 + 2.0*k32 + k42 )/6.0;
                t = 0.0 + n*h;
                v_real_t = tst4e(t);
            }
            fprintf(arq,"%f\t%f\t%f\t%f\n",t,v,z,v_real_t);    //Escrita de arquivo: t//teta//v
            //printf("%f\t%f\t%f\t%f\n",t,v,v_real_t, z);
        erro = absoluto(v_real_t-v);
        ordem = log2(erro_old/erro);
        if (i>=1)
                printf("Ordem = %f  np = %d->%d\n",ordem,np/2,np);
        np=np*2.0;
        fprintf(arq,"\nOrdem = %lf\t np = %d\n\n\n",ordem,np);
        }


        fclose(arq);

        exit(0);
        }


















//====================================================================// Solving Problem: //=========================================================================

    FILE *arq;                           //Ponteiro para manipulação de arquivos
    char name_arq[20];                   //Nome do arquivo maximo de 19 characters
    double teta_init=-9999.0;            //Angulo do pendulo com a normal inicial
    double v_init=-9999.0;               //Velocidade angular do pendulo inicial
    double teta;                         //Angulo do pendulo com a normal
    double v;                            //Velocidade angular do pendulo
    double h;                            //Passo do Runge-Kutta
    double t_final=-9999;                      //Tempo final
    double t=0;                          //Tempo
    double E,E_old;
    double var_energy=0.0;
    int np,n;



    while(teta_init<-270 || teta_init>270){
        printf(" Digite o valor do angulo inicial em graus que o pendulo faz com a normal\n Esse valor deve estar entre -270 e 270 graus\n");
        scanf("%lf",&teta_init);
    }
    while(v_init<-4 || v_init>4){
        printf(" Digite a velocidade angular inicial do pendulo\n Esse valor deve estar entra -4 e 4 \n");
        scanf("%lf",&v_init);
    }

    while(t_final<0){
        printf(" Digite o tempo final (maior que zero): \n");
        scanf("%lf",&t_final);
    }

    printf(" Digite o numero de passo 'np': \n");
    scanf("%d",&np);

    printf("Digite o nome do arquivo ao qual os dados serao salvos [max 19 char]: \n");
    scanf("%s",name_arq);

    teta_init = teta_init*3.141592653589793/180.0;

    double k11,k12,k21,k22,k31,k32,k41,k42;   //Aplicação do metodo Runge-Kutta de quarta ordem.
    arq = fopen(name_arq,"w");                //Abrir arquivo "arq" com o nome "name_arq" como escrita de dados
    var_energy = 1.0;

    if(teste5)
        u = 0.0;

    while(var_energy > 1.0e-10){
            fprintf(arq,"\n\nPara o numero de passos = %d\n\n\n",np);
            printf("\n\nPara o numero de passos = %d",np);
            teta = teta_init;
            v = v_init;
            h = (t_final)/np;
            t = 0.0;
            E_old = 0.5*(v*v) - (w*w)*cos(teta) ;
            for(n=1; n <= np; n++){

                E_old = E;
                fprintf(arq,"%f\t%f\t%f\t\%e\n",t,teta,v,var_energy);    //Escrita de arquivo: t//teta//v
                printf("%f\t%f\t%f\t%e\n",t,teta*180.0/3.141592653589793,v,var_energy);

                k11= h*f1( t, teta, v);
                k12= h*f2( t, teta, v);
                k21= h*f1( t + 0.5*h, teta + 0.5*k11, v+ 0.5*k12 );
                k22= h*f2( t + 0.5*h, teta + 0.5*k11, v+ 0.5*k12 );
                k31= h*f1( t + 0.5*h, teta + 0.5*k21, v+ 0.5*k22 );
                k32= h*f2( t + 0.5*h, teta + 0.5*k21, v+ 0.5*k22 );
                k41= h*f1(t+h,teta+k31,v+k32);
                k42= h*f2(t+h,teta+k31,v+k32);

                teta = teta + ( k11 + 2.0*k21 + 2.0*k31 + k41 )/6.0;
                v = v + ( k12 + 2.0*k22 + 2.0*k32 + k42 )/6.0;

                t = 0.0 + n*h;

                E = 0.5*v*v - w*w*cos(teta);

                var_energy = E_old-E;
                var_energy = absoluto(var_energy);
                if(var_energy>1.0e-10)
                    break;
            }
            if(teste5==0)
                break;
    np = np * 2;
    }
    fprintf(arq,"\n\n\nO valor de h = %lf\tCom o valor np= %d\n\n",h,np/2);
    printf("\n\n\nO valor de h = %lf\tCom o valor np= %d\n\n",h,np/2);

    if(teste5==0)
    {
        fprintf(arq,"\n\nPara o numero de passos = %d\n\n\n",np);
            printf("\n\nPara o numero de passos = %d",np);
            teta = teta_init;
            v = v_init;
            h = (t_final)/np;

            E_old = 0.5*(v*v) - (w*w)*cos(teta) ;
            t = 0.0;
            for(n=1; n <= np; n++){

                E_old = E;
                fprintf(arq,"%f\t%f\t%f\t\%e\n",t,teta,v,var_energy);    //Escrita de arquivo: t//teta//v
                printf("%f\t%f\t%f\t%e\n",t,teta*180.0/3.141592653589793,v,var_energy);

                k11= h*f1( t, teta, v);
                k12= h*f2( t, teta, v);
                k21= h*f1( t + 0.5*h, teta + 0.5*k11, v+ 0.5*k12 );
                k22= h*f2( t + 0.5*h, teta + 0.5*k11, v+ 0.5*k12 );
                k31= h*f1( t + 0.5*h, teta + 0.5*k21, v+ 0.5*k22 );
                k32= h*f2( t + 0.5*h, teta + 0.5*k21, v+ 0.5*k22 );
                k41= h*f1(t+h,teta+k31,v+k32);
                k42= h*f2(t+h,teta+k31,v+k32);

                teta = teta + ( k11 + 2.0*k21 + 2.0*k31 + k41 )/6.0;
                v = v + ( k12 + 2.0*k22 + 2.0*k32 + k42 )/6.0;

                t = 0.0 + n*h;

                E = 0.5*v*v - w*w*cos(teta);

                var_energy = E_old-E;
                var_energy = absoluto(var_energy);

            }
            fprintf(arq,"%f\t%f\t%f\t\%e\n",t,teta,v,var_energy);    //Escrita de arquivo: t//teta//v
            printf("%f\t%f\t%f\t%e\n",t,teta*180.0/3.141592653589793,v,var_energy);

    }

    fclose(arq);

    system("pause");
    return 0;
}




