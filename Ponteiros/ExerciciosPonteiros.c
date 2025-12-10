

void NumRealChar(){
    int *pontnum, num=1;
    char *pontchar, letra='f';
    float *pontreal,numReal=2.0f;

    printf("VALOR DAS VARIAVEIS ORIGINAIS\n");
    printf("Primeiro valor Inteiro %d \n",num);
    printf("Primeiro valor Char %c \n",letra);
    printf("Primeiro valor Real %f \n\n",numReal);

    //Atribuição do endereço das variaveis ao ponteiro
    pontnum=&num;
    pontchar=&letra;
    pontreal=&numReal;

    *pontnum=3;
    *pontchar='k';
    *pontreal=5.5f;

    printf("VALOR DO PONTEIRO\n");
    printf("Primeiro valor Inteiro %d \n",*pontnum);
    printf("Primeiro valor Char %c \n",*pontchar);
    printf("Primeiro valor Real %f \n\n",*pontreal);
}

void CompararEndereco(){
    int num1=5;
    int num2=3;
    if (&num1>&num2)
    {
        printf("Numero 1 %d maior que %d\n",&num1,&num2);
    }else{
        printf("Numero 2%d maior que %d\n",&num2,&num1);
    }
    
}

void CompararEnderecoTeclado(){
    int num1=0;
    int num2=0;
    printf("Insira um Numero\n");
    scanf("%d",&num1);
    printf("Insira um Numero\n");
    scanf("%d",&num2);
    
    if (&num1>&num2)
    {
        printf("Numero %d maior que %d\n",num1,num2);
    }else{
        printf("Numero %d maior que %d\n",num2,num1);
    }
    
}

int inverteNumeros(numero1,numero2){
    
    int *temp1= numero1;
    int *temp2= numero2;
    printf("%d\n",*temp1);
    printf("%d\n",*temp2);
    //Manipulação dos valores das variaveis
    int *temp3= *temp1;
    *temp1 = *temp2;
    *temp2 = temp3;
    
    return temp1,temp2;
}
void TrocaValores(){
    int num1=0;
    int num2=0;
    printf("Insira um Numero\n");
    scanf("%d",&num1);
    printf("Insira um Numero\n");
    scanf("%d",&num2);
    inverteNumeros(&num1,&num2);
    printf("Valor Primeiro: %d Valor Segundo: %d",num1,num2);
    
}


int main(){
    printf("Exercicio 1\n");
    NumRealChar();
    printf("Exercicio 2\n");
    CompararEndereco();
    printf("Exercicio 3\n");
    CompararEnderecoTeclado();
    printf("Exercicio 4\n");
    TrocaValores();
    return 0;
}
