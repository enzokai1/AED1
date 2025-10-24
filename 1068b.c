#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
    char caractere;
    struct No* proximo;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

int estaVazia(Pilha *p) {
    return (p->topo == NULL);
}

void empilhar(Pilha *p, char c) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo) {
        novoNo->caractere = c;
        novoNo->proximo = p->topo;
        p->topo = novoNo;
    }
}

void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        No* temp = p->topo;
        p->topo = p->topo->proximo;
        free(temp);
    }
}

void destruirPilha(Pilha* p) {
    while (!estaVazia(p)) {
        desempilhar(p);
    }
}

int verificarParenteses(char* expressao) {
    Pilha p;
    inicializarPilha(&p);

    for (int i = 0; expressao[i] != '\0'; i++) {
        
        if (expressao[i] == '(') {
            empilhar(&p, '(');
            
        } else if (expressao[i] == ')') {
            
            if (estaVazia(&p)) {
                destruirPilha(&p); 
                return 0;
            } else {
                desempilhar(&p);
            }
        }
    }

    int resultado = estaVazia(&p);
    
    destruirPilha(&p);
    
    return resultado;
}

int main() {
    char expressao[1002]; 

    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        
        expressao[strcspn(expressao, "\n")] = '\0';

        if (verificarParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
