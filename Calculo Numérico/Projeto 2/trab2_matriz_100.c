
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846264338327950

double p(double X){// indice da derivada segunda do PVC
    return 1+X*X;

}
double p1(double X){// indice da derivada segunda do teste 1
    return 1;

}
double p2(double X){// indice da derivada segunda do teste 2
    return -1;

}
double p5(double X){// indice da derivada segunda do teste 5
    return 1;

}

double q(double X){//indice da derivada primeira do PVC
    return -4*X;
}
double q1(double X){//indice da derivada primeira do teste 1
    return 0;
}
double q2(double X){//indice da derivada primeira do teste 2
    return 0;
}
double q5(double X){//indice da derivada primeira do teste 5
    return 0;
}

double r(double X){//indice da derivada de ordem 0 do PVC
    return 6;

}
double r1(double X){//indice da derivada de ordem 0 do teste 1
    return 1;

}
double r2(double X){//indice da derivada de ordem 0 do teste 2
    return 1;

}
double r5(double X){//indice da derivada de ordem 0 do teste 5
    return 0;

}

double f(double X, double epsilon){//indice do termo independente do teste 1
    return epsilon*exp(-X*X);

}
double f1(double X){//indice do termo independente do teste 1
    return X*X*exp(-X);

}
double f2(double X){//indice do termo independente do teste 2
    return 2.0*cos(X);

}
double f5(double X){//indice do termo independente do teste 5
    return 0;

}

double e1 (double X){    //Retorna o resultado analitico do teste 1
    return 0.5*exp(-X)*(1.0 + 2.0*X + X*X - exp(X)*cos(X) - 2.0*exp(X)*(-0.5*(cos(10.0)/sin(10.0)) + 121.0/(2.0*exp(10.0)*sin(10.0)))*sin(X)) ;
}
double e2 (double X){    //Retorna o resultado analitico do teste 2
    return cos(X);
}
double e5 (double X){    //Retorna o resultado analitico do teste 5
    return 2.0*X+2.0;
}




int main()
{

    clock_t temp;// declara a variavel para o calculo do tempo
    char teste1, teste2, teste3, teste4, teste5;
    int menu;


    printf("O que deseja?\n1-Teste1\n2-Teste2\n3-Exercicio_Oficial\n4-Teste para achar o W ideal\n5-Teste que converge os iterativos(Teste0 novo)\n\n-?-EXIT\n");
    scanf("%d",&menu);
    switch(menu)
        {
            case(1):teste1=1; teste2=0; teste3=0 ;teste4=0 ; teste5=0;break;
            case(2):teste1=0; teste2=1; teste3=0 ;teste4=0 ; teste5=0;break;
            case(3):teste1=0; teste2=0; teste3=3 ;teste4=0 ; teste5=0;break;
            case(4):teste1=0; teste2=0; teste3=0 ;teste4=1 ; teste5=0;break;
            case(5):teste1=0; teste2=0; teste3=0 ;teste4=0 ; teste5=1;break;
            default:exit(0);
        }



        int i,j,k,c, cy;//auxiliares
        double alfa1, alfa2, va, beta1, beta2, vb;// constantes das condicoes de contorno
        int np=50;//numero de passos


        double **A;             //A[np][np];// matriz dos coeficientes tridiagonal
        A = (double**)malloc(np*sizeof(double*));
        for(c=0;c<np;c++)
            A[c]=(double*)malloc(np*sizeof(double));


        double *u;             //u[np+1];//vetor solucao
        u = (double*)malloc((np+1)*sizeof(double));


        double *b;              //b[np];//vetor dos termos independentes
        b = (double*)malloc(np*sizeof(double));

        double **A_aux;         //A_aux[np][np];
        A_aux = (double**)malloc(np*sizeof(double*));
        for(c=0;c<np;c++)
            A_aux[c]=(double*)malloc(np*sizeof(double));

        double *b_aux;          //b_aux [np];//vetor dos termos independentes
        b_aux = (double*)malloc(np*sizeof(double));

        double X;
        double x_inicial;
        double x_final;
        double h;// tamanho do espacamento
        int N; // contador do loop para atualizar o h
        double valor_analitico;
        double En;//Erro da iteracao antiga com n passos
        double E2n;//Erro da iteracao nova com 2n passos
        double Enmax;//Erro maxima a partir da normal infinita
        double ordem;
        FILE *arq;//ponteiro para arquivo
        FILE *arqs;//ponteiro para arquivo solucao




        double Er=10.0;//erro relativo
        double e=1.e-7;   //criterio de parada
        double soma=0.0; //somas auxiliares
        int iteracao=0;//contador de iteracao
        int n=np-1;//numero de sistemas
        double *Xold, *Xnew; //vetores solucao dos metodos iterativos
        double *x;//vetor solucao dos metodos analiticos


        double aux;//variavel aux
        int linha;// armazena o numero da linha
        double max;// armazena o valor maximo da coluna
        double m;//fator de multiplicacao entre as linhas dos MEGs


        double numerador=0.0;//numerador do erro relativo
        double denominador=0.0;//denominador do erro relativo

        double *sol_analitica;






    for(cy=0;cy<5;cy++){



        sol_analitica =  (double*)malloc((np+1)*sizeof(double));

        A = (double**)malloc(np*sizeof(double*));
        for(c=0;c<np;c++)
            A[c]=(double*)malloc(np*sizeof(double));

        u = (double*)malloc((np+1)*sizeof(double));

        b = (double*)malloc(np*sizeof(double));


        A_aux = (double**)malloc(np*sizeof(double*));
        for(c=0;c<np;c++)
            A_aux[c]=(double*)malloc(np*sizeof(double));



        b_aux = (double*)malloc(np*sizeof(double));



        Enmax=0;





        ////////////////////////////////////////TESTE 1///////////////////////////////////////////////

        if (teste1){

            alfa1=1; alfa2=0; va=0; beta1=1; beta2=0; vb=0;// constantes das condicoes de contorno
            x_inicial=0;
            x_final=10;
            h=(x_final-x_inicial)/np;// calculo do espassamento
            N=1; // contador do loop para atualizar o h

            //printf("u[0] = %lf, u[%d] = %lf\n", u[0], np, u[np]);


            //Criando uma matriz [np-2][np-2] de zeros
            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    A[i][j]=0;                //zera a matriz dos coeficientes
                }
            }


            X=x_inicial+N*h; // inicializa a variavel x em x_k onde k=1


            //calculo da primeira linha de A, e de b
            A[1][1]=2.0*h*h*r1(X)-4.0*p1(X)-4.0*alfa2*(2.0*p1(X)-h*q1(X))/(2.0*h*alfa1-3.0*alfa2);//calculo a[1];
            A[1][2]=2.0*p1(X)+h*q1(X)+alfa2*(2.0*p1(X)-h*q1(X))/(2*h*alfa1-3.0*alfa2);
            b[1]=2.0*h*h*f1(X)-(2*h*va)*(2.0*p1(X)-h*q1(X))/(2*h*alfa1-3.0*alfa2);

            N = 2;

            for (i=2;i<=np-2;i++){
                X=x_inicial+h*N;
                for(j=1;j<=3;j++){//preenche a tridiagonal
                    A[i][i-1]=2.0*p1(X)-h*q1(X);// calculo do d[i] da matriz
                    A[i][i]=2.0*h*h*r1(X)-4.0*p1(X);//calculo do a[i] da matriz
                    A[i][i+1]=2.0*p1(X)+h*q1(X);// calculo do c[i] da matriz
                }
                b[i]=2.0*h*h*f1(X);
                N++;
            }
            X=x_inicial+h*N;

            //calculo da utima linha de A, e de b
            A[np-1][np-2]=2.0*p1(X)-h*q1(X)-beta2*(2.0*p1(X)+h*q1(X))/(2.0*h*beta1+3*beta2);
            A[np-1][np-1]=2.0*h*h*r1(X)-4.0*p1(X)+4*beta2*(2.0*p1(X)+h*q1(X))/(2.0*h*beta1+3*beta2);
            b[np-1]=2.0*h*h*f1(X)-2*h*vb*(2.0*p1(X)+h*q1(X))/(2.0*h*beta1+3*beta2);

            FILE* arq=fopen("matriz_teste1.txt","w");

            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    fprintf(arq,"%lf\t", A[i][j]);//zera a matriz dos coeficientes
                }
                fprintf(arq,"\t%lf\n", b[i]);
            }
            fclose(arq);

            printf("\n\nRESPOSTA ANALITICA TESTE 1:\n");
            for(i=0;i<=np;i++)
            {
                X = x_inicial+ h*i;
                valor_analitico = e1(X);
                sol_analitica[i]= valor_analitico;
                //printf("x = %lf temos f = %lf \n", X , valor_analitico);
            }
        }






















        //////////////////////////////////////TESTE 2//////////////////////////////////////////

        if (teste2){

            alfa1=3; alfa2=1; va=-1; beta1=4; beta2=1; vb=-4;// constantes das condicoes de contorno
            x_inicial=PI*0.5;
            x_final=PI;
            h=(x_final-x_inicial)/np;// calculo do espassamento
            N=1; // contador do loop para atualizar o h

            //printf("u[0] = %lf, u[%d] = %lf\n", u[0], np, u[np]);


            //Criando uma matriz [np-2][np-2] de zeros
            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    A[i][j]=0;                //zera a matriz dos coeficientes
                }
            }


            X=x_inicial+N*h; // inicializa a variavel x em x_k onde k=1


            //calculo da primeira linha de A, e de b
            A[1][1]=2.0*h*h*r2(X)-4.0*p2(X)-4.0*alfa2*(2.0*p2(X)-h*q2(X))/(2.0*h*alfa1-3.0*alfa2);//calculo a[1];
            A[1][2]=2.0*p2(X)+h*q2(X)+alfa2*(2.0*p2(X)-h*q2(X))/(2*h*alfa1-3.0*alfa2);
            b[1]=2.0*h*h*f2(X)-(2*h*va)*(2.0*p2(X)-h*q2(X))/(2*h*alfa1-3.0*alfa2);

            N = 2;

            for (i=2;i<=np-2;i++){
                X=x_inicial+h*N;
                for(j=1;j<=3;j++){//preenche a tridiagonal
                    A[i][i-1]=2.0*p2(X)-h*q2(X);// calculo do d[i] da matriz
                    A[i][i]=2.0*h*h*r2(X)-4.0*p2(X);//calculo do a[i] da matriz
                    A[i][i+1]=2.0*p2(X)+h*q2(X);// calculo do c[i] da matriz
                }
                b[i]=2.0*h*h*f2(X);
                N++;
            }
            X=x_inicial+h*N;

            //calculo da utima linha de A, e de b
            A[np-1][np-2]=2.0*p2(X)-h*q2(X)-beta2*(2.0*p2(X)+h*q2(X))/(2.0*h*beta1+3*beta2);
            A[np-1][np-1]=2.0*h*h*r2(X)-4.0*p2(X)+4*beta2*(2.0*p2(X)+h*q2(X))/(2.0*h*beta1+3*beta2);
            b[np-1]=2.0*h*h*f2(X)-2*h*vb*(2.0*p2(X)+h*q2(X))/(2.0*h*beta1+3*beta2);

            u[0]=(2.0*h*va-4.0*alfa2*u[1]+alfa2*u[2])/(2.0*h*alfa1-3.0*alfa2);
            u[np]=(2.0*h*vb+4.0*beta2*u[np-1]-beta2*u[np-2])/(2.0*h*beta1+3*beta2);

            FILE* arq=fopen("matriz_teste2.txt","w");\

            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    fprintf(arq,"%lf\t", A[i][j]);//zera a matriz dos coeficientes
                }
                fprintf(arq,"\t%lf\n", b[i]);
            }
            fclose(arq);


            printf("\n\nRESPOSTA ANALITICA TESTE 2:\n");
            for(i=0;i<=np;i++)
            {
                X = x_inicial+ h*i;
                valor_analitico = e2(X);
                sol_analitica[i]= valor_analitico;
                //printf("x = %lf temos f = %lf \n", X , valor_analitico);
            }
        }

////////////////////////////////////////TESTE 5///////////////////////////////////////////////

        if (teste5){

            alfa1=1; alfa2=0; va=2; beta1=1; beta2=0; vb=4;// constantes das condicoes de contorno
            x_inicial=0;
            x_final=1;
            h=(x_final-x_inicial)/np;// calculo do espassamento
            N=1; // contador do loop para atualizar o h

            //printf("u[0] = %lf, u[%d] = %lf\n", u[0], np, u[np]);


            //Criando uma matriz [np-2][np-2] de zeros
            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    A[i][j]=0;                //zera a matriz dos coeficientes
                }
            }


            X=x_inicial+N*h; // inicializa a variavel x em x_k onde k=1


            //calculo da primeira linha de A, e de b
            A[1][1]=2.0*h*h*r5(X)-4.0*p5(X)-4.0*alfa2*(2.0*p5(X)-h*q5(X))/(2.0*h*alfa1-3.0*alfa2);//calculo a[1];
            A[1][2]=2.0*p5(X)+h*q5(X)+alfa2*(2.0*p5(X)-h*q5(X))/(2*h*alfa1-3.0*alfa2);
            b[1]=2.0*h*h*f5(X)-(2*h*va)*(2.0*p5(X)-h*q5(X))/(2*h*alfa1-3.0*alfa2);

            N = 2;

            for (i=2;i<=np-2;i++){
                X=x_inicial+h*N;
                for(j=1;j<=3;j++){//preenche a tridiagonal
                    A[i][i-1]=2.0*p5(X)-h*q5(X);// calculo do d[i] da matriz
                    A[i][i]=2.0*h*h*r5(X)-4.0*p5(X);//calculo do a[i] da matriz
                    A[i][i+1]=2.0*p5(X)+h*q5(X);// calculo do c[i] da matriz
                }
                b[i]=2.0*h*h*f5(X);
                N++;
            }
            X=x_inicial+h*N;

            //calculo da utima linha de A, e de b
            A[np-1][np-2]=2.0*p5(X)-h*q5(X)-beta2*(2.0*p5(X)+h*q5(X))/(2.0*h*beta1+3*beta2);
            A[np-1][np-1]=2.0*h*h*r5(X)-4.0*p5(X)+4*beta2*(2.0*p5(X)+h*q5(X))/(2.0*h*beta1+3*beta2);
            b[np-1]=2.0*h*h*f5(X)-2*h*vb*(2.0*p5(X)+h*q5(X))/(2.0*h*beta1+3*beta2);

            FILE* arq=fopen("matriz_teste5.txt","w");
            arqs = fopen("Solucao_teste5.txt","w");

            fprintf(arqs,"Variavel Independente\n");
            for(i=0;i<=np;i++){
                fprintf(arqs,"%lf\n",x_inicial+h*i);

            }
            fprintf(arqs,"\n");

            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    fprintf(arq,"%lf\t", A[i][j]);//zera a matriz dos coeficientes
                }
                fprintf(arq,"\t%lf\n", b[i]);
            }
            fclose(arq);

            printf("\n\nRESPOSTA ANALITICA TESTE 1:\n");
            for(i=0;i<=np;i++)
            {
                X = x_inicial+ h*i;
                valor_analitico = e5(X);
                sol_analitica[i]= valor_analitico;
                printf("x = %lf temos f = %lf \n", X , valor_analitico);
            }
        }

      //------------------------------------------------------ EXERCICIO OFICICIAL ---------------------------------------------------------






        if (teste3||teste4){
            int ene;
            arq = fopen("Matriz_exercicio_proposto.txt","w");
            arqs = fopen("Solucao_exercicio_proposto.txt","w");
            printf("Qual o valor do n?\n");
            printf("Valores recomendados 10, 20 , 80, 160, 320\n");
            scanf("%d",&ene);
            double epsilon=1.0/ene;
            alfa1=1.0; alfa2=0.0; va=1.0; beta1=1.0; beta2=0.0; vb=0.0;// constantes das condicoes de contorno
            x_inicial=0.0;
            x_final=1.0;
            h=(x_final-x_inicial)/np;// calculo do espassamento
            N=1; // contador do loop para atualizar o h

            //printf("u[0] = %lf, u[%d] = %lf\n", u[0], np, u[np]);


            //Criando uma matriz [np-2][np-2] de zeros
            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    A[i][j]=0;                //zera a matriz dos coeficientes
                }
            }


            X=x_inicial+N*h; // inicializa a variavel x em x_k onde k=1
            if(teste3){
                fprintf(arqs,"Variavel Independente\n");
                for(i=0;i<=np;i++){
                    fprintf(arqs,"%lf\n",x_inicial+h*i);

                }
                fprintf(arqs,"\n");
            }

            //calculo da primeira linha de A, e de b
            A[1][1]=2.0*h*h*r(X)-4.0*p(X)-4.0*alfa2*(2.0*p(X)-h*q(X))/(2.0*h*alfa1-3.0*alfa2);//calculo a[1];
            A[1][2]=2.0*p(X)+h*q(X)+alfa2*(2.0*p(X)-h*q(X))/(2*h*alfa1-3.0*alfa2);
            b[1]=2.0*h*h*f(X,epsilon)-(2*h*va)*(2.0*p(X)-h*q(X))/(2*h*alfa1-3.0*alfa2);

            N = 2;

            for (i=2;i<=np-2;i++){
                X=x_inicial+h*N;
                for(j=1;j<=3;j++){//preenche a tridiagonal
                    A[i][i-1]=2.0*p(X)-h*q(X);// calculo do d[i] da matriz
                    A[i][i]=2.0*h*h*r(X)-4.0*p(X);//calculo do a[i] da matriz
                    A[i][i+1]=2.0*p(X)+h*q(X);// calculo do c[i] da matriz
                }
                b[i]=2.0*h*h*f(X,epsilon);
                N++;
            }
            X=x_inicial+h*N;

            //calculo da utima linha de A, e de b
            A[np-1][np-2]=2.0*p(X)-h*q(X)-beta2*(2.0*p(X)+h*q(X))/(2.0*h*beta1+3*beta2);
            A[np-1][np-1]=2.0*h*h*r(X)-4.0*p(X)+4*beta2*(2.0*p(X)+h*q(X))/(2.0*h*beta1+3*beta2);
            b[np-1]=2.0*h*h*f(X,epsilon)-2*h*vb*(2.0*p(X)+h*q(X))/(2.0*h*beta1+3*beta2);

            u[0]=(2.0*h*va-4.0*alfa2*u[1]+alfa2*u[2])/(2.0*h*alfa1-3.0*alfa2);
            u[np]=(2.0*h*vb+4.0*beta2*u[np-1]-beta2*u[np-2])/(2.0*h*beta1+3*beta2);


            for(i=1;i<=np-1;i++){
                for(j=1;j<=np-1;j++){
                    fprintf(arq,"%lf\t", A[i][j]);//escreve a matriz dos coeficientes no arquivo
                }
                fprintf(arq,"\t%lf\n", b[i]);
            }
            fclose(arq);
        }











        //Salvando A e B no formato das diferenças finitas, para que os metodos de resoluçao nao se atrapalhem.

        for (i=1; i< np ; i++)
        {
            for(j=1;j<np;j++)
            {
                A_aux[i][j] = A[i][j];
            }
            b_aux[i]=b[i];
        }










//========================================================================================================RESOLUCAO DE SISTEMA LINEAR=====================================================================//



         Er=10.0;//erro relativo
         e=1.e-7;   //criterio de parada
         soma=0.0; //somas auxiliares
        iteracao=0;//contador de iteracao
         n=np-1;//numero de sistemas
        Xold = (double*)malloc((n+1)*sizeof(double));
        Xnew = (double*)malloc((n+1)*sizeof(double));      //Xold[n+1], Xnew[n+1]; //vetores solucao dos metodos iterativos

        for(i=1;i<=n;i++){
            Xnew[i]=0.0;//zera o vetor inicial
        }


         x = (double*)malloc((n+1)*sizeof(double));//x[n+1];//vetor solucao dos metodos analiticos
        for(i=1;i<=n;i++){
            Xnew[i]=0.0;//zera o vetor inicial
        }

         numerador=0.0;//numerador do erro relativo
         denominador=0.0;//denominador do erro relativo





if(teste4==0){

        //=============================MEG=============================//
            if(teste3||teste5)
                printf("\nEliminacao Gaussiana sem pivotamento\n");

            for ( k = 1 ; k <= n - 1 ; k++ )
            {
              for ( i = k + 1 ; i <= n ; i++ )
            {
              m = A[ i ] [ k ] / A [ k ] [ k ] ;
              for ( j = k ; j <= n ; j++ )
                {
                  A [ i ] [ j ] = A [ i ] [ j ] - m * A [ k ] [ j ] ;
                }
              b [ i ] = b [ i ] - m * b [ k ] ;
            }
            }

          //===============================================================
          // SISTEMA LINEAR APÓS A ELIMINAÇÃO GAUSSIANA
          //===============================================================
    if(teste3){
          fprintf ( arq,"\n" ) ;

          for ( i = 1 ; i <= n ; i++ )
            {
              for ( j = 1 ; j <= n ; j++ )
              {
                fprintf ( arq,"% lf " , A [ i ] [ j ] ) ;
              }
              fprintf ( arq,"% lf\n" , b [ i ] ) ;
            }
    }
          //===============================================================
          // SUBSTITUIÇÃO REGRESSIVA
          //===============================================================

          x [ n ] = b [ n ] / A [ n ] [ n ] ;

          for ( i = n - 1 ; i >= 1 ; i-- )
            {
              soma = 0.0 ;
              for ( j = i + 1 ; j <= n ; j++ )
            {
              soma += A [ i ] [ j ] * x [ j ] ;
            }
              x [ i ] = ( b [ i ] - soma ) / A [ i ] [ i ] ;
            }
            u[0]=(2.0*h*va-4.0*alfa2*x[1]+alfa2*x[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
            u[np]=(2.0*h*vb+4.0*beta2*x[np-1]-beta2*x[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final
            if(teste3||teste5)
                printf("Solucao do sistema\n");
            if(teste3||teste4||teste5){
                printf("x0 = %lf\n",u[0]);
                fprintf(arqs,"MEG\n");
                fprintf(arqs,"%lf\n",u[0]);

                for(i=1;i<=n;i++){
                    printf("x%d = %lf\n",i,x[i]);
                    fprintf(arqs,"%lf\n",x[i]);


                }
                printf("x%d = %lf\n",np,u[np]);
                fprintf(arqs,"%lf\n\n",u[np]);
            }

        //RECUPERAÇÃO DA MATRIZ ORIGINAL




        for (i=1; i< np ; i++)
        {
            for(j=1;j<np;j++)
            {
                A[i][j] = A_aux[i][j];
            }
            b[i]=b_aux[i];
        }






















                //=============================MEGPP=============================//
        printf("\nEliminacao Gaussiana com pivotamento\n");

          for ( k = 1 ; k <= n - 1 ; k++ )
            {
              linha = k ;
              max = fabs ( A [ k ] [ k ] ) ;
              for ( i = k + 1 ; i <= n ; i++ )
            {
              if ( max < fabs ( A [ i ] [ k ] ) )
                {
                  linha = i ;
                  max = fabs ( A [ i ] [ k ] ) ;
                }
            }
              if ( linha > k )
            {
              for ( j = k ; j <= n ; j++ )
                {
                  aux = A [ k ] [ j ] ;
                  A [ k ] [ j ] = A [ linha ] [ j ] ;
                  A [ linha ] [ j ] = aux ;
                }
              aux = b [ k ] ;
              b [ k ] = b [ linha ] ;
              b [ linha ] = aux ;
            }
              for ( i = k + 1 ; i <= n ; i++ )
            {
              m = A [ i ] [ k ] / A [ k ] [ k ] ;
              for ( j = k ; j <= n ; j++ )
                {
                  A [ i ] [ j ] = A [ i ] [ j ] - m * A [ k ] [ j ] ;
                }
              b [ i ] = b [ i ] - m * b [ k ] ;
            }
            }

          //===============================================================
          // SISTEMA LINEAR APÓS A ELIMINAÇÃO GAUSSIANA
          //===============================================================
    if(teste3){

          fprintf (arq, "\n" ) ;

          for ( i = 1 ; i <= n ; i++ )
            {
              for ( j = 1 ; j <= n ; j++ )
            {
              fprintf (arq, "% lf " , A [ i ] [ j ] ) ;
            }
              fprintf (arq, "% lf\n" , b [ i ] ) ;
            }
    }
          //===============================================================
          // SUBSTITUIÇÃO REGRESSIVA
          //===============================================================

          x [ n ] = b [ n ] / A [ n ] [ n ] ;

          for ( i = n - 1 ; i >= 1 ; i-- )
            {
              soma = 0.0 ;
              for ( j = i + 1 ; j <= n ; j++ )
            {
              soma += A [ i ] [ j ] * x [ j ] ;
            }
              x [ i ] = ( b [ i ] - soma ) / A [ i ] [ i ] ;
            }

            u[0]=(2.0*h*va-4.0*alfa2*x[1]+alfa2*x[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
            u[np]=(2.0*h*vb+4.0*beta2*x[np-1]-beta2*x[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final


            printf("Solucao do sistema\n");
        if(teste3||teste5){
            printf("x0 = %lf\n",u[0]);
            fprintf(arqs,"MEGPP\n");
            fprintf(arqs,"%lf\n",u[0]);
        }
        for(i=1;i<=n;i++){
            if(teste3||teste5){
                printf("x%d = %lf\n",i,x[i]);
                fprintf(arqs,"%lf\n",x[i]);
                }
            En=sol_analitica[i]-x[i];
            if(En<0)
                En=-1.0*En;
            if(En>Enmax)
                Enmax=En;

        }
        if(teste3||teste5){
            printf("x%d = %lf\n",np,u[np]);
            fprintf(arqs,"%lf\n\n",u[np]);}
        ordem=log2(E2n/Enmax);
        if(teste1||teste2)
            printf("\nOrdem=%lf (np=%d=>np=%d)\n",ordem,np/2,np);
        E2n=Enmax;
                //RECUPERAÇÃO DA MATRIZ ORIGINAL




        for (i=1; i< np ; i++)
        {
            for(j=1;j<np;j++)
            {
                A[i][j] = A_aux[i][j];
            }
            b[i]=b_aux[i];
        }
















if(teste3||teste5){


        //=============================MGJ=============================//



        printf("\nMetodo de Gauss-Jacobi\n");
        temp=clock();// calcula tempo inicial

        while(Er>e){
            iteracao++;
            for(i=1;i<=n;i++){
                Xold[i]=Xnew[i]; //Atualiza todos os Xs
                }
            for(i=1;i<=n;i++){//calculo das somas
                for(j=1;j<i;j++){
                    soma=soma+A[i][j]*Xold[j];
                }
                for(j=1+i;j<=n;j++){
                    soma=soma+A[i][j]*Xold[j];
                }
                Xnew[i]=(1.0/A[i][i])*(b[i]-soma);//calculando os novos Xs
                soma=0.0;
            }

            for(i=1;i<=n;i++){
                numerador=numerador+(Xnew[i]-Xold[i])*(Xnew[i]-Xold[i]);//numerador do erro
                denominador=denominador+Xnew[i]*Xnew[i];//denominador do erro
            }
            Er=sqrt(numerador/denominador);//Erro relativo da normal euclidiana
            numerador=0.0;
            denominador=0.0;
        }

        u[0]=(2.0*h*va-4.0*alfa2*Xnew[1]+alfa2*Xnew[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
        u[np]=(2.0*h*vb+4.0*beta2*Xnew[np-1]-beta2*Xnew[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final

            printf("Solucao do sistema\n");
            printf("x0 = %lf\n",u[0]);
            if(teste3||teste5)
                fprintf(arqs,"MGJ\n");
                fprintf(arqs,"%lf\n",u[0]);
        for(i=1;i<=n;i++){
            printf("x%d = %lf\n",i,Xnew[i]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",Xnew[i]);

        }
            printf("x%d = %lf\n",np,u[np]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",u[np]);




        printf("numero de iteracoes = %d\n",iteracao);
        temp=clock()-temp;//diferenca do tempo inicial com o final
        printf("Tempo = %e\n",((float)temp)/CLOCKS_PER_SEC);

        Er=10.0;
        soma=0;
        iteracao=0;
        denominador=0;
        numerador=0;
        for(i=1;i<=n;i++){
            Xnew[i]=0.0;//zera o vetor inicial
        }





















        //=============================MGS=============================//

        printf("\nMetodo de Gauss-Seidel\n");
        temp=clock();//calcula o tempo inicial
        while(Er>e){
            iteracao++;
            for(i=1;i<=n;i++){
                Xold[i]=Xnew[i]; //Atualiza todos os Xs
                }
            for(i=1;i<=n;i++){//calculo das somas
                for(j=1;j<i;j++){
                    soma=soma+A[i][j]*Xnew[j];
                }
                for(j=1+i;j<=n;j++){
                    soma=soma+A[i][j]*Xold[j];
                }
                Xnew[i]=(1/A[i][i])*(b[i]-soma);//calculando os novos Xs
                soma=0.0;
            }

            for(i=1;i<=n;i++){
                numerador=numerador+(Xnew[i]-Xold[i])*(Xnew[i]-Xold[i]);//numerador do erro
                denominador=denominador+Xnew[i]*Xnew[i];//denominador do erro
            }
            Er=sqrt(numerador/denominador);//Erro relativo da normal euclidiana
            numerador=0.0;
            denominador=0.0;
        }
        u[0]=(2.0*h*va-4.0*alfa2*Xnew[1]+alfa2*Xnew[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
        u[np]=(2.0*h*vb+4.0*beta2*Xnew[np-1]-beta2*Xnew[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final

            printf("Solucao do sistema\n");
            printf("x0 = %lf\n",u[0]);
            if(teste3||teste5)
                fprintf(arqs,"MGS\n");
                fprintf(arqs,"%lf\n",u[0]);
        for(i=1;i<=n;i++){
            printf("x%d = %lf\n",i,Xnew[i]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",Xnew[i]);

        }
            printf("x%d = %lf\n",np,u[np]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",u[np]);


        printf("numero de iteracoes = %d\n",iteracao);
        temp=clock()-temp;//diferenca do tempo inicial com o final
        printf("Tempo = %e\n",((float)temp)/CLOCKS_PER_SEC);


        Er=10.0;
        soma=0;
        iteracao=0;
        denominador=0;
        numerador=0;
        for(i=1;i<=n;i++){
            Xnew[i]=0.0;//zera o vetor inicial
        }

























        //=============================SOR=============================//

        printf("\nMetodo de Sobre relaxacao sucessiva\n");
        temp=clock();// calcula o tempo inicial

        double w=1.92;// w do SOR

        while(Er>e){
            iteracao++;
            for(i=1;i<=n;i++){
                Xold[i]=Xnew[i]; //Atualiza todos os Xs
                }
            for(i=1;i<=n;i++){//calculo das somas
                for(j=1;j<i;j++){
                    soma=soma+A[i][j]*Xnew[j];
                }
                for(j=1+i;j<=n;j++){
                    soma=soma+A[i][j]*Xold[j];
                }
                Xnew[i]=(1-w)*Xold[i]+(w/A[i][i])*(b[i]-soma);//calculando os novos Xs
                soma=0.0;
            }

            for(i=1;i<=n;i++){
                numerador=numerador+(Xnew[i]-Xold[i])*(Xnew[i]-Xold[i]);//numerador do erro
                denominador=denominador+Xnew[i]*Xnew[i];//denominador do erro
            }
            Er=sqrt(numerador/denominador);//Erro relativo da normal euclidiana
            numerador=0.0;
            denominador=0.0;
        }
        u[0]=(2.0*h*va-4.0*alfa2*Xnew[1]+alfa2*Xnew[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
        u[np]=(2.0*h*vb+4.0*beta2*Xnew[np-1]-beta2*Xnew[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final

            printf("Solucao do sistema\n");
            printf("x0 = %lf\n",u[0]);
            if(teste3||teste5)
                fprintf(arqs,"SOR\n");
                fprintf(arqs,"%lf\n",u[0]);
        for(i=1;i<=n;i++){
            printf("x%d = %lf\n",i,Xnew[i]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",Xnew[i]);

        }
            printf("x%d = %lf\n",np,u[np]);
            if(teste3||teste5)
                fprintf(arqs,"%lf\n",u[np]);


        printf("numero de iteracoes = %d\n",iteracao);
        temp=clock()-temp;//diferenca do tempo inicial com o final
        printf("Tempo = %e\n",((float)temp)/CLOCKS_PER_SEC);


}}
////////////////////////////////////////////////////////W IDEAL PARA O SOR/////////////////////////////////////////////////////////

if(teste4){

        double w;// w do SOR
        double w_otimizado=0;// w que dara o menor numero de iteracoes
        int iteracao_min=99999999;
        for (w=0.01;w<2;w=w+0.01){
            printf("\nMetodo de Sobre relaxacao sucessiva\n");
            temp=clock();// ca  calcula o tempo inicial

            Er=10.0;
            soma=0;
            iteracao=0;
            denominador=0;
            numerador=0;
            for(i=1;i<=n;i++){
                Xnew[i]=0.0;//zera o vetor inicial
            }


            while(Er>e){
                iteracao++;
                for(i=1;i<=n;i++){
                    Xold[i]=Xnew[i]; //Atualiza todos os Xs
                    }
                for(i=1;i<=n;i++){//calculo das somas
                    for(j=1;j<i;j++){
                        soma=soma+A[i][j]*Xnew[j];
                    }
                    for(j=1+i;j<=n;j++){
                        soma=soma+A[i][j]*Xold[j];
                    }
                    Xnew[i]=(1-w)*Xold[i]+(w/A[i][i])*(b[i]-soma);//calculando os novos Xs
                    soma=0.0;
                }

                for(i=1;i<=n;i++){
                    numerador=numerador+(Xnew[i]-Xold[i])*(Xnew[i]-Xold[i]);//numerador do erro
                    denominador=denominador+Xnew[i]*Xnew[i];//denominador do erro
                }
                Er=sqrt(numerador/denominador);//Erro relativo da normal euclidiana
                numerador=0.0;
                denominador=0.0;
            }

            u[0]=(2.0*h*va-4.0*alfa2*Xnew[1]+alfa2*Xnew[2])/(2.0*h*alfa1-3.0*alfa2);//calculo condicoes de contorno inicial
            u[np]=(2.0*h*vb+4.0*beta2*Xnew[np-1]-beta2*Xnew[np-2])/(2.0*h*beta1+3*beta2);//calculo condicoes de contorno final
/*
                printf("Solucao do sistema\n");
                printf("x0 = %lf\n",u[0]);
            for(i=1;i<=n;i++){
                printf("x%d = %lf\n",i,Xnew[i]);


            }
                printf("x%d = %lf\n",np,u[np]);
*/
            if (iteracao_min>iteracao){
                iteracao_min=iteracao;
                w_otimizado=w;
            }

            temp=clock()-temp;//diferenca do tempo inicial com o final
            printf("numero de iteracoes = %d\tw=%lf\tTempo = %e\n",iteracao,w,((float)temp)/CLOCKS_PER_SEC);
        }
        printf("w otimizado = %lf\n",w_otimizado);


}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        free(sol_analitica);

        for(c=0;c<np;c++)
            free(A[c]);
        free(A);

        free(u);
        free(b);

        for(c=0;c<np;c++)
            free(A_aux[c]);
        free(A_aux);

        free(b_aux);

        free(Xold);
        free(Xnew);
        free(x);

        if(teste3||teste4)
            {
            fclose(arq);
            break;

            }
        if(teste5)
            break;
        if(teste5||teste3)
            fclose(arqs);


        np=np*2;

        }


    system("pause");




    return 0;
}

