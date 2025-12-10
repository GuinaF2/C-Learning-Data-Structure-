#include <stdio.h>
#include <stdlib.h>

typedef struct NodeAVL
{
    int valor;
    struct NodeAVL *esquerda;
    struct NodeAVL *direita;
    int altura;
} NodeAVL;

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

// Função para percorrer em pré-ordem
void preorder(NodeAVL *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preorder(raiz->esquerda);
        preorder(raiz->direita);
    }
}

// Função para contar nós
int contarNos(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

// Função para contar folhas
int contarFolhas(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

// Função para somar todos os valores
int somaTodos(NodeAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    return raiz->valor + somaTodos(raiz->esquerda) + somaTodos(raiz->direita);
}

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

int main()
{
    int tipo_arvore = 0;
    char op;
    printf("Escolha o tipo de arvore:\n");
    printf("1. BST\n");
    printf("2. AVL\n");
    scanf("%d", &tipo_arvore);

    if (tipo_arvore == 1)
    {
        // BST
        Node *raiz = NULL;
        int valor;
        do
        {
            printf("\nMenu BST:\n");
            printf("1. Inserir\n2. Remover\n3. Buscar\n4. Inorder\n5. Preorder\n6. Altura\n7. Total de Nos\n8. Total de Folhas\n9. Soma\n0. Sair\n");
            scanf(" %c", &op);
            switch (op)
            {
            case '1':
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case '2':
                printf("Valor para remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case '3':
                printf("Valor para buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor))
                    printf("Encontrado!\n");
                else
                    printf("Nao encontrado.\n");
                break;
            case '4':
                printf("Inorder: ");
                inorder(raiz);
                printf("\n");
                break;
            case '5':
                printf("Preorder: ");
                preorder(raiz);
                printf("\n");
                break;
            case '6':
                printf("Altura: %d\n", altura(raiz));
                break;
            case '7':
                printf("Total de nos: %d\n", contarNos(raiz));
                break;
            case '8':
                printf("Total de folhas: %d\n", contarFolhas(raiz));
                break;
            case '9':
                printf("Soma: %d\n", somaTodos(raiz));
                break;
            }
        } while (op != '0');
    }
    else if (tipo_arvore == 2)
    {
        // AVL
        NodeAVL *raiz = NULL;
        int valor;
        do
        {
            printf("\nMenu AVL:\n");
            printf("1. Inserir\n2. Inorder\n3. Preorder\n4. Altura\n5. Total de Nos\n6. Total de Folhas\n7. Soma\n0. Sair\n");
            scanf(" %c", &op);
            switch (op)
            {
            case '1':
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserirAVL(raiz, valor);
                break;
            case '2':
                printf("Inorder: ");
                inorder(raiz);
                printf("\n");
                break;
            case '3':
                printf("Preorder: ");
                preorder(raiz);
                printf("\n");
                break;
            case '4':
                printf("Altura: %d\n", getAltura(raiz));
                break;
            case '5':
                printf("Total de nos: %d\n", contarNos(raiz));
                break;
            case '6':
                printf("Total de folhas: %d\n", contarFolhas(raiz));
                break;
            case '7':
                printf("Soma: %d\n", somaTodos(raiz));
                break;
            }
        } while (op != '0');
    }
    else
    {
        printf("Opcao invalida!\n");
    }
    return 0;
}