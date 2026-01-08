#include <stdio.h>


int movimentos[100005]; 
int fila_bfs[100005];   

// funcao pra inverter o numero
int inverter_numero(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n = n / 10;
    }
    return invertido;
}

int main() {
    int casos_teste;
    if (scanf("%d", &casos_teste) != 1) return 0;

    while (casos_teste > 0) {
        int origem, destino;
        scanf("%d %d", &origem, &destino);
        
       // -1 mostra que nao foi visitado
        for(int i = 0; i < 100000; i++) {
            movimentos[i] = -1;
        }
        
    
        int inicio_fila = 0;
        int fim_fila = 0;
        
        
        fila_bfs[fim_fila] = origem;
        fim_fila++;
        movimentos[origem] = 0;
        
        // loop busca em largura
        while (inicio_fila < fim_fila) {
            
            int atual = fila_bfs[inicio_fila];
            inicio_fila++;
            
            
            if (atual == destino) {
                printf("%d\n", movimentos[atual]);
                break;
            }
            
           
            int proximo_soma = atual + 1;
            
            if (proximo_soma < 100000 && movimentos[proximo_soma] == -1) {
                movimentos[proximo_soma] = movimentos[atual] + 1;
                fila_bfs[fim_fila] = proximo_soma;
                fim_fila++;
            }
            
            
            int proximo_inverso = inverter_numero(atual);
            // ve se e valido e nao visitado
            if (proximo_inverso < 100000 && movimentos[proximo_inverso] == -1) {
                movimentos[proximo_inverso] = movimentos[atual] + 1;
                fila_bfs[fim_fila] = proximo_inverso;
                fim_fila++;
            }
        }
        
        casos_teste--;
    }
    return 0;
}
