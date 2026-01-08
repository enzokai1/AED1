#include <stdio.h>
#include <stdlib.h>

//pilha estatica
typedef struct {
    int vagoes[1005];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    if (p->topo == -1) return 1;
    return 0;
}

void empilhar(Pilha *p, int vagao) {
    p->topo++;
    p->vagoes[p->topo] = vagao;
}

void desempilhar(Pilha *p) {
    if (!esta_vazia(p)) {
        p->topo--;
    }
}

int ver_topo(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->vagoes[p->topo];
    }
    return -1; //erro ou pilha vazia
}

int main() {
    int n;
    int vetor_saida[1005];

    
    while (scanf("%d", &n) == 1 && n != 0) {
        
        
        while (1) {
            
            scanf("%d", &vetor_saida[0]);
            
            
            if (vetor_saida[0] == 0) {
                printf("\n"); 
                break;
            }
            
           
            for (int i = 1; i < n; i++) {
                scanf("%d", &vetor_saida[i]);
            }
            
            
            Pilha estacao;
            inicializar(&estacao);
            
            int vagao_que_chega = 1; 
            int indice_saida = 0;    // pra saber qual vagao despachar
            
            
            while (vagao_que_chega <= n) {
                
                
                empilhar(&estacao, vagao_que_chega);
                vagao_que_chega++;
                
               
                while (!esta_vazia(&estacao) && ver_topo(&estacao) == vetor_saida[indice_saida]) {
                    desempilhar(&estacao); 
                    indice_saida++;       
                }
            }
            
            
            if (esta_vazia(&estacao)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}
