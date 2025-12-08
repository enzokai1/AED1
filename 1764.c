#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem;
    int destino;
    int peso;
} Aresta;

Aresta arestas[50005];
int pai[40005];

int buscar(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = buscar(pai[i]);
}

void unir(int i, int j) {
    int raiz_i = buscar(i);
    int raiz_j = buscar(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int comparar(const void* a, const void* b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
        }

        for (int i = 0; i < m; i++) {
            pai[i] = i;
        }

        qsort(arestas, n, sizeof(Aresta), comparar);

        long long custo_mst = 0;

        for (int i = 0; i < n; i++) {
            if (buscar(arestas[i].origem) != buscar(arestas[i].destino)) {
                unir(arestas[i].origem, arestas[i].destino);
                custo_mst += arestas[i].peso;
            }
        }

        printf("%lld\n", custo_mst);
    }

    return 0;
}
