#include <stdio.h>
#include <string.h>

#define MAX_TAM 1001 

int pilha[MAX_TAM]; 
int topo;            

void inicializarPilha() {
    topo = -1;
}

int estaVazia() {
    return (topo == -1);
}

void empilhar(int c) {
    topo++;
    pilha[topo] = c;
}

int desempilhar() {
    int val = pilha[topo];
    topo--;
    return val;
}

int verTopo() {
    return pilha[topo];
}

int main() {
    int N;
    int saida_desejada[MAX_TAM];
    
    int primeiroBloco = 1; 

    while (scanf("%d", &N) == 1 && N != 0) {
        
        if (!primeiroBloco) {
            printf("\n");
        }
        primeiroBloco = 0;

        while (1) {
            
            scanf("%d", &saida_desejada[0]);
            
            if (saida_desejada[0] == 0) {
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &saida_desejada[i]);
            }
            
            inicializarPilha();
            int vagao_A = 1;     
            int idx_saida = 0;   
            int possivel = 1;    

            while (idx_saida < N) {
                
                if (!estaVazia() && verTopo() == saida_desejada[idx_saida]) {
                    desempilhar();
                    idx_saida++;
                
                } else if (vagao_A <= N) {
                    
                    if (vagao_A == saida_desejada[idx_saida]) {
                        vagao_A++;
                        idx_saida++;
                    
                    } else {
                        empilhar(vagao_A);
                        vagao_A++;
                    }
                
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    printf("\n");

    return 0;
}
