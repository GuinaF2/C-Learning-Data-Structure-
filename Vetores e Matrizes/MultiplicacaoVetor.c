#include <stdio.h>
#include <stdlib.h>

void main()

{
   MultVetor();
}

void MultVetor(){ //6º Exercicio Completo
    int VetorNumeros[10]={4,-11,42,0,1,10,9,5,10,89};

    int NumeroMultiplicador=0;
    int ResultadoMultiplicacao=0; 


    int i=0;
   
    printf("Insira um numero para multiplicar pelos elementos do Vetor: ");
    scanf("%d",&NumeroMultiplicador);

    for(i=0;i<sizeof(VetorNumeros)/sizeof(VetorNumeros[0]);i++)
    {
           ResultadoMultiplicacao=NumeroMultiplicador*VetorNumeros[i];
           printf("%d X %d = %d \n",NumeroMultiplicador,VetorNumeros[i],ResultadoMultiplicacao);
    }

}

