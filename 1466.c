#include <stdio.h>
#include <stdlib.h> 

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};


struct No* criar_no(int v) {
    
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    
    novo->valor = v;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

struct No* inserir(struct No* raiz, int v) {
    
    if (raiz == NULL) {
        return criar_no(v);
    }
    
    
    if (v < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, v);
    }
    
    else {
        raiz->direita = inserir(raiz->direita, v);
    }
    
    return raiz;
}


void imprimir_por_nivel(struct No* raiz) {
    if (raiz == NULL) return;
    
    
    struct No* fila[505];
    int inicio = 0;
    int fim = 0;
    
    // enfileira a raiz
    fila[fim] = raiz;
    fim++;
    
    int primeiro = 1; 
    
    while (inicio < fim) {
        // desenfileira
        struct No* atual = fila[inicio];
        inicio++;
        
        if (primeiro == 0) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        
        // enfileira filhos se existirem
        if (atual->esquerda != NULL) {
            fila[fim] = atual->esquerda;
            fim++;
        }
        if (atual->direita != NULL) {
            fila[fim] = atual->direita;
            fim++;
        }
    }
}


void liberar_arvore(struct No* raiz) {
    if (raiz == NULL) return;
    
    liberar_arvore(raiz->esquerda); 
    liberar_arvore(raiz->direita);  
    free(raiz);                     
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int i = 1; i <= casos_teste; i++) {
        int n;
        scanf("%d", &n);
        
        struct No* raiz = NULL; 
        
        for (int j = 0; j < n; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        imprimir_por_nivel(raiz);
        printf("\n\n");

        
        liberar_arvore(raiz);
    }

    return 0;
}
