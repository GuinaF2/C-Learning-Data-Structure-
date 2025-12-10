#include <stdio.h>
#include <stdlib.h>

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

void inorder(Node *raiz)
{
    if (raiz != NULL)
    {
        inorder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inorder(raiz->direita);
    }
}

void preorder(Node *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preorder(raiz->esquerda);
        preorder(raiz->direita);
    }
}

int altura(Node *raiz)
{
    if (raiz == NULL)
        return -1;
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

int contarNos(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int somaTodos(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    return raiz->valor + somaTodos(raiz->esquerda) + somaTodos(raiz->direita);
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

int main(int argc, char const *argv[])
{
    ArvoreBST minhaArvore;
    inicializarArvore(&minhaArvore);

    minhaArvore.raiz = inserir(minhaArvore.raiz, 50);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 30);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 70);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 20);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 40);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 60);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 80);
    minhaArvore.raiz = inserir(minhaArvore.raiz, 55);

    printf("Percurso em ordem (inorder): ");
    inorder(minhaArvore.raiz);
    printf("\n");

    printf("Percurso em ordem (preorder): ");
    preorder(minhaArvore.raiz);
    printf("\n");

    Node *resultado = buscar(minhaArvore.raiz, 10);
    if (resultado != NULL)
        printf("Noh encontrado com valor: %d\n", resultado->valor);
    else
        printf("Noh nao encontrado.\n");

    int h = altura(minhaArvore.raiz);
    printf("Altura da arvore: %d\n", h);

    int totalNos = contarNos(minhaArvore.raiz);
    printf("Total de nos: %d\n", totalNos);

    int totalFolhas = contarFolhas(minhaArvore.raiz);
    printf("Total de folhas: %d\n", totalFolhas);

    int soma = somaTodos(minhaArvore.raiz);
    printf("Soma de todos os valores: %d\n", soma);

    printf("Removendo o nó com valor 70...\n");
    minhaArvore.raiz = remover(minhaArvore.raiz, 70);

    printf("Percurso em ordem (inorder) apos remocao: ");
    inorder(minhaArvore.raiz);
    printf("\n");

    return 0;
}