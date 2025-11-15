#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1); 
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, char valor) {
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

int pesquisar(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0; 
    }
    
    if (raiz->valor == valor) {
        return 1; 
    }
    
    if (valor < raiz->valor) {
        return pesquisar(raiz->esquerda, valor);
    } else {
        return pesquisar(raiz->direita, valor);
    }
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void imprimirPreOrdem(No* raiz, int* ehPrimeiro) {
    if (raiz == NULL) {
        return;
    }

    if (*ehPrimeiro) {
        printf("%c", raiz->valor);
        *ehPrimeiro = 0; 
    } else {
        printf(" %c", raiz->valor); 
    }
    imprimirPreOrdem(raiz->esquerda, ehPrimeiro);
    imprimirPreOrdem(raiz->direita, ehPrimeiro);
}

void imprimirEmOrdem(No* raiz, int* ehPrimeiro) {
    if (raiz == NULL) {
        return;
    }

    imprimirEmOrdem(raiz->esquerda, ehPrimeiro);
    
    if (*ehPrimeiro) {
        printf("%c", raiz->valor);
        *ehPrimeiro = 0;
    } else {
        printf(" %c", raiz->valor);
    }
    
    imprimirEmOrdem(raiz->direita, ehPrimeiro);
}

void imprimirPosOrdem(No* raiz, int* ehPrimeiro) {
    if (raiz == NULL) {
        return;
    }

    imprimirPosOrdem(raiz->esquerda, ehPrimeiro);
    imprimirPosOrdem(raiz->direita, ehPrimeiro);
    
    if (*ehPrimeiro) {
        printf("%c", raiz->valor);
        *ehPrimeiro = 0;
    } else {
        printf(" %c", raiz->valor);
    }
}

int main() {
    No* raiz = NULL;
    char comando[20];
    char valor;

    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor); 
            raiz = inserir(raiz, valor);
        
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }

        } else if (strcmp(comando, "INFIXA") == 0) {
            int ehPrimeiro = 1; 
            imprimirEmOrdem(raiz, &ehPrimeiro);
            printf("\n");

        } else if (strcmp(comando, "PREFIXA") == 0) {
            int ehPrimeiro = 1; 
            imprimirPreOrdem(raiz, &ehPrimeiro);
            printf("\n");

        } else if (strcmp(comando, "POSFIXA") == 0) {
            int ehPrimeiro = 1; 
            imprimirPosOrdem(raiz, &ehPrimeiro);
            printf("\n");
        }
    }

    liberarArvore(raiz);
    return 0;
}
