#include <stdio.h>


char mapa[60][60];
int linhas, colunas;

// dfs
void espalhar_tinta(int l, int c) {
    
    // 0 = cima, 1 = baixo, 2 = esquerda, 3 = direita
    int mov_linha[] = {-1, 1, 0, 0};
    int mov_coluna[] = {0, 0, -1, 1};

    //posicao atual
    mapa[l][c] = 'T';

    
    for (int i = 0; i < 4; i++) {
        int nova_l = l + mov_linha[i];
        int nova_c = c + mov_coluna[i];

        //ve se a nova posicao ta tendo ta matriz
        if (nova_l >= 0 && nova_l < linhas && nova_c >= 0 && nova_c < colunas) {
            
            // se o vizinho for A, chama a recursao
            if (mapa[nova_l][nova_c] == 'A') {
                espalhar_tinta(nova_l, nova_c);
            }
        }
    }
}

int main() {
    
    while (scanf("%d %d", &linhas, &colunas) && (linhas != 0 || colunas != 0)) {
        
        
        for (int i = 0; i < linhas; i++) {
            scanf("%s", mapa[i]);
        }

        
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (mapa[i][j] == 'T') {
                    espalhar_tinta(i, j);
                }
            }
        }

        
        for (int i = 0; i < linhas; i++) {
            printf("%s\n", mapa[i]);
        }
        printf("\n"); 
    }

    return 0;
}
