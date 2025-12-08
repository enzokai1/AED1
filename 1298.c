#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Aresta;

Aresta arestas[400005];
int pai[400005];
int N;
int num_arestas;

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
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int get_id(int r, int c) {
    return r * (2 * N + 2) + c;
}

void adicionar_aresta(int u, int v, int w) {
    arestas[num_arestas].u = u;
    arestas[num_arestas].v = v;
    arestas[num_arestas].w = w;
    num_arestas++;
}

int main() {
    char buffer[605];
    
    while (scanf("%d", &N) != EOF) {
        num_arestas = 0;
        int linhas = 2 * N;
        int colunas = 2 * N + 1;
        int total_nos = (linhas + 1) * (colunas + 1);

        for (int i = 0; i <= total_nos; i++) {
            pai[i] = i;
        }

        int raiz_borda = get_id(0, 0);
        for (int c = 0; c <= colunas; c++) {
            unir(raiz_borda, get_id(0, c));
            unir(raiz_borda, get_id(linhas, c));
        }
        for (int r = 0; r <= linhas; r++) {
            unir(raiz_borda, get_id(r, 0));
            unir(raiz_borda, get_id(r, colunas));
        }

        for (int i = 1; i < 2 * N; i++) {
            scanf("%s", buffer);
            for (int j = 0; j < N; j++) {
                int r = i;
                int c = (i % 2 != 0) ? (2 * j + 1) : (2 * j + 2);
                
                int u_h = get_id(r, c - 1);
                int v_h = get_id(r, c + 1);
                int w_h = (buffer[j] == 'H') ? 0 : 1;
                adicionar_aresta(u_h, v_h, w_h);

                int u_v = get_id(r - 1, c);
                int v_v = get_id(r + 1, c);
                int w_v = (buffer[j] == 'V') ? 0 : 1;
                adicionar_aresta(u_v, v_v, w_v);
            }
        }

        qsort(arestas, num_arestas, sizeof(Aresta), comparar);

        int trocas = 0;
        for (int i = 0; i < num_arestas; i++) {
            if (buscar(arestas[i].u) != buscar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                trocas += arestas[i].w;
            }
        }

        printf("%d\n", trocas);
    }
    return 0;
}
