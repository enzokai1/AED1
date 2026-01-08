#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Coordenada {
    int x;
    int y;
};

struct Aresta {
    int ponto_a;
    int ponto_b;
    double distancia;
};


struct Coordenada pessoas[505];
struct Aresta lista_arestas[130000];
int chefe_grupo[505]; // union-find

// achar a distancia entre dois pontos
double calcular_distancia(int i, int j) {
    double dif_x = pessoas[i].x - pessoas[j].x;
    double dif_y = pessoas[i].y - pessoas[j].y;
    return sqrt(dif_x * dif_x + dif_y * dif_y);
}

// union - find
int encontrar_chefe(int i) {
    if (chefe_grupo[i] == i) {
        return i;
    }
    
    int raiz = encontrar_chefe(chefe_grupo[i]);
    chefe_grupo[i] = raiz;
    return raiz;
}

// junta se eles forem difrentes
void unir_conjuntos(int i, int j) {
    int chefe_i = encontrar_chefe(i);
    int chefe_j = encontrar_chefe(j);
    
    if (chefe_i != chefe_j) {
        chefe_grupo[chefe_i] = chefe_j;
    }
}

// comparacao para o quicksort
int comparar_arestas(const void* a, const void* b) {
    struct Aresta* aresta1 = (struct Aresta*) a;
    struct Aresta* aresta2 = (struct Aresta*) b;
    
    if (aresta1->distancia < aresta2->distancia) return -1;
    if (aresta1->distancia > aresta2->distancia) return 1;
    return 0;
}

int main() {
    int casos_teste;
    if (scanf("%d", &casos_teste) != 1) return 0;

    while (casos_teste > 0) {
        int n;
        scanf("%d", &n);

        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pessoas[i].x, &pessoas[i].y);
            chefe_grupo[i] = i; 
        }

        
        int total_arestas = 0;
        for (int i = 0; i < n; i++) {
            //fiz isso pra nao repetir aresta
            for (int j = i + 1; j < n; j++) {
                lista_arestas[total_arestas].ponto_a = i;
                lista_arestas[total_arestas].ponto_b = j;
                lista_arestas[total_arestas].distancia = calcular_distancia(i, j);
                total_arestas++;
            }
        }

        //menor para maior
        qsort(lista_arestas, total_arestas, sizeof(struct Aresta), comparar_arestas);

        // implementando o algoritmo de kruskal
        double custo_total = 0.0;
        int arestas_usadas = 0;

        for (int i = 0; i < total_arestas; i++) {
            int u = lista_arestas[i].ponto_a;
            int v = lista_arestas[i].ponto_b;

            
            if (encontrar_chefe(u) != encontrar_chefe(v)) {
                unir_conjuntos(u, v);
                custo_total = custo_total + lista_arestas[i].distancia;
                arestas_usadas++;
            }

            
            if (arestas_usadas == n - 1) break;
        }

        
        printf("%.2lf\n", custo_total / 100.0);

        casos_teste--;
    }

    return 0;
}
