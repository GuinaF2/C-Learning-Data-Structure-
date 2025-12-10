#include <stdio.h>
#include <stdlib.h>

void main()

{
   NumeroNoVetor();
}

void NumeroNoVetor(){  //4º Exercicio Completo

    int numerosVetor[10]={1,2,3,4,5,6,7,8,9,10};
    int UsuarioNumero=0;
    
    int i=0;
   
    printf("Insira um numero para verificar se ele esta presente no vetor: ");
    scanf("%d",&UsuarioNumero);

    for(i=0;i<sizeof(numerosVetor)/sizeof(numerosVetor[0]);i++)
    {
        if(numerosVetor[i]==UsuarioNumero){
            printf("O numero digitado se encontra na posicao %d do vetor\n",i);
            break;
        }
        if(i==9){
        printf("Nao encontrado \n");
        }
    }
}

