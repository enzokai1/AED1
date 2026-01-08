#include <stdio.h>
#include <stdlib.h> 

struct No {
    int numero;
    struct No *esquerda;
    struct No *direita;
};


struct No* criar_no(int n) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->numero = n;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}


struct No* inserir(struct No* raiz, int n) {
    if (raiz == NULL) {
        return criar_no(n);
    }

    if (n < raiz->numero) {
        raiz->esquerda = inserir(raiz->esquerda, n);
    } else {
        raiz->direita = inserir(raiz->direita, n);
    }
    
    return raiz;
}


void imprimir_prefixa(struct No* raiz) {
    if (raiz == NULL) return;

    printf(" %d", raiz->numero);
    imprimir_prefixa(raiz->esquerda);
    imprimir_prefixa(raiz->direita);
}

//em ordem
void imprimir_infixa(struct No* raiz) {
    if (raiz == NULL) return;

    imprimir_infixa(raiz->esquerda);
    printf(" %d", raiz->numero);
    imprimir_infixa(raiz->direita);
}

// pos ordem
void imprimir_posfixa(struct No* raiz) {
    if (raiz == NULL) return;

    imprimir_posfixa(raiz->esquerda);
    imprimir_posfixa(raiz->direita);
    printf(" %d", raiz->numero);
}


void destruir_arvore(struct No* raiz) {
    if (raiz == NULL) return;
    
    destruir_arvore(raiz->esquerda);
    destruir_arvore(raiz->direita);
    free(raiz);
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int i = 1; i <= casos_teste; i++) {
        int qtd_numeros;
        scanf("%d", &qtd_numeros);

        struct No* raiz = NULL;
        
        for (int j = 0; j < qtd_numeros; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);

        
        printf("Pre.:");
        imprimir_prefixa(raiz);
        printf("\n");

        printf("In..:");
        imprimir_infixa(raiz);
        printf("\n");

        printf("Post:");
        imprimir_posfixa(raiz);
        printf("\n");
        
        
        printf("\n");

        destruir_arvore(raiz);
    }

    return 0;
}
