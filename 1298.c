#include <stdio.h>


struct Aresta {
    int origem;
    int destino;
    int peso; 
};


struct Aresta lista_arestas[400005];
int chefe_grupo[400005]; 
int contador_arestas;
int tamanho_N;

//transformando a coordenada em um numero so 
int calcular_indice(int linha, int coluna) {
    int largura = 2 * tamanho_N + 2;
    return linha * largura + coluna;
}

// union-find
int encontrar_chefe(int i) {
    if (chefe_grupo[i] == i) return i;
    return chefe_grupo[i] = encontrar_chefe(chefe_grupo[i]);
}


void unir_conjuntos(int i, int j) {
    int chefe_i = encontrar_chefe(i);
    int chefe_j = encontrar_chefe(j);
    if (chefe_i != chefe_j) {
        chefe_grupo[chefe_i] = chefe_j;
    }
}

void criar_aresta(int u, int v, int w) {
    lista_arestas[contador_arestas].origem = u;
    lista_arestas[contador_arestas].destino = v;
    lista_arestas[contador_arestas].peso = w;
    contador_arestas++;
}

int main() {
    char buffer_leitura[605];
    
    while (scanf("%d", &tamanho_N) != EOF) {
        contador_arestas = 0;
        
        int total_linhas = 2 * tamanho_N;
        int total_colunas = 2 * tamanho_N + 1;
        int max_nos = (total_linhas + 1) * (total_colunas + 1);

        // union-find
        for (int i = 0; i <= max_nos; i++) {
            chefe_grupo[i] = i;
        }

        // conectando as bordas
        int raiz_borda = calcular_indice(0, 0);
        
        for (int c = 0; c <= total_colunas; c++) {
            unir_conjuntos(raiz_borda, calcular_indice(0, c));
            unir_conjuntos(raiz_borda, calcular_indice(total_linhas, c));
        }
        for (int r = 0; r <= total_linhas; r++) {
            unir_conjuntos(raiz_borda, calcular_indice(r, 0));
            unir_conjuntos(raiz_borda, calcular_indice(r, total_colunas));
        }

        // criando arestas
        for (int i = 1; i < 2 * tamanho_N; i++) {
            scanf("%s", buffer_leitura);
            for (int j = 0; j < tamanho_N; j++) {
                int r = i;
                int c = (i % 2 != 0) ? (2 * j + 1) : (2 * j + 2);
                
                // horizontal
                int u_h = calcular_indice(r, c - 1);
                int v_h = calcular_indice(r, c + 1);
                int peso_h = (buffer_leitura[j] == 'H') ? 0 : 1;
                criar_aresta(u_h, v_h, peso_h);

                // vertical
                int u_v = calcular_indice(r - 1, c);
                int v_v = calcular_indice(r + 1, c);
                int peso_v = (buffer_leitura[j] == 'V') ? 0 : 1;
                criar_aresta(u_v, v_v, peso_v);
            }
        }

       // kruskal sem ordenacao
        int custo_total = 0;

        // prioridade maxima
        for (int i = 0; i < contador_arestas; i++) {
            if (lista_arestas[i].peso == 0) {
                int u = lista_arestas[i].origem;
                int v = lista_arestas[i].destino;
                
                if (encontrar_chefe(u) != encontrar_chefe(v)) {
                    unir_conjuntos(u, v);
                    
                }
            }
        }

        // prioridade baixa
        for (int i = 0; i < contador_arestas; i++) {
            if (lista_arestas[i].peso == 1) {
                int u = lista_arestas[i].origem;
                int v = lista_arestas[i].destino;
                
                if (encontrar_chefe(u) != encontrar_chefe(v)) {
                    unir_conjuntos(u, v);
                    custo_total += 1;
                }
            }
        }

        printf("%d\n", custo_total);
    }
    return 0;
}
