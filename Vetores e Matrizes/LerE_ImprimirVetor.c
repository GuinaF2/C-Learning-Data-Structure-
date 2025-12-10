#include <stdio.h>
#include <stdlib.h>

void main()
{
   LerVetor();
}

void LerVetor(){  //1º Exercicio Completo

    int numerosUser[5]={};
    
    int i=0;

    for(i=0;i<sizeof(numerosUser)/sizeof(numerosUser[0]);i++)
    {
        printf("Insira um Numero: ");
        scanf("%d",&numerosUser[i]);
    }
    for(i=0;i<sizeof(numerosUser)/sizeof(numerosUser[0]);i++)
    {
        printf("O Numero %d foi: %d \n",i+1,numerosUser[i]);
    }
}

