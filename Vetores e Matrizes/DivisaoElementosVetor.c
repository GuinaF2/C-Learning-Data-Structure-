#include <stdio.h>
#include <stdlib.h>

void main()

{
   DivisaoVetores();
}
void DivisaoVetores(){ //Penultimo Exercicio Completo 

    float DividendoVetor[10]={1,-10,2,58,0,543,-4,10,-27,42};
    float DivisorVetor[10]={0,10,-5,0,41,2,1,40,9,10};
    float ResultadoDivisao=0; 
    int i=0;

    for(i=0;i<sizeof(DividendoVetor)/sizeof(DividendoVetor[0]);i++)
    {
        if(DivisorVetor[i]!=0 && DividendoVetor[i]!=0){
            ResultadoDivisao= DividendoVetor[i] / DivisorVetor[i]; 
            printf("A divisao de %.2f por %.2f eh: %.2f \n",DividendoVetor[i],DivisorVetor[i],ResultadoDivisao);
        }
        else if(DividendoVetor[i]==0){
            printf("A divisao de %.0f por %.1f eh: %.0f \n",DividendoVetor[i],DivisorVetor[i],DividendoVetor[i]);
        }
        else{
            printf("Nao eh possivel dividir %.1f por 0 \n",DividendoVetor[i]);
        }
    }
}
