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

int contarDiamantes(char* mina) {
    inicializarPilha();
    int diamantes = 0;

    for (int i = 0; mina[i] != '\0'; i++) {
        
        if (mina[i] == '<') {
            empilhar('<');
            
        } else if (mina[i] == '>') {
            
            if (!estaVazia()) {
                desempilhar();
                diamantes++;
            }
        }
    }
    
    return diamantes;
}

int main() {
    int N;
    scanf("%d", &N);
    
    getchar(); 

    char mina[MAX_TAM + 2]; 

    for (int i = 0; i < N; i++) {
        fgets(mina, sizeof(mina), stdin);
        
        mina[strcspn(mina, "\n")] = '\0';

        printf("%d\n", contarDiamantes(mina));
    }

    return 0;
}
