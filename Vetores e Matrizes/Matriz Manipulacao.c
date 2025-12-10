#include <stdio.h>

int main(){
    int matriz1[3][3];
    int matriz2[3][3];
    RecebeMatriz(matriz1);
    RecebeMatriz(matriz2);
    SomaMatriz(matriz1,matriz2);
    SubMatriz(matriz1,matriz2);
    multMatriz(matriz1,matriz2);
    MatrizTransposta(matriz1);
    return 0;
}

void SomaMatriz(int mat1[3][3],int mat2[3][3]){
    int i,j;
    int soma[3][3];
    printf("Exercicio 2 Realiza a soma das Matrizes 1 e 2\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            soma[i][j]= mat1[i][j] + mat2[i][j];
            
        }
        
    }
    ImprimeMatriz(soma);
}
void RecebeMatriz(int mat[3][3]){
    int i, j;
    printf("Digite os valores para a matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite um valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}


void ImprimeMatriz(int mat[3][3]){
    int i, j;

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void SubMatriz(int mat1[3][3],int mat2[3][3]){
    int i,j;
    int sub [3][3];
    printf("Exercicio 3 Subtracao elementos Segunda Matriz e Primeira Matriz\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sub[i][j] = mat2[i][j] - mat1[i][j];
          
        }
        
    }
    ImprimeMatriz(sub);
}

void multMatriz(int mat1[3][3],int mat2[3][3]){
    int mult [3][3]={};
    printf("Exercicio 4 Multiplicacao entre Matriz 1 e Matriz 2\n");
        for (int linha = 0; linha < 3; linha++)
        {
            for (int coluna = 0; coluna < 3; coluna++)
            {
                mult[linha][coluna]=0;
                for (int interior = 0; interior < 3; interior++)
                {
                    mult[linha][coluna] += mat1[linha][interior] * mat2[interior][coluna] ;   
                }   
            }
        }
        ImprimeMatriz(mult);
}

void MatrizTransposta(int mat[3][3]){
    int valorinverso;
    printf("Exercicio 5 Matriz Transposta da Matriz 1\n");
              for (int linhainv = 0; linhainv < 3; linhainv++)//3 TERCEIRO FOR
              {
                 for (int colunainv = linhainv+1; colunainv < 3; colunainv++)//4 QUARTO FOR
                 {
                        //Recebe 1-0
                        valorinverso=mat[linhainv][colunainv];
                        mat[linhainv][colunainv] = mat[colunainv][linhainv];
                        mat[colunainv][linhainv] = valorinverso; 
                 }   
             }    
    ImprimeMatriz(mat);
}

