#include <stdio.h>
#include <string.h>


char pilha[1005];
int topo; 
void inicializar_pilha() {
    topo = -1; 
}

void empilhar(char c) {
    topo++;
    pilha[topo] = c;
}

void desempilhar() {
    if (topo != -1) {
        topo--;
    }
}

int pilha_vazia() {
    if (topo == -1) return 1;
    else return 0;
}

int verificar_expressao(char* expressao) {
    inicializar_pilha();

    for (int i = 0; expressao[i] != '\0'; i++) {
        
        // se for abre parenteses, joga na pilha
        if (expressao[i] == '(') {
            empilhar('(');
        }
        //se for fecha parenteses
        else if (expressao[i] == ')') {
           
            if (pilha_vazia()) {
                return 0; // incorreto
            }
            
            desempilhar();
        }
        
    }

    // se sobrou algo na pilha é porque abriu e não fechou
    if (pilha_vazia()) {
        return 1; // correto
    } else {
        return 0; // incorreto
    }
}

int main() {
    char expressao[1005];

    
    while (fgets(expressao, 1005, stdin) != NULL) {
        
        if (verificar_expressao(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
