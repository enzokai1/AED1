#include <stdio.h>
#include <string.h>

#define MAX_TAM 1001 

char pilha[MAX_TAM]; 
int topo;            

void inicializarPilha() {
    topo = -1;
}

int estaVazia() {
    return (topo == -1);
}

void empilhar(char c) {
    topo++;
    pilha[topo] = c;
}

void desempilhar() {
    topo--;
}

int verificarParenteses(char* expressao) {
    inicializarPilha();

    for (int i = 0; expressao[i] != '\0'; i++) {
        
        if (expressao[i] == '(') {
            empilhar('(');
            
        } else if (expressao[i] == ')') {
            
            if (estaVazia()) {
                return 0; 
            } else {
                desempilhar();
            }
        }
    }

    return estaVazia();
}

int main() {
    char expressao[MAX_TAM + 2]; 

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
