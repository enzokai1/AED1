#include <stdio.h>
#include <stdlib.h> 

struct No {
    int numero;
    struct No *proximo;
};


struct No* criar_no(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->numero = valor;
    novo->proximo = NULL;
    return novo;
}


void inserir_na_tabela(struct No **tabela, int tamanho, int valor) {
    
    int indice = valor % tamanho;
    
    struct No* novo_no = criar_no(valor);

    // tabela está vazia
    if (tabela[indice] == NULL) {
        tabela[indice] = novo_no;
    } 
    //se tem gente la vai para o fim da lista
    else {
        struct No* atual = tabela[indice];
        
       
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        
        
        atual->proximo = novo_no;
    }
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int i = 0; i < casos_teste; i++) {
        
        if (i > 0) {
            printf("\n");
        }

        int m_tamanho, c_chaves;
        scanf("%d %d", &m_tamanho, &c_chaves);

        //alocando dinamicamente
        struct No **tabela_hash = (struct No **) malloc(m_tamanho * sizeof(struct No *));

        
        for (int j = 0; j < m_tamanho; j++) {
            tabela_hash[j] = NULL;
        }

        
        for (int j = 0; j < c_chaves; j++) {
            int valor;
            scanf("%d", &valor);
            inserir_na_tabela(tabela_hash, m_tamanho, valor);
        }

        
        for (int j = 0; j < m_tamanho; j++) {
            printf("%d -> ", j);
            
            struct No *atual = tabela_hash[j];
            
            while (atual != NULL) {
                printf("%d -> ", atual->numero);
                
                
                struct No *temp = atual;
                atual = atual->proximo; 
                free(temp); 
            }
            
            
            printf("\\\n");
        }

        
        free(tabela_hash);
    }

    return 0;
}
