#include <stdio.h>

int cabeca_lista[10005];   
int destino_aresta[30005]; 
int prox_aresta[30005];    
int contador_arestas;      

// 0 = nao visitei
// 1 = visitando
// 2 = visitado
int estado_vertice[10005];

int ciclo_encontrado; 


void limpar_grafo(int qtd_vertices) {
    contador_arestas = 0;
    ciclo_encontrado = 0;
    
    
    for (int i = 1; i <= qtd_vertices; i++) {
        cabeca_lista[i] = -1; 
        estado_vertice[i] = 0; 
    }
}


void criar_dependencia(int origem, int destino) {
    destino_aresta[contador_arestas] = destino;
    prox_aresta[contador_arestas] = cabeca_lista[origem];
    cabeca_lista[origem] = contador_arestas;
    contador_arestas++;
}


// se eu encontrar um vizinho "1", eu achei um caminho de volta pra alguem que esta sendo visitado. Busca em profundidade 
void verificar_ciclo_dfs(int u) {
    
    if (ciclo_encontrado == 1) return;

    estado_vertice[u] = 1; 

    
    for (int i = cabeca_lista[u]; i != -1; i = prox_aresta[i]) {
        int vizinho = destino_aresta[i];

        if (estado_vertice[vizinho] == 1) {
           
            ciclo_encontrado = 1;
            return;
        } 
        else if (estado_vertice[vizinho] == 0) {
            //nao visitei ainda
            verificar_ciclo_dfs(vizinho);
            if (ciclo_encontrado == 1) return;
        }
        //totalmente visitado
    }

    estado_vertice[u] = 2; // visitei ele e os filhos
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    
    while (casos_teste > 0) {
        int N, M; 
        scanf("%d %d", &N, &M);

        limpar_grafo(N);

       
        for (int i = 0; i < M; i++) {
            int docA, docB;
            scanf("%d %d", &docA, &docB);
            criar_dependencia(docA, docB);
        }

       
        for (int i = 1; i <= N; i++) {
            if (estado_vertice[i] == 0) {
                verificar_ciclo_dfs(i);
                
                //achou, parou
                if (ciclo_encontrado == 1) {
                    break; 
                }
            }
        }

        if (ciclo_encontrado == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        casos_teste--;
    }

    return 0;
}
