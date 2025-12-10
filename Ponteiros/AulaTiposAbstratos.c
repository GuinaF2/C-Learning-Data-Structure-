#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[5]={0,0,0,0,0};

   for(int *pont=vetor;pont<vetor+5;pont++){
    printf("Insira um novo numero\n");
    scanf("%d",&*pont);
   }
   for (int *pont=vetor;pont<vetor + 5;pont++)
   {
    printf("O numero eh %d\n",*pont);
   }
   

   return 0;
}
