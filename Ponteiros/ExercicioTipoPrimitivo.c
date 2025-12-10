#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main(){
    int num=5;
    float numDeci= 2.0f;
    char caractere="g";

    int *ptrI=&num;
    float *ptrF=&numDeci;
    char *ptrC=&caractere;

    printf("Valor do Inteiro %d",num,"Endereco %p\n",num,(void *)ptrI);
    printf("Valor do Decimal %f",numDeci,"Endereco %p\n",numDeci,(void *)ptrF);
    printf("Valor do Caractere %c",caractere,"Endereco %p\n",caractere,(void *)ptrC);

    *ptrI=100;
    *ptrF=5.0f;
    *ptrC="f";

    printf("Valores depois da modificação\n");
    printf("Valor do Inteiro %d",num,"Endereco %p\n",num,(void*)ptrI);
    printf("Valor do Decimal %f",numDeci,"Endereco %p\n",numDeci,(void*)ptrF);
    printf("Valor do Caractere %c",caractere,"Endereco %p\n",caractere,(void*)ptrC);


    printf("Tamanhos na Memória");
    printf("Valor do Decimal %f",numDeci,"Endereco %p\n",numDeci,(void*)ptrF);
    printf("Valor do Caractere %c",caractere,"Endereco %p\n",caractere,(void*)ptrC);

    return 1;
}
