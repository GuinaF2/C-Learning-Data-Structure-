#include <stdio.h>
#include <stdlib.h>

void main()

{
   VetorEscalar();
}

void VetorEscalar(){    //AntePenultimo Exercicio Completo
    int VetorA[10]={1,-5,4,12,0,50,-12,29,8,10};
    int VetorB[10]={1,0,4,-5,3,40,25,-10,5,28};

    int ResultadoEscalar=0; 

    int i=0;

    for(i=0;i<sizeof(VetorA)/sizeof(VetorA[0]);i++)
    {
           ResultadoEscalar+=VetorA[i]*VetorB[i];
    }
    printf("O produto escalar eh %d \n",ResultadoEscalar);

}

