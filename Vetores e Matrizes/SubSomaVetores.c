#include <stdio.h>
#include <stdlib.h>

void main()

{
   SubOuSoma();
}

void SubOuSoma(){ //5º Exercicio Completo
    
    int VetorSoma[10]={2,3,4,5,6,7,8,9,10,11};
    int VetorSubtracao[10]={-1,-2,0,-4,0,-6,-7,-8,9,10};  

    int SomaTotalVetores=0;
    int SubtracaoTotalVetores=0; 

    int i=0;
   

    for(i=0;i<sizeof(VetorSoma)/sizeof(VetorSoma[0]);i++)
    {
           SomaTotalVetores+=VetorSoma[i];
           SubtracaoTotalVetores-=VetorSubtracao[i];
    }
    printf("A soma de todos os numeros no primeiro vetor eh: %d \n",SomaTotalVetores);
    printf("A subtracao de todos os numeros no segundo vetor eh: %d \n",SubtracaoTotalVetores);
}

