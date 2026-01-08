#include <stdio.h>
#include <string.h>


char pilha[1005];
int topo;

void iniciar_pilha() {
    topo = -1; // pilha vazia
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

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    
    
    getchar();

    char linha[1005];

    for (int k = 0; k < casos_teste; k++) {
        
        fgets(linha, 1005, stdin);
        
        iniciar_pilha();
        int diamantes = 0;

        
        for (int i = 0; linha[i] != '\0'; i++) {
            
            // se achou uma metade esquerda do diamante
            if (linha[i] == '<') {
                empilhar('<');
            }
            
            // Se achou uma metade direita
            else if (linha[i] == '>') {
                
                if (topo != -1) {
                    desempilhar(); 
                    diamantes++;   // forma um par
                }
            }
            
            
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
