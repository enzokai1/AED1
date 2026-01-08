#include <stdio.h>


int matriz_adj[30][30];
int visitados[30];
int num_vertices, num_arestas;


int componente_atual[30];
int tamanho_componente;


void ordenar_vetor() {
    for (int i = 0; i < tamanho_componente - 1; i++) {
        for (int j = 0; j < tamanho_componente - i - 1; j++) {
            if (componente_atual[j] > componente_atual[j + 1]) {
                
                int temp = componente_atual[j];
                componente_atual[j] = componente_atual[j + 1];
                componente_atual[j + 1] = temp;
            }
        }
    }
}

//busca em profundidade
void dfs(int u) {
    visitados[u] = 1; // visitado
    
    
    componente_atual[tamanho_componente] = u;
    tamanho_componente++;
    
    
    for (int v = 0; v < num_vertices; v++) {
        
        if (matriz_adj[u][v] == 1 && visitados[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int k = 1; k <= casos_teste; k++) {
        scanf("%d %d", &num_vertices, &num_arestas);

        
        for (int i = 0; i < num_vertices; i++) {
            visitados[i] = 0;
            for (int j = 0; j < num_vertices; j++) {
                matriz_adj[i][j] = 0;
            }
        }

       
        for (int i = 0; i < num_arestas; i++) {
            char u_char, v_char;
            
            scanf(" %c %c", &u_char, &v_char);
            
            
            int u = u_char - 'a';
            int v = v_char - 'a';
            
            matriz_adj[u][v] = 1;
            matriz_adj[v][u] = 1; // grafo nao direcionado
        }

        printf("Case #%d:\n", k);

        int qtd_conexoes = 0;

       
        for (int i = 0; i < num_vertices; i++) {
            
            if (visitados[i] == 0) {
                qtd_conexoes++;
                tamanho_componente = 0; 
                
                dfs(i); 
                
                ordenar_vetor(); 
                
                
                for (int j = 0; j < tamanho_componente; j++) {
                    
                    printf("%c,", componente_atual[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", qtd_conexoes);
    }

    return 0;
}
