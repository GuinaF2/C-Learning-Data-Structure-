#include <stdio.h>
#include <stdlib.h>

void main()

{
   VetorSoma();
}



void VetorSoma(){  //2º Exercicio Completo

    int numerosVetor[10]={1,2,3,4,5,6,7,8,9,10};
    int SomaVetor=0;
    
    int i=0;
   
    for(i=0;i<sizeof(numerosVetor)/sizeof(numerosVetor[0]);i++)
    {
        SomaVetor+=numerosVetor[i];
    }
    printf("A soma de todos os numeros do Vetor eh: %d \n",SomaVetor);
}
