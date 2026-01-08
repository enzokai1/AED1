#include <stdio.h>
#include <stdlib.h> 


int verificar_conjunto(int vetor[9]) {
    int numeros_vistos[10]; 
    
    
    for (int i = 0; i <= 9; i++) {
        numeros_vistos[i] = 0;
    }

    for (int i = 0; i < 9; i++) {
        int numero = vetor[i];
        
        if (numero < 1 || numero > 9) return 0;
        if (numeros_vistos[numero] == 1) return 0;
        
        numeros_vistos[numero] = 1;
    }
    return 1;
}

int main() {
    int n_instancias;
    scanf("%d", &n_instancias);

    for (int k = 1; k <= n_instancias; k++) {
        
        // alocando dinamicamente
        int **tabuleiro = (int**) malloc(9 * sizeof(int*));
        
        for (int i = 0; i < 9; i++) {
            tabuleiro[i] = (int*) malloc(9 * sizeof(int));
        }
        
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &tabuleiro[i][j]);
            }
        }
        
        int eh_valido = 1;
        int vetor_teste[9]; 

        // verifica Linhas
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                vetor_teste[j] = tabuleiro[i][j];
            }
            if (verificar_conjunto(vetor_teste) == 0) {
                eh_valido = 0;
                break;
            }
        }

        // verifica colunas
        if (eh_valido) {
            for (int j = 0; j < 9; j++) {
                for (int i = 0; i < 9; i++) {
                    vetor_teste[i] = tabuleiro[i][j];
                }
                if (verificar_conjunto(vetor_teste) == 0) {
                    eh_valido = 0;
                    break;
                }
            }
        }

        // verifica bloco
        if (eh_valido) {
            for (int linha_bloco = 0; linha_bloco < 9; linha_bloco += 3) {
                for (int col_bloco = 0; col_bloco < 9; col_bloco += 3) {
                    
                    int idx = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            vetor_teste[idx] = tabuleiro[linha_bloco + i][col_bloco + j];
                            idx++;
                        }
                    }
                    
                    if (verificar_conjunto(vetor_teste) == 0) {
                        eh_valido = 0;
                        linha_bloco = 9; 
                        break;
                    }
                }
            }
        }
        
        printf("Instancia %d\n", k);
        if (eh_valido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");

      
        for (int i = 0; i < 9; i++) {
            free(tabuleiro[i]);
        }
        free(tabuleiro);
    }

    return 0;
}
