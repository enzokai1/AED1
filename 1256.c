#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir(No **tabela, int chave, int m) {
    int indice = chave % m;
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = chave;
    novo->prox = NULL;

    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        No *atual = tabela[indice];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int main() {
    int n, m, c, chave;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        if (i > 0) printf("\n");
        
        scanf("%d %d", &m, &c);
        
        No **tabela = (No **)malloc(m * sizeof(No *));
        for (int j = 0; j < m; j++) {
            tabela[j] = NULL;
        }
        
        for (int j = 0; j < c; j++) {
            scanf("%d", &chave);
            inserir(tabela, chave, m);
        }
        
        for (int j = 0; j < m; j++) {
            printf("%d -> ", j);
            No *atual = tabela[j];
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
            printf("\\\n");
        }
        
        free(tabela);
    }
    
    return 0;
}
