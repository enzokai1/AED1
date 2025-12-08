#include <stdio.h>
#include <stdlib.h>

#define INFINITO 2000000000
#define MAX_C 10005
#define MAX_A 100005 
#define TAM_HEAP 400000

int cabeca[MAX_C];
int ponto[MAX_A];
int peso[MAX_A];
int proximo[MAX_A];
int contador_arestas = 0;

int dist[MAX_C][2];

typedef struct {
    int custo;
    int u;
    int paridade;
} No;

No heap[TAM_HEAP];
int tam_heap = 0;

void adicionar_aresta(int u, int v, int w) {
    ponto[contador_arestas] = v;
    peso[contador_arestas] = w;
    proximo[contador_arestas] = cabeca[u];
    cabeca[u] = contador_arestas++;
}

void push(No n) {
    int i = tam_heap++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].custo <= n.custo) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = n;
}

No pop() {
    No ret = heap[0];
    No x = heap[--tam_heap];
    int i = 0;
    while (i * 2 + 1 < tam_heap) {
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if (b < tam_heap && heap[b].custo < heap[a].custo) a = b;
        if (heap[a].custo >= x.custo) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main() {
    int C, V;
    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i <= C; i++) {
        cabeca[i] = -1;
        dist[i][0] = INFINITO;
        dist[i][1] = INFINITO;
    }

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adicionar_aresta(u, v, w);
        adicionar_aresta(v, u, w);
    }

    dist[1][0] = 0;
    No inicio = {0, 1, 0};
    push(inicio);

    while (tam_heap > 0) {
        No atual = pop();
        int d = atual.custo;
        int u = atual.u;
        int par = atual.paridade;

        if (d > dist[u][par]) continue;

        for (int e = cabeca[u]; e != -1; e = proximo[e]) {
            int v = ponto[e];
            int w = peso[e];
            int nova_par = 1 - par;

            if (dist[u][par] + w < dist[v][nova_par]) {
                dist[v][nova_par] = dist[u][par] + w;
                No proximo_no = {dist[v][nova_par], v, nova_par};
                push(proximo_no);
            }
        }
    }

    if (dist[C][0] == INFINITO) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[C][0]);
    }

    return 0;
}
