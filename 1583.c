#include <stdio.h>

int N, M;
char mapa[55][55];

void dfs(int r, int c) {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    mapa[r][c] = 'T';

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
            if (mapa[nr][nc] == 'A') {
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    while (scanf("%d %d", &N, &M) && (N != 0 || M != 0)) {
        for (int i = 0; i < N; i++) {
            scanf("%s", mapa[i]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mapa[i][j] == 'T') {
                    dfs(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            printf("%s\n", mapa[i]);
        }
        printf("\n");
    }
    return 0;
}
