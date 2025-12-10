#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Funções BST
typedef struct Node
{
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node *criarNo(int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

typedef struct
{
    Node *raiz;
} ArvoreBST;

void inicializarArvore(ArvoreBST *arvore)
{
    arvore->raiz = NULL;
}

Node *buscar(Node *raiz, int valor)
{
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

Node *inserir(Node *raiz, int valor)
{
    if (raiz == NULL)
        return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

int altura(Node *raiz)
{
    if (raiz == NULL)
        return -1;
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

// Impressão visual para BST
void printArvore(Node *raiz, int espaco, char barra)
{
    if (raiz == NULL)
        return;

    espaco += 6;

    printArvore(raiz->direita, espaco, '/');

    printf("\n");
    for (int i = 6; i < espaco; i++)
        printf(" ");
    if (barra)
        printf("%c", barra);
    printf("%d\n", raiz->valor);

    printArvore(raiz->esquerda, espaco, '\\');
}

Node *menorValor(Node *raiz)
{
    Node *atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

Node *remover(Node *raiz, int valor)
{
    if (raiz == NULL)
        return NULL;
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else
    {
        if (raiz->esquerda == NULL)
        {
            Node *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            Node *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Node *temp = menorValor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// FUNÇÕES AVL
typedef struct NodeAVL
{
    int valor;
    struct NodeAVL *esquerda;
    struct NodeAVL *direita;
    int altura;
} NodeAVL;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Função para obter a altura de um nó
int getAltura(NodeAVL *n)
{
    if (n == NULL)
        return -1;
    return n->altura;
}

// Função para obter o fator de balanceamento
int getFator(NodeAVL *n)
{
    if (n == NULL)
        return 0;
    return getAltura(n->esquerda) - getAltura(n->direita);
}

// Função para atualizar a altura de um nó
void atualizarAltura(NodeAVL *n)
{
    int altE = getAltura(n->esquerda);
    int altD = getAltura(n->direita);
    n->altura = (altE > altD ? altE : altD) + 1;
}

// Rotação simples à direita
NodeAVL *rotacaoDireita(NodeAVL *y)
{
    NodeAVL *x = y->esquerda;
    NodeAVL *T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    atualizarAltura(y);
    atualizarAltura(x);
    return x;
}

// Rotação simples à esquerda
NodeAVL *rotacaoEsquerda(NodeAVL *x)
{
    NodeAVL *y = x->direita;
    NodeAVL *T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    atualizarAltura(x);
    atualizarAltura(y);
    return y;
}

// Impressão visual para AVL
void printArvoreAVL(NodeAVL *raiz, int espaco, char barra)
{
    if (raiz == NULL)
        return;

    espaco += 6;

    printArvoreAVL(raiz->direita, espaco, '/');

    printf("\n");
    for (int i = 6; i < espaco; i++)
        printf(" ");
    if (barra)
        printf("%c", barra);
    printf("%d\n", raiz->valor);

    printArvoreAVL(raiz->esquerda, espaco, '\\');
}

// Função para inserir um valor na AVL
NodeAVL *inserirAVL(NodeAVL *raiz, int valor)
{
    if (raiz == NULL)
    {
        NodeAVL *novo = (NodeAVL *)malloc(sizeof(NodeAVL));
        novo->valor = valor;
        novo->esquerda = novo->direita = NULL;
        novo->altura = 0;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esquerda = inserirAVL(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserirAVL(raiz->direita, valor);
    else
        return raiz; // Não permite valores duplicados

    atualizarAltura(raiz);

    int fator = getFator(raiz);

    // Balanceamento
    // Esquerda Esquerda
    if (fator > 1 && valor < raiz->esquerda->valor)
        return rotacaoDireita(raiz);

    // Direita Direita
    if (fator < -1 && valor > raiz->direita->valor)
        return rotacaoEsquerda(raiz);

    // Esquerda Direita
    if (fator > 1 && valor > raiz->esquerda->valor)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Direita Esquerda
    if (fator < -1 && valor < raiz->direita->valor)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

NodeAVL *menorValorAVL(NodeAVL *raiz)
{
    NodeAVL *atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

NodeAVL *removerAVL(NodeAVL *raiz, int valor)
{
    // Passo 1: Remoção BST padrão
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = removerAVL(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = removerAVL(raiz->direita, valor);
    else
    {
        // Casos de remoção (um ou nenhum filho)
        if (raiz->esquerda == NULL || raiz->direita == NULL)
        {
            NodeAVL *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL)
            { // Sem filhos
                temp = raiz;
                raiz = NULL;
            }
            else // Um filho
                *raiz = *temp;
            free(temp);
        }
        else
        { // Dois filhos
            NodeAVL *temp = menorValorAVL(raiz->direita);
            raiz->valor = temp->valor;
            raiz->direita = removerAVL(raiz->direita, temp->valor);
        }
    }

    // Se a árvore tinha apenas um nó
    if (raiz == NULL)
        return raiz;

    // Passo 2: Atualizar altura
    raiz->altura = 1 + max(getAltura(raiz->esquerda),
                           getAltura(raiz->direita));

    // Passo 3: Rebalancear (mesma lógica da inserção)
    int fator = getFator(raiz);

    // Verificar os 4 casos de rotação
    // Balanceamento
    // Esquerda Esquerda
    if (fator > 1 && valor < raiz->esquerda->valor)
        return rotacaoDireita(raiz);

    // Direita Direita
    if (fator < -1 && valor > raiz->direita->valor)
        return rotacaoEsquerda(raiz);

    // Esquerda Direita
    if (fator > 1 && valor > raiz->esquerda->valor)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Direita Esquerda
    if (fator < -1 && valor < raiz->direita->valor)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

// Função para percorrer em ordem
void inorder(NodeAVL *raiz)
{
    if (raiz != NULL)
    {
        inorder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inorder(raiz->direita);
    }
}

void inorderAVL(NodeAVL *raiz)
{
    if (raiz != NULL)
    {
        inorderAVL(raiz->esquerda);
        printf("%d ", raiz->valor);
        inorderAVL(raiz->direita);
    }
}
// Função para percorrer em pré-ordem
void preorder(Node *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preorder(raiz->esquerda);
        preorder(raiz->direita);
    }
}

void preorderAVL(NodeAVL *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preorderAVL(raiz->esquerda);
        preorderAVL(raiz->direita);
    }
}

// Função para contar nós
int contarNos(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

// Função para contar folhas
int contarFolhas(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int contarNosAVL(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contarNosAVL(raiz->esquerda) + contarNosAVL(raiz->direita);
}

// Função para contar folhas para AVL
int contarFolhasAVL(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contarFolhasAVL(raiz->esquerda) + contarFolhasAVL(raiz->direita);
}
// Função para somar todos os valores
int somaTodos(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    return raiz->valor + somaTodos(raiz->esquerda) + somaTodos(raiz->direita);
}

int somaTodosAVL(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    return raiz->valor + somaTodosAVL(raiz->esquerda) + somaTodosAVL(raiz->direita);
}

int main()
{
    char op;
    int quantidade_nos;
    int *valorNo;
    int tipo_arvore;

    printf("Escolha o tipo da árvore\n");
    printf("1.BST\n2.AVL\n");
    scanf("%d", &tipo_arvore);

    if (tipo_arvore == 1)
    {
        Node *raiz = NULL;
        int valor;
        while (1)
        {
            system("cls");
            printf("ARVORE BST\n");
            printf("Insira a operacao desejada\n");
            printf("1. Inserir No\n2. Buscar No\n3. Remover No\n4. Quantidade Nos\n5. Altura\n6. Somar Valores\n7. Contar Folhas\n8. Inorder\n9. Preorder\n0-Visualizacao da Arvore\n-. Sair\n");
            scanf(" %c", &op);
            switch (op)
            {
            case '1':
                system("cls");
                printf("Insira a quantidade de nos que deseja inserir\n");
                scanf("%d", &quantidade_nos);
                valorNo = (int *)malloc(quantidade_nos * sizeof(int));
                if (valorNo == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    break;
                }
                for (int i = 0; i < quantidade_nos; i++)
                {
                    printf("Insira o valor desejado para o no %d\n", i + 1);
                    scanf("%d", &valorNo[i]);
                    raiz = inserir(raiz, valorNo[i]);
                    system("cls");
                }
                free(valorNo);
                break;
            case '2':
                system("cls");
                printf("Insira um valor para ser buscado\n");
                scanf("%d", &valor);
                Node *busca = buscar(raiz, valor);
                if (busca != NULL)
                {
                    printf("Noh encontrado com valor: %d\n", busca->valor);
                }
                else
                {
                    printf("Noh nao encontrado.\n");
                }
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '3':
                system("cls");
                printf("Insira um valor para ser removido\n");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                printf("Remocao concluida.\n");
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '4':
                system("cls");
                printf("Quantidade de Nos: %d\n", contarNos(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '5':
                system("cls");
                printf("Altura da arvore: %d\n", altura(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '6':
                system("cls");
                printf("Soma de todos os valores: %d\n", somaTodos(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '7':
                system("cls");
                printf("Total de folhas: %d\n", contarFolhas(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '8':
                system("cls");
                printf("Percurso em ordem (inorder): ");
                inorder(raiz);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '9':
                printf("Percurso em pre-ordem (preorder): ");
                preorder(raiz);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '0':
                printf("Visualizacao da arvore:\n");
                printArvore(raiz, 0, 0);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '-':
                exit(0);
                break;
            default:
                break;
            }
        }
    }
    else if (tipo_arvore == 2)
    {
        NodeAVL *raiz = NULL;
        int valor;
        while (1)
        {
            system("cls");
            printf("ARVORE AVL\n");
            printf("Insira a operacao desejada\n");
            printf("1. Inserir AVL\n2. Remover AVL\n3. Quantidade Nos\n4. Altura\n5. Somar Valores\n6. Contar Folhas\n7. Inorder\n8. Preorder\n9. Visualizacao Arvore AVL\n0. Sair\n");
            scanf(" %c", &op);
            switch (op)
            {
            case '1':
                system("cls");
                printf("Insira a quantidade de nos que deseja inserir\n");
                scanf("%d", &quantidade_nos);
                valorNo = (int *)malloc(quantidade_nos * sizeof(int));
                if (valorNo == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    break;
                }
                for (int i = 0; i < quantidade_nos; i++)
                {
                    printf("Insira o valor desejado para o no %d\n", i + 1);
                    scanf("%d", &valorNo[i]);
                    raiz = inserirAVL(raiz, valorNo[i]);
                }
                free(valorNo);
                system("cls");
                break;
            case '2':
                system("cls");
                printf("Insira um valor para ser removido\n");
                scanf("%d", &valor);
                raiz = removerAVL(raiz, valor);
                printf("Remocao concluida.\n");
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '3':
                system("cls");
                printf("Quantidade de Nos: %d\n", contarNosAVL(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '4':
                system("cls");
                printf("Altura da arvore: %d\n", getAltura(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '5':
                system("cls");
                printf("Soma de todos os valores: %d\n", somaTodosAVL(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '6':
                system("cls");
                printf("Total de folhas: %d\n", contarFolhasAVL(raiz));
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '7':
                system("cls");
                printf("Percurso em ordem (inorder): ");
                inorderAVL(raiz);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '8':
                system("cls");
                printf("Percurso em pre-ordem (preorder): ");
                preorderAVL(raiz);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '9':
                system("cls");
                printf("Visualizacao da arvore AVL:\n");
                printArvoreAVL(raiz, 0, 0);
                printf("\nPressione qualquer tecla para voltar...");
                getch();
                fflush(stdin);
                system("cls");
                break;
            case '0':
                exit(0);
                break;
            default:
                break;
            }
        }
    }
    else
    {
        printf("Favor inserir tipo valido\n");
        return 1;
    }
    return 0;
}