#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX_ID 100001

int main() {
    int N; 
    scanf("%d", &N);

    int *fila_inicial = (int*) malloc(N * sizeof(int));
    if (fila_inicial == NULL) return 1; 

    for (int i = 0; i < N; i++) {
        scanf("%d", &fila_inicial[i]);
    }

    int M; 
    scanf("%d", &M);

    int *saiu = (int*) calloc(MAX_ID, sizeof(int));
    if (saiu == NULL) return 1; 

    for (int i = 0; i < M; i++) {
        int id_que_saiu;
        scanf("%d", &id_que_saiu);
        saiu[id_que_saiu] = 1; 
    }

    int primeiro_a_imprimir = 1; 
    
    for (int i = 0; i < N; i++) {
        int id_atual = fila_inicial[i];
        
        if (saiu[id_atual] == 0) { 
            
            if (primeiro_a_imprimir == 0) {
                printf(" ");
            }
            
            printf("%d", id_atual);
            
            primeiro_a_imprimir = 0;
        }
    }
    
    printf("\n");
    
    free(fila_inicial);
    free(saiu);

    return 0;
}
