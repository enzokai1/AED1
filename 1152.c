#include <stdio.h>


struct Estrada {
    int origem;
    int destino;
    int custo;
};

struct Estrada lista_estradas[200005]; 
struct Estrada auxiliar[200005];       
int chefe_grupo[200005];               

void intercalar(int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    // compara as duas metades e joga o menor no vetor auxiliar
    while (i <= meio && j <= fim) {
        if (lista_estradas[i].custo <= lista_estradas[j].custo) {
            auxiliar[k] = lista_estradas[i];
            i++;
        } else {
            auxiliar[k] = lista_estradas[j];
            j++;
        }
        k++;
    }

    // copia o que sobrou da esquerda
    while (i <= meio) {
        auxiliar[k] = lista_estradas[i];
        i++;
        k++;
    }

    // copia o que sobrou da direita
    while (j <= fim) {
        auxiliar[k] = lista_estradas[j];
        j++;
        k++;
    }

    // devolve os dados ordenados para o vetor original
    for (i = inicio; i <= fim; i++) {
        lista_estradas[i] = auxiliar[i];
    }
}


void ordenar_por_custo(int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        ordenar_por_custo(inicio, meio);
        ordenar_por_custo(meio + 1, fim);
        intercalar(inicio, meio, fim);
    }
}

// algoritmo de kruskal

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


int main() {
    int qtd_cidades, qtd_estradas;

    
    while (scanf("%d %d", &qtd_cidades, &qtd_estradas) && (qtd_cidades != 0 || qtd_estradas != 0)) {
        
        long long custo_total_antes = 0;
        
        for (int i = 0; i < qtd_estradas; i++) {
            scanf("%d %d %d", &lista_estradas[i].origem, 
                              &lista_estradas[i].destino, 
                              &lista_estradas[i].custo);
            custo_total_antes += lista_estradas[i].custo;
        }

        // mergesort manual
        ordenar_por_custo(0, qtd_estradas - 1);

        // kruskal
        for (int i = 0; i < qtd_cidades; i++) {
            chefe_grupo[i] = i;
        }

        long long custo_mst = 0;
        
        for (int i = 0; i < qtd_estradas; i++) {
            int u = lista_estradas[i].origem;
            int v = lista_estradas[i].destino;
            
            if (encontrar_chefe(u) != encontrar_chefe(v)) {
                unir_conjuntos(u, v);
                custo_mst += lista_estradas[i].custo;
            }
        }

        
        printf("%lld\n", custo_total_antes - custo_mst);
    }

    return 0;
}
