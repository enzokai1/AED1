#include <stdio.h>


int fila_original[1005];
int fila_ordenada[1005];

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    while (casos_teste > 0) {
        int m; // quantidade de alunos
        scanf("%d", &m);

        // Leitura
        for (int i = 0; i < m; i++) {
            scanf("%d", &fila_original[i]);
            
            fila_ordenada[i] = fila_original[i];
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - 1 - i; j++) {
                
                if (fila_ordenada[j] < fila_ordenada[j+1]) {
                    int aux = fila_ordenada[j];
                    fila_ordenada[j] = fila_ordenada[j+1];
                    fila_ordenada[j+1] = aux;
                }
            }
        }

        
        int nao_trocaram = 0;
        for (int i = 0; i < m; i++) {
            
            if (fila_original[i] == fila_ordenada[i]) {
                nao_trocaram++;
            }
        }

        printf("%d\n", nao_trocaram);

        casos_teste--;
    }

    return 0;
}
