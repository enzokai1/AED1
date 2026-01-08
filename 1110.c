#include <stdio.h>

//fila circular
int fila[100];
int inicio; 
int fim;   
int quantidade;

void limpar_fila() {
    inicio = 0;
    fim = -1;
    quantidade = 0;
}

void inserir(int valor) {
    
    fim = (fim + 1) % 100;
    fila[fim] = valor;
    quantidade++;
}

int remover() {
    int valor = fila[inicio];
    inicio = (inicio + 1) % 100;  // pra fazer a fila ser circular
    quantidade--;
    return valor;
}

int main() {
    int n;

   
    while (scanf("%d", &n) == 1 && n != 0) {
        
        limpar_fila();
        
        
        for (int i = 1; i <= n; i++) {
            inserir(i);
        }
        
        printf("Discarded cards:");
        
        
        int primeiro_descarte = 1; 
        
        while (quantidade >= 2) {
           
            int carta_fora = remover();
            
            if (primeiro_descarte) {
                printf(" %d", carta_fora);
                primeiro_descarte = 0;
            } else {
                printf(", %d", carta_fora);
            }
            
            
            int carta_base = remover();
            inserir(carta_base);
        }
        
        printf("\n");
        
        
        printf("Remaining card: %d\n", remover());
    }
    
    return 0;
}
