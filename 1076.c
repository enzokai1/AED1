#include <stdio.h>


int matriz_adj[55][55];

int main() {
    int casos_teste;
    if (scanf("%d", &casos_teste) != 1) return 0;

    while (casos_teste--) {
        int ponto_inicio;
        scanf("%d", &ponto_inicio); 

        int qtd_vertices, qtd_arestas;
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

       
        for (int i = 0; i < qtd_vertices; i++) {
            for (int j = 0; j < qtd_vertices; j++) {
                matriz_adj[i][j] = 0;
            }
        }

        
        for (int i = 0; i < qtd_arestas; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            
            // grafo nao direcionado
            matriz_adj[u][v] = 1;
            matriz_adj[v][u] = 1;
        }

       // desenhar o labirinto todo e volta, passando 2 vezes por linha, entao basta somar quando 1 existem na matriz
        int total_movimentos = 0;
        
        for (int i = 0; i < qtd_vertices; i++) {
            for (int j = 0; j < qtd_vertices; j++) {
                if (matriz_adj[i][j] == 1) {
                    total_movimentos++;
                }
            }
        }

        printf("%d\n", total_movimentos);
    }

    return 0;
}
