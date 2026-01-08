#include <stdio.h>
#include <stdlib.h>


struct Aresta {
    int origem;
    int destino;
    int peso;
};


struct Aresta lista_arestas[50005];
int chefe_do_grupo[40005]; 

// union-find
int encontrar_chefe(int i) {
    if (chefe_do_grupo[i] == i) { // se for ele mesmo achei a raiz
        return i;
    }
    
    // atualiza o chefe direto pra raiz
    int raiz = encontrar_chefe(chefe_do_grupo[i]);
    chefe_do_grupo[i] = raiz;
    
    return raiz;
}

// union-find
void unir_conjuntos(int i, int j) {
    int chefe_i = encontrar_chefe(i);
    int chefe_j = encontrar_chefe(j);

    // se tiverem chefes diferentes, acaba que um vira chefe do outro
    if (chefe_i != chefe_j) {
        chefe_do_grupo[chefe_i] = chefe_j;
    }
}

// comparacao com quick sort , o algoritmo de kruskal precisa ordernar 50 mil arestas se fizer com bubble sort por exemplo ia dar time limit
int comparar_arestas(const void* a, const void* b) {
    struct Aresta* aresta1 = (struct Aresta*) a;
    struct Aresta* aresta2 = (struct Aresta*) b;
    
    return aresta1->peso - aresta2->peso;
}

int main() {
    int qtd_vertices, qtd_arestas;

    
    while (scanf("%d %d", &qtd_vertices, &qtd_arestas) && (qtd_vertices != 0 || qtd_arestas != 0)) {
        
        
        for (int i = 0; i < qtd_arestas; i++) {
            scanf("%d %d %d", &lista_arestas[i].origem, &lista_arestas[i].destino, &lista_arestas[i].peso);
        }

        
        for (int i = 0; i < qtd_vertices; i++) {
            chefe_do_grupo[i] = i;
        }

        // ordena pelo peso
        qsort(lista_arestas, qtd_arestas, sizeof(struct Aresta), comparar_arestas);

        // kruskal soma os pesos das arestas que nao formam ciclo
        long long custo_total = 0; 

        for (int i = 0; i < qtd_arestas; i++) {
            int u = lista_arestas[i].origem;
            int v = lista_arestas[i].destino;
            
            // se nao forma ciclo podemos unir
            if (encontrar_chefe(u) != encontrar_chefe(v)) {
                unir_conjuntos(u, v);
                custo_total = custo_total + lista_arestas[i].peso;
            }
        }

        printf("%lld\n", custo_total);
    }

    return 0;
}
