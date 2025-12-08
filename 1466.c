#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criar(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criar(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void bfs(No* raiz) {
    if (raiz == NULL) return;
    
    No* fila[505];
    int inicio = 0, fim = 0;
    
    fila[fim++] = raiz;
    int primeiro = 1;
    
    while (inicio < fim) {
        No* atual = fila[inicio++];
        
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        
        if (atual->esq) fila[fim++] = atual->esq;
        if (atual->dir) fila[fim++] = atual->dir;
    }
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n, valor;
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        No* raiz = NULL;

        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        bfs(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
