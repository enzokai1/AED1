#include <stdio.h>

#define INFINITO 10000000
#define MAX 255

int main() {
    int N, M, C, K;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        int grafo[MAX][MAX];
        int distancia[MAX];
        int visitado[MAX];

        for (int i = 0; i < N; i++) {
            distancia[i] = INFINITO;
            visitado[i] = 0;
            for (int j = 0; j < N; j++) {
                grafo[i][j] = (i == j) ? 0 : INFINITO;
            }
        }

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            if (p < grafo[u][v]) grafo[u][v] = p;
            if (p < grafo[v][u]) grafo[v][u] = p;
        }

        distancia[K] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;
            int menor = INFINITO;

            for (int j = 0; j < N; j++) {
                if (!visitado[j] && distancia[j] < menor) {
                    menor = distancia[j];
                    u = j;
                }
            }

            if (u == -1) break;
            visitado[u] = 1;

            for (int v = 0; v < N; v++) {
                if (grafo[u][v] != INFINITO) {
                    if (u < C - 1) {
                        if (v == u + 1) {
                            if (distancia[u] + grafo[u][v] < distancia[v]) {
                                distancia[v] = distancia[u] + grafo[u][v];
                            }
                        }
                    } else {
                        if (distancia[u] + grafo[u][v] < distancia[v]) {
                            distancia[v] = distancia[u] + grafo[u][v];
                        }
                    }
                }
            }
        }

        printf("%d\n", distancia[C - 1]);
    }

    return 0;
}
