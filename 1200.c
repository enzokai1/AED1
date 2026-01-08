#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct No {
    char letra;
    struct No *esquerda;
    struct No *direita;
};


struct No* criar_no(char c) {
    
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    
   
    novo->letra = c;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

// arvore binaria de pesquisa
struct No* inserir(struct No* raiz, char c) {
    
    if (raiz == NULL) {
        return criar_no(c);
    }

    // se a letra for menor, vai para a esquerda
    if (c < raiz->letra) {
        raiz->esquerda = inserir(raiz->esquerda, c);
    }
    // se for maior, vai para a direita
    else {
        raiz->direita = inserir(raiz->direita, c);
    }

    return raiz;
}


int buscar(struct No* raiz, char c) {
    if (raiz == NULL) {
        return 0; 
    }

    if (raiz->letra == c) {
        return 1; 
    }

    
    if (c < raiz->letra) {
        return buscar(raiz->esquerda, c);
    } else {
        return buscar(raiz->direita, c);
    }
}


void prefixa(struct No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    if (*primeiro == 1) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }

    prefixa(raiz->esquerda, primeiro);
    prefixa(raiz->direita, primeiro);
}


void infixa(struct No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    infixa(raiz->esquerda, primeiro);

    if (*primeiro == 1) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }

    infixa(raiz->direita, primeiro);
}


void posfixa(struct No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    posfixa(raiz->esquerda, primeiro);
    posfixa(raiz->direita, primeiro);

    if (*primeiro == 1) {
        printf("%c", raiz->letra);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->letra);
    }
}


void liberar_arvore(struct No* raiz) {
    if (raiz == NULL) return;
    
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

int main() {
    struct No* raiz = NULL;
    char comando[50];
    char letra;

    
    while (scanf("%s", comando) == 1) {
        
        
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra); 
            raiz = inserir(raiz, letra);
        }
        
        
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra)) {
                printf("%c existe\n", letra);
            } else {
                printf("%c nao existe\n", letra);
            }
        }
        
        
        else {
            int flag_primeiro = 1; 
            
            if (strcmp(comando, "PREFIXA") == 0) {
                prefixa(raiz, &flag_primeiro);
            } 
            else if (strcmp(comando, "INFIXA") == 0) {
                infixa(raiz, &flag_primeiro);
            } 
            else if (strcmp(comando, "POSFIXA") == 0) {
                posfixa(raiz, &flag_primeiro);
            }
            
            printf("\n"); 
        }
    }

    
    liberar_arvore(raiz);
    
    return 0;
}
