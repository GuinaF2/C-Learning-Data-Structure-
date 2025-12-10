#include <stdio.h>
#include <stdlib.h>

void main()

{
   InverterVetor();
}

void InverterVetor(){   //Ultimo Exercicio Completo

    //                    00 01 02 03 04 
    int VetorOriginal[5]={25,65,32,50,22};

    int i=0;

    int inverso = sizeof(VetorOriginal)/sizeof(VetorOriginal[0]);//Recebe o tamanho total do vetor

    int valor_temp=0;//Variavel que ira segurar o valor do indice antes da mudança

    for(i=0;i<inverso;i++)//Depois do i<inverso começou a funcionar, talvez seja atribuição de valor
    {   
        inverso--;

        valor_temp=VetorOriginal[i];//Pegou valor

        VetorOriginal[i]=VetorOriginal[inverso];//Trocou valor de uma ponta pra outra

        VetorOriginal[inverso]=valor_temp;//Valor pego vai para a ponta final
    }
    for(i=0;i<sizeof(VetorOriginal)/sizeof(VetorOriginal[0]);i++)
    {   
        printf("Posicao %d Valor %d\n",i,VetorOriginal[i]);
    }
    
    

}
    
