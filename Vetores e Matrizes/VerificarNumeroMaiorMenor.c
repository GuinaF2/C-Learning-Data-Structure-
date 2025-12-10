#include <stdio.h>
#include <stdlib.h>

void main()

{
   NumeroMaiorOuMenor();
}


void NumeroMaiorOuMenor(){  //3º Exercicio Completo

    float numerosVetor[10]={-10,200.54,30,24,45,-10.1,76,49,47,85};
    float VetorMaior,VetorMenor=numerosVetor[1];
    
    int i=0;
   
    for(i=0;i<sizeof(numerosVetor)/sizeof(numerosVetor[0]);i++)
    {
        if(numerosVetor[i]>VetorMaior){
        VetorMaior=numerosVetor[i];
        }
        if (numerosVetor[i]<VetorMenor)
        {
            VetorMenor=numerosVetor[i];        
        }
    }
    printf("O maior numero presente no Vetor eh: %.2f \n",VetorMaior);
    printf("O menor numero presente no Vetor eh: %.2f \n",VetorMenor);
}
