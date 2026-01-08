#include <stdio.h>


double matriz_probabilidades[105][105];

int main() {
    int num_nos, num_conexoes;

   
    while (scanf("%d", &num_nos) && num_nos != 0) {
        scanf("%d", &num_conexoes);

        
     //chance de ele ir de um no pra ele mesmo 100% e para outros 0(sem conexao)    
        for (int i = 1; i <= num_nos; i++) {
            for (int j = 1; j <= num_nos; j++) {
                if (i == j) {
                    matriz_probabilidades[i][j] = 1.0;
                } else {
                    matriz_probabilidades[i][j] = 0.0;
                }
            }
        }

        //le os pares e a chance de sucesso
        for (int i = 0; i < num_conexoes; i++) {
            int origem, destino, percentual;
            scanf("%d %d %d", &origem, &destino, &percentual);
            
            // inteiro pra decimal
            double prob = percentual / 100.0;
            
            // grafo nao direcionado
            matriz_probabilidades[origem][destino] = prob;
            matriz_probabilidades[destino][origem] = prob;
        }

        // aplicando o algoritmo floyd warshall mas para multiplicar as chances e achar o valor maximo
        for (int k = 1; k <= num_nos; k++) {
            for (int i = 1; i <= num_nos; i++) {
                for (int j = 1; j <= num_nos; j++) {
                    
                    
                    double nova_prob = matriz_probabilidades[i][k] * matriz_probabilidades[k][j];
                    
                    // se por k for mais seguro que o caminho atual 
                    if (nova_prob > matriz_probabilidades[i][j]) {
                        matriz_probabilidades[i][j] = nova_prob;
                    }
                }
            }
        }

        
        
        printf("%.6lf percent\n", matriz_probabilidades[1][num_nos] * 100.0);
    }

    return 0;
}
