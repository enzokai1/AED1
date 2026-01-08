#include <stdio.h>
#include <stdlib.h>

struct Aresta {
    int origem;
    int destino;
    int peso;
};


struct Aresta lista_arestas[50005];
struct Aresta auxiliar[50005]; 
int chefe_do_grupo[40005]; 


void intercalar(int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    
    while (i <= meio && j <= fim) {
        if (lista_arestas[i].peso <= lista_arestas[j].peso) {
            auxiliar[k] = lista_arestas[i];
            i++;
        } else {
            auxiliar[k] = lista_arestas[j];
            j++;
        }
        k++;
    }

    
    while (i <= meio) {
        auxiliar[k] = lista_arestas[i];
        i++;
        k++;
    }

  
    while (j <= fim) {
        auxiliar[k] = lista_arestas[j];
        j++;
        k++;
    }

  
    for (i = inicio; i <= fim; i++) {
        lista_arestas[i] = auxiliar[i];
    }
}


void merge_sort(int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        
        // ordena a primeira metade
        merge_sort(inicio, meio);
        
        // ordena a segunda metade
        merge_sort(meio + 1, fim);
        
        // junta
        intercalar(inicio, meio, fim);
    }
}

//union-find
int encontrar_chefe(int i) {
    if (chefe_do_grupo[i] == i) return i;
    //atualiza o chefe direto pra raiz
    int raiz = encontrar_chefe(chefe_do_grupo[i]);
    chefe_do_grupo[i] = raiz; // Compressão de caminho
    return raiz;
}

void unir_conjuntos(int i, int j) {
    int chefe_i = encontrar_chefe(i);
    int chefe_j = encontrar_chefe(j);
    //se tiverem chefes diferentes, acaba que um vira chefe do outro
    if (chefe_i != chefe_j) {
        chefe_do_grupo[chefe_i] = chefe_j;
    }
}


int main() {
    int qtd_vertices, qtd_arestas;

    while (scanf("%d %d", &qtd_vertices, &qtd_arestas) && (qtd_vertices != 0 || qtd_arestas != 0)) {
        
        for (int i = 0; i < qtd_arestas; i++) {
            scanf("%d %d %d", &lista_arestas[i].origem, 
                              &lista_arestas[i].destino, 
                              &lista_arestas[i].peso);
        }

       
        for (int i = 0; i < qtd_vertices; i++) {
            chefe_do_grupo[i] = i;
        }

        
        merge_sort(0, qtd_arestas - 1);

        //kruskal
        long long custo_total = 0; 

        for (int i = 0; i < qtd_arestas; i++) {
            int u = lista_arestas[i].origem;
            int v = lista_arestas[i].destino;
            
            if (encontrar_chefe(u) != encontrar_chefe(v)) {
                unir_conjuntos(u, v);
                custo_total += lista_arestas[i].peso;
            }
        }

        printf("%lld\n", custo_total);
    }

    return 0;
}
