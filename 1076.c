#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int inicio;
        scanf("%d", &inicio);

        int V, A;
        scanf("%d %d", &V, &A);

        int adj[MAX][MAX];
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int movimentos = 0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (adj[i][j] == 1) {
                    movimentos++;
                }
            }
        }

        printf("%d\n", movimentos);
    }

    return 0;
}
