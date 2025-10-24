#include <stdio.h>
#include <string.h> 

int checarGrupo(int group[9]) {
    int check[10];
    
    for (int i = 0; i < 10; i++) {
        check[i] = 0;
    }

    for (int i = 0; i < 9; i++) {
        int num = group[i];
        
        if (num < 1 || num > 9 || check[num] == 1) {
            return 0; 
        }
        
        check[num] = 1;
    }

    return 1; 
}

int main() {
    int n, k;
    scanf("%d", &n); 

    int grid[9][9];
    int tempGrupo[9];

    for (k = 1; k <= n; k++) {
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        int ehValido = 1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                tempGrupo[j] = grid[i][j];
            }
            if (!checarGrupo(tempGrupo)) {
                ehValido = 0;
                break; 
            }
        }

        if (ehValido) { 
            for (int j = 0; j < 9; j++) {
                for (int i = 0; i < 9; i++) {
                    tempGrupo[i] = grid[i][j];
                }
                if (!checarGrupo(tempGrupo)) {
                    ehValido = 0;
                    break;
                }
            }
        }
        
        if (ehValido) { 
            for (int startRow = 0; startRow < 9; startRow += 3) {
                if (!ehValido) break; 
                
                for (int startCol = 0; startCol < 9; startCol += 3) {
                    
                    int idx = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tempGrupo[idx++] = grid[startRow + i][startCol + j];
                        }
                    }
                    
                    if (!checarGrupo(tempGrupo)) {
                        ehValido = 0;
                        break; 
                    }
                }
            }
        }
        
        printf("Instancia %d\n", k);
        if (ehValido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n"); 
    }

    return 0;
}
