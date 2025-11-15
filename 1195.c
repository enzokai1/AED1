#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1); 
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void imprimirPreOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf(" %d", raiz->valor);
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimirEmOrdem(raiz->esquerda);
    printf(" %d", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

void imprimirPosOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf(" %d", raiz->valor);
}


int main() {
    int C; 
    scanf("%d", &C);

    for (int i = 1; i <= C; i++) {
        int N; 
        scanf("%d", &N);

        No* raiz = NULL; 
        
        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);

        printf("Pre.:");
        imprimirPreOrdem(raiz);
        printf("\n");

        printf("In..:");
        imprimirEmOrdem(raiz);
        printf("\n");

        printf("Post:");
        imprimirPosOrdem(raiz);
        printf("\n");

        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
