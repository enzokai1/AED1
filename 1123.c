#include <stdio.h>


int matriz_adj[255][255];
int distancia[255];
int visitado[255];

int num_cidades, num_estradas, rota_servico, inicio;


int dijkstra() {
    
    for (int i = 0; i < num_cidades; i++) {
        distancia[i] = 10000000; // infinito
        visitado[i] = 0;
    }
    
    distancia[inicio] = 0;
    
    
    for (int i = 0; i < num_cidades; i++) {
        
        // no nao visitado com menor distância
        int atual = -1;
        int menor_valor = 10000000;
        
        for (int j = 0; j < num_cidades; j++) {
            if (!visitado[j] && distancia[j] < menor_valor) {
                menor_valor = distancia[j];
                atual = j;
            }
        }
        
        
        if (atual == -1) break;
        
        visitado[atual] = 1; // visitado
        
        
        //estou na rota de serviço nao sendo o destino final ainda
        if (atual < rota_servico - 1) {
            int proximo = atual + 1;
            
            // so verifico a aresta que vai para atual + 1
            if (matriz_adj[atual][proximo] != 10000000) {
                int peso = matriz_adj[atual][proximo];
                if (distancia[atual] + peso < distancia[proximo]) {
                    distancia[proximo] = distancia[atual] + peso;
                }
            }
        }
        
        // to fora da rota de serviço ou ja sou o destino final
        
        else {
            for (int vizinho = 0; vizinho < num_cidades; vizinho++) {
                if (matriz_adj[atual][vizinho] != 10000000) {
                    int peso = matriz_adj[atual][vizinho];
                    if (distancia[atual] + peso < distancia[vizinho]) {
                        distancia[vizinho] = distancia[atual] + peso;
                    }
                }
            }
        }
    }
    
    
    return distancia[rota_servico - 1];
}

int main() {
    
    while (scanf("%d %d %d %d", &num_cidades, &num_estradas, &rota_servico, &inicio) && 
           (num_cidades != 0 || num_estradas != 0 || rota_servico != 0 || inicio != 0)) {
        
       
        for (int i = 0; i < num_cidades; i++) {
            for (int j = 0; j < num_cidades; j++) {
                matriz_adj[i][j] = 10000000;
            }
            matriz_adj[i][i] = 0;
        }
        
        
        for (int i = 0; i < num_estradas; i++) {
            int u, v, preco;
            scanf("%d %d %d", &u, &v, &preco);
            
           
            if (preco < matriz_adj[u][v]) {
                matriz_adj[u][v] = preco;
                matriz_adj[v][u] = preco;
            }
        }
        
        
        printf("%d\n", dijkstra());
    }
    
    return 0;
}
