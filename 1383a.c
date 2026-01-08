#include <stdio.h>


int tabuleiro[9][9];


int validar_grupo(int vetor[9]) {
    int numeros_vistos[10]; 
    
    
    for (int i = 0; i <= 9; i++) {
        numeros_vistos[i] = 0;
    }

    for (int i = 0; i < 9; i++) {
        int num = vetor[i];
        
        // nao pode repetir
        if (num < 1 || num > 9 || numeros_vistos[num] == 1) {
            return 0; 
        }
        
        numeros_vistos[num] = 1; // visto
    }

    return 1; // válido
}

int main() {
    int qtd_instancias;
    scanf("%d", &qtd_instancias);

    int vetor_teste[9]; // vetor temporário para passar para a função

    for (int k = 1; k <= qtd_instancias; k++) {
        
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &tabuleiro[i][j]);
            }
        }
        
        int eh_valido = 1;

        // verifica linha
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                vetor_teste[j] = tabuleiro[i][j]; 
            }
            if (validar_grupo(vetor_teste) == 0) {
                eh_valido = 0;
                break;
            }
        }

        // verifica coluna
        if (eh_valido) {
            for (int j = 0; j < 9; j++) {
                for (int i = 0; i < 9; i++) {
                    vetor_teste[i] = tabuleiro[i][j]; 
                }
                if (validar_grupo(vetor_teste) == 0) {
                    eh_valido = 0;
                    break;
                }
            }
        }
        
        // verifica bloco
        if (eh_valido) {
            
            for (int linha_inicio = 0; linha_inicio < 9; linha_inicio += 3) {
                for (int col_inicio = 0; col_inicio < 9; col_inicio += 3) {
                    
                    int indice = 0;
                    
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            vetor_teste[indice] = tabuleiro[linha_inicio + i][col_inicio + j];
                            indice++;
                        }
                    }
                    
                    if (validar_grupo(vetor_teste) == 0) {
                        eh_valido = 0;
                        break; 
                    }
                }
                if (!eh_valido) break; 
            }
        }
        
        printf("Instancia %d\n", k);
        if (eh_valido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
