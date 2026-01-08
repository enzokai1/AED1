#include <stdio.h>


int matriz_adj[505][505];
int distancia[505];
int nos_processados[505];

int num_cidades, num_acordos;

//encontra o menor caminho da origem ate o destino e retorna o custo ou infinito se nao tem caminho
int calcular_dijkstra(int origem, int destino) {
    
    for (int i = 1; i <= num_cidades; i++) {
        distancia[i] = 10000000; // infinito
        nos_processados[i] = 0;  // nao foi visitado
    }
    
    distancia[origem] = 0;
    
    
    for (int i = 0; i < num_cidades; i++) {
        
        // escolher o nó com menor distância que ainda não foi processado
        int atual = -1;
        int menor_valor = 10000000;
        
        for (int j = 1; j <= num_cidades; j++) {
            if (nos_processados[j] == 0 && distancia[j] < menor_valor) {
                menor_valor = distancia[j];
                atual = j;
            }
        }
        
        // se não achou ninguém ou o menor valor é infinito, nao tem caminho
        if (atual == -1 || menor_valor == 10000000) break;
        
        nos_processados[atual] = 1; 
        
       
        if (atual == destino) return distancia[destino];
        
       
        for (int vizinho = 1; vizinho <= num_cidades; vizinho++) {
            
            if (matriz_adj[atual][vizinho] != 10000000) {
                
                if (distancia[atual] + matriz_adj[atual][vizinho] < distancia[vizinho]) {
                    distancia[vizinho] = distancia[atual] + matriz_adj[atual][vizinho];
                }
            }
        }
    }
    
    return distancia[destino];
}

int main() {
    
    while (scanf("%d %d", &num_cidades, &num_acordos) == 2 && num_cidades != 0) {
        
       
        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                
                if (i == j) {
                    matriz_adj[i][j] = 0;
                } else {
                    matriz_adj[i][j] = 10000000;
                }
            }
        }
        
       
        for (int i = 0; i < num_acordos; i++) {
            int x, y, horas;
            scanf("%d %d %d", &x, &y, &horas);
            
            // grafo direcionado, vai de x para y com custo horas
            // se já tiver um multigrafo la , pegamos a menor 
            // mas o problema garante arestas únicas.
            matriz_adj[x][y] = horas;
        }
        
      
           
        //Se existe ida (i->j) E volta (j->i), o custo vira 0 para ambos.   
        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                if (i != j) { // Não compara cidade com ela mesma
                 
                    if (matriz_adj[i][j] != 10000000 && matriz_adj[j][i] != 10000000) {
                        matriz_adj[i][j] = 0;
                        matriz_adj[j][i] = 0;
                    }
                }
            }
        }
        
        
        int qtd_consultas;
        scanf("%d", &qtd_consultas);
        
        while (qtd_consultas > 0) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);
            
            int resultado = calcular_dijkstra(origem, destino);
            
            if (resultado == 10000000) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
            
            qtd_consultas--;
        }
        
        printf("\n"); 
    }
    
    return 0;
}
