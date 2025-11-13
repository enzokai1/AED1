#include <stdio.h>

#define N_MAX 10001
#define M_MAX 30001

int inicio_lista[N_MAX];
int vertice_destino[M_MAX];
int proxima_aresta[M_MAX];
int contador_arestas;

int visitado[N_MAX];
int tem_ciclo;

void inicializar_grafo(int N) {
    contador_arestas = 0;
    tem_ciclo = 0;
    for (int i = 1; i <= N; i++) {
        inicio_lista[i] = -1;
        visitado[i] = 0;
    }
}

void adicionar_aresta(int u, int v) {
    vertice_destino[contador_arestas] = v;
    proxima_aresta[contador_arestas] = inicio_lista[u];
    inicio_lista[u] = contador_arestas;
    contador_arestas++;
}

void busca_profundidade(int u) {
    if (tem_ciclo) return;

    visitado[u] = 1;

    for (int i = inicio_lista[u]; i != -1; i = proxima_aresta[i]) {
        int v = vertice_destino[i];

        if (visitado[v] == 0) {
            busca_profundidade(v);
            if (tem_ciclo) return;
        } else if (visitado[v] == 1) {
            tem_ciclo = 1;
            return;
        }
    }

    visitado[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        inicializar_grafo(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar_aresta(A, B);
        }

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                busca_profundidade(i);
                if (tem_ciclo) {
                    break;
                }
            }
        }

        if (tem_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
