#include <stdio.h>
#include <stdlib.h>

int primeira_aresta[10005]; 
int destino[100005];        
int peso[100005];           
int prox_aresta[100005];    
int indice_aresta = 0;      


int distancia[10005][2];


typedef struct {
    int custo_atual;
    int vertice;
    int paridade; 
} Estado;

Estado meu_heap[400000];
int tamanho_heap = 0;


int infinito = 1000000000;

void criar_aresta(int origem, int dest, int custo) {
    destino[indice_aresta] = dest;
    peso[indice_aresta] = custo;
    
    //o proximo da aresta aponta para o antigo inicio da lista
    prox_aresta[indice_aresta] = primeira_aresta[origem];

    //inicio da lista vira essa nova aresta
    primeira_aresta[origem] = indice_aresta;
    
    indice_aresta++;
}


void inserir_no_heap(Estado novo) {
    int i = tamanho_heap;
    tamanho_heap++;
    
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (meu_heap[pai].custo_atual <= novo.custo_atual) {
            break; 
        }
        meu_heap[i] = meu_heap[pai];
        i = pai;
    }
    meu_heap[i] = novo;
}


Estado remover_do_heap() {
    Estado retorno = meu_heap[0];
    tamanho_heap--;
    
    Estado ultimo = meu_heap[tamanho_heap];
    int i = 0;
    
    while (i * 2 + 1 < tamanho_heap) {
        int filho_esq = i * 2 + 1;
        int filho_dir = i * 2 + 2;
        int menor = filho_esq;
        
        if (filho_dir < tamanho_heap && meu_heap[filho_dir].custo_atual < meu_heap[filho_esq].custo_atual) {
            menor = filho_dir;
        }
        
        if (meu_heap[menor].custo_atual >= ultimo.custo_atual) {
            break;
        }
        
        meu_heap[i] = meu_heap[menor];
        i = menor;
    }
    
    meu_heap[i] = ultimo;
    return retorno;
}

int main() {
    int C, V;
    
    if (scanf("%d %d", &C, &V) != 2) return 0;

    
    for (int i = 0; i <= C; i++) {
        primeira_aresta[i] = -1; 
        distancia[i][0] = infinito; 
        distancia[i][1] = infinito;
    }

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        criar_aresta(u, v, w);
        criar_aresta(v, u, w);
    }

    distancia[1][0] = 0;
    Estado inicial = {0, 1, 0};
    inserir_no_heap(inicial);

    while (tamanho_heap > 0) {
        Estado atual = remover_do_heap();
        
        int d = atual.custo_atual;
        int u = atual.vertice;
        int par = atual.paridade;
        
        //ve se o que eu tirei do heap e um caminho pior do que eu conheco, se for pior dou um continue para nao dar time limit   
        if (d > distancia[u][par]) continue;

        for (int e = primeira_aresta[u]; e != -1; e = prox_aresta[e]) {
            int v = destino[e];
            int w = peso[e];
            int nova_par = 1 - par;

            if (distancia[u][par] + w < distancia[v][nova_par]) {
                distancia[v][nova_par] = distancia[u][par] + w;
                
                Estado proximo = {distancia[v][nova_par], v, nova_par};
                inserir_no_heap(proximo);
            }
        }
    }

    if (distancia[C][0] == infinito) {
        printf("-1\n");
    } else {
        printf("%d\n", distancia[C][0]);
    }

    return 0;
}
