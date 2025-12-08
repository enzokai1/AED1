#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[26][26];
int visitado[26];
int lista[26];
int tam_lista;
int V, A;

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int u) {
    visitado[u] = 1;
    lista[tam_lista++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int caso = 1; caso <= N; caso++) {
        scanf("%d %d", &V, &A);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
            visitado[i] = 0;
        }

        for (int i = 0; i < A; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", caso);

        int total_componentes = 0;
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                total_componentes++;
                tam_lista = 0;
                dfs(i);
                
                qsort(lista, tam_lista, sizeof(int), comparar);
                
                for (int j = 0; j < tam_lista; j++) {
                    printf("%c,", lista[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", total_componentes);
    }

    return 0;
}
