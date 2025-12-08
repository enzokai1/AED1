#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Ponto;

typedef struct {
    int u, v;
    double w;
} Aresta;

Ponto pessoas[505];
Aresta arestas[125000];
int pai[505];

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
    double diff = ((Aresta*)a)->w - ((Aresta*)b)->w;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

double dist(int i, int j) {
    double dx = pessoas[i].x - pessoas[j].x;
    double dy = pessoas[i].y - pessoas[j].y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int c, n;
    scanf("%d", &c);

    while (c--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pessoas[i].x, &pessoas[i].y);
            pai[i] = i;
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                arestas[k].u = i;
                arestas[k].v = j;
                arestas[k].w = dist(i, j);
                k++;
            }
        }

        qsort(arestas, k, sizeof(Aresta), comparar);

        double total = 0;
        int arestas_count = 0;

        for (int i = 0; i < k; i++) {
            if (buscar(arestas[i].u) != buscar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                total += arestas[i].w;
                arestas_count++;
            }
            if (arestas_count == n - 1) break;
        }

        printf("%.2lf\n", total / 100.0);
    }

    return 0;
}
