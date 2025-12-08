#include <stdio.h>

#define INFINITO 10000000
#define MAX 505

int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int N, E;

int dijkstra(int origem, int destino) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INFINITO;
        visitado[i] = 0;
    }
    
    dist[origem] = 0;
    
    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_val = INFINITO;
        
        for (int j = 1; j <= N; j++) {
            if (!visitado[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visitado[u] = 1;
        
        if (u == destino) return dist[u];
        
        for (int v = 1; v <= N; v++) {
            if (adj[u][v] != INFINITO) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }
    return dist[destino];
}

int main() {
    while (1) {
        if (scanf("%d %d", &N, &E) != 2) break;
        if (N == 0 && E == 0) break;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = INFINITO;
            }
            adj[i][i] = 0;
        }
        
        for (int i = 0; i < E; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            adj[x][y] = h;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j] != INFINITO && adj[j][i] != INFINITO) {
                    adj[i][j] = 0;
                    adj[j][i] = 0;
                }
            }
        }
        
        int K;
        scanf("%d", &K);
        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);
            int res = dijkstra(O, D);
            
            if (res == INFINITO) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", res);
            }
        }
        printf("\n");
    }
    
    return 0;
}
