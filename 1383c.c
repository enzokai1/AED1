#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int checarGrupo(int group[9]) {
    int check[10];
    
    memset(check, 0, sizeof(check));

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

    for (k = 1; k <= n; k++) {
        
        int** grid = (int**) malloc(9 * sizeof(int*));
        if (grid == NULL) return 1; 

        for (int i = 0; i < 9; i++) {
            grid[i] = (int*) malloc(9 * sizeof(int));
            if (grid[i] == NULL) return 1; 
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        int ehValido = 1;
        int tempGrupo[9]; 

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                tempGrupo[j] = grid[i][j];
            }
            if (!checarGrupo(tempGrupo)) {
                ehValido = 0;
            }
        }

        if (ehValido) { 
            for (int j = 0; j < 9; j++) {
                for (int i = 0; i < 9; i++) {
                    tempGrupo[i] = grid[i][j];
                }
                if (!checarGrupo(tempGrupo)) {
                    ehValido = 0;
                }
            }
        }
        
        if (ehValido) { 
            for (int startRow = 0; startRow < 9; startRow += 3) {
                for (int startCol = 0; startCol < 9; startCol += 3) {
                    
                    int idx = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            tempGrupo[idx++] = grid[startRow + i][startCol + j];
                        }
                    }
                    
                    if (!checarGrupo(tempGrupo)) {
                        ehValido = 0;
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
        
        for (int i = 0; i < 9; i++) {
            free(grid[i]); 
        }
        free(grid); 
    }

    return 0;
}
