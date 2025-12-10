#include <stdio.h>
#include <stdlib.h>

typedef struct NodeAVL {
    int valor;
    struct NodeAVL* esquerda;
    struct NodeAVL* direita;
    int altura;
} NodeAVL;

// Função para obter a altura de um nó
int getAltura(NodeAVL* n) {
    if (n == NULL) return -1;
    return n->altura;
}

// Função para obter o fator de balanceamento
int getFator(NodeAVL* n) {
    if (n == NULL) return 0;
    return getAltura(n->esquerda) - getAltura(n->direita);
}

// Função para atualizar a altura de um nó
void atualizarAltura(NodeAVL* n) {
    int altE = getAltura(n->esquerda);
    int altD = getAltura(n->direita);
    n->altura = (altE > altD ? altE : altD) + 1;
}

// Rotação simples à direita
NodeAVL* rotacaoDireita(NodeAVL* y) {
    NodeAVL* x = y->esquerda;
    NodeAVL* T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    atualizarAltura(y);
    atualizarAltura(x);
    return x;
}

// Rotação simples à esquerda
NodeAVL* rotacaoEsquerda(NodeAVL* x) {
    NodeAVL* y = x->direita;
    NodeAVL* T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    atualizarAltura(x);
    atualizarAltura(y);
    return y;
}

// Função para inserir um valor na AVL
NodeAVL* inserirAVL(NodeAVL* raiz, int valor) {
    if (raiz == NULL) {
        NodeAVL* novo = (NodeAVL*)malloc(sizeof(NodeAVL));
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
    if (fator > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Direita Esquerda
    if (fator < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para percorrer em ordem
void inorder(NodeAVL* raiz) {
    if (raiz != NULL) {
        inorder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inorder(raiz->direita);
    }
}

// Função para percorrer em pré-ordem
void preorder(NodeAVL* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preorder(raiz->esquerda);
        preorder(raiz->direita);
    }
}

// Função para contar nós
int contarNos(NodeAVL* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

// Função para contar folhas
int contarFolhas(NodeAVL* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL) return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

// Função para somar todos os valores
int somaTodos(NodeAVL* raiz) {
    if (raiz == NULL) return 0;
    return raiz->valor + somaTodos(raiz->esquerda) + somaTodos(raiz->direita);
}

int main() {
    NodeAVL* raiz = NULL;

    // Inserindo os valores: 10, 5, 7, 15, 18, 20
    raiz = inserirAVL(raiz, 10);
    raiz = inserirAVL(raiz, 20);
    raiz = inserirAVL(raiz, 30);
    raiz = inserirAVL(raiz, 40);
    raiz = inserirAVL(raiz, 50);
    raiz = inserirAVL(raiz, 60);

    printf("Percurso em ordem (inorder): ");
    inorder(raiz);
    printf("\n");

    printf("Percurso em pre-ordem (preorder): ");
    preorder(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", getAltura(raiz));
    printf("Total de nos: %d\n", contarNos(raiz));
    printf("Total de folhas: %d\n", contarFolhas(raiz));
    printf("Soma de todos os valores: %d\n", somaTodos(raiz));

    return 0;
}