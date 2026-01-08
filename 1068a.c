#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char itens[1005];
    int topo;
} Pilha;


void inicializar(Pilha *p) {
    p->topo = -1;
}


int esta_vazia(Pilha *p) {
    if (p->topo == -1) {
        return 1; 
    }
    return 0; 
}


void empilhar(Pilha *p, char caractere) {
   
    p->topo++;
    p->itens[p->topo] = caractere;
}


void desempilhar(Pilha *p) {
    if (esta_vazia(p) == 0) {
        p->topo--;
    }
}


int verificar_parenteses(char *expressao) {
    Pilha p;
    inicializar(&p); // endereco da pilha

    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];

        if (atual == '(') {
            empilhar(&p, '(');
        }
        else if (atual == ')') {
            
            if (esta_vazia(&p)) {
                return 0; 
            }
            // se tem par, remove da pilha
            desempilhar(&p);
        }
    }

    // no final, a pilha deve estar vazia para ser correto
    return esta_vazia(&p);
}

int main() {
    char entrada[1005];

    
    while (fgets(entrada, 1005, stdin) != NULL) {
        
        
        if (verificar_parenteses(entrada)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
