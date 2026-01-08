#include <stdio.h>

int fila[50005];          
int quem_saiu[100005];    

int main() {
    int qtd_inicial;
    scanf("%d", &qtd_inicial);

    
    for (int i = 0; i < qtd_inicial; i++) {
        scanf("%d", &fila[i]);
    }

    int qtd_sairam;
    scanf("%d", &qtd_sairam);

    // marcando quem saiu
    int id_removido;
    for (int i = 0; i < qtd_sairam; i++) {
        scanf("%d", &id_removido);
        quem_saiu[id_removido] = 1; 
    }

    int primeiro_impresso = 1; // pra nao dar presentation error no beecrowd

    // so imprime quem nao ta marcado
    for (int i = 0; i < qtd_inicial; i++) {
        int id_atual = fila[i];

        if (quem_saiu[id_atual] == 0) {
             
            // ainda nao pra dar presentation error 
            if (primeiro_impresso == 1) {
                printf("%d", id_atual);
                primeiro_impresso = 0;
            } else {
                printf(" %d", id_atual);
            }
        }
    }
    
    printf("\n");

    return 0;
}
