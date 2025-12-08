#include <stdio.h>
#include <string.h>

double grafo[105][105];

int main() {
    int n, m, a, b, p;

    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &m);

        memset(grafo, 0, sizeof(grafo));

        for (int i = 1; i <= n; i++) {
            grafo[i][i] = 1.0;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &p);
            double prob = p / 100.0;
            grafo[a][b] = grafo[b][a] = prob;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (grafo[i][k] * grafo[k][j] > grafo[i][j]) {
                        grafo[i][j] = grafo[i][k] * grafo[k][j];
                    }
                }
            }
        }

        printf("%.6lf percent\n", grafo[1][n] * 100.0);
    }

    return 0;
}
