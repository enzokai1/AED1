#include <stdio.h>
//pilha
int pilha[1005];
int topo_pilha;

// fila
int fila[1005];
int inicio_fila, fim_fila;

// fila de prioridade
int fila_prio[1005];
int tam_prio;

int main() {
    int n;

    
    while (scanf("%d", &n) != EOF) {
        
        
        topo_pilha = 0;
        
        inicio_fila = 0;
        fim_fila = 0;
        
        tam_prio = 0;
        
       // 1 = pode ser essa estrutura, 0 = impossivel
        int pode_ser_pilha = 1;
        int pode_ser_fila = 1;
        int pode_ser_prio = 1;

        for (int i = 0; i < n; i++) {
            int comando, valor;
            scanf("%d %d", &comando, &valor);

            //coloca o valor nas três estruturas
            if (comando == 1) {
                
                if (pode_ser_pilha) {
                    pilha[topo_pilha] = valor;
                    topo_pilha++;
                }

                
                if (pode_ser_fila) {
                    fila[fim_fila] = valor;
                    fim_fila++;
                }

                
                if (pode_ser_prio) {
                    fila_prio[tam_prio] = valor;
                    tam_prio++;
                }
            }
            
            // vejo se o valor tirado faz sentido com a logica
            else {
                
                if (pode_ser_pilha) {
                    
                    if (topo_pilha == 0 || pilha[topo_pilha - 1] != valor) {
                        pode_ser_pilha = 0; 
                    } else {
                        topo_pilha--; 
                    }
                }

                
                if (pode_ser_fila) {
                    
                    if (inicio_fila == fim_fila || fila[inicio_fila] != valor) {
                        pode_ser_fila = 0;
                    } else {
                        inicio_fila++; 
                    }
                }

                
                if (pode_ser_prio) {
                    if (tam_prio == 0) {
                        pode_ser_prio = 0;
                    } else {
                        
                        int indice_maior = 0;
                        int maior_valor = fila_prio[0];

                        for (int k = 1; k < tam_prio; k++) {
                            if (fila_prio[k] > maior_valor) {
                                maior_valor = fila_prio[k];
                                indice_maior = k;
                            }
                        }

                        
                        if (maior_valor != valor) {
                            pode_ser_prio = 0;
                        } else {
                            
                            fila_prio[indice_maior] = fila_prio[tam_prio - 1];
                            tam_prio--;
                        }
                    }
                }
            }
        }

        
        int total_possiveis = pode_ser_pilha + pode_ser_fila + pode_ser_prio;

        if (total_possiveis == 0) {
            printf("impossible\n");
        } else if (total_possiveis > 1) {
            printf("not sure\n");
        } else {
            if (pode_ser_pilha) printf("stack\n");
            else if (pode_ser_fila) printf("queue\n");
            else printf("priority queue\n");
        }
    }

    return 0;
}
