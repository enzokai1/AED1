#include <stdio.h>

#define MAX_TAM 100 

int fila[MAX_TAM];
int frente;
int tras;
int tamanho;

void inicializarFila() {
    frente = 0;
    tras = -1;
    tamanho = 0;
}

void enfileirar(int valor) {
    tras = (tras + 1) % MAX_TAM;
    fila[tras] = valor;
    tamanho++;
}

int desenfileirar() {
    int valor = fila[frente];
    frente = (frente + 1) % MAX_TAM;
    tamanho--;
    return valor;
}

int getTamanho() {
    return tamanho;
}

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        
        inicializarFila();
        for (int i = 1; i <= n; i++) {
            enfileirar(i);
        }
        
        int descartadas[MAX_TAM];
        int countDescartadas = 0;
        
        while (getTamanho() >= 2) {
            
            descartadas[countDescartadas] = desenfileirar();
            countDescartadas++;
            
            int cartaParaMover = desenfileirar();
            enfileirar(cartaParaMover);
        }
        
        printf("Discarded cards:");
        for (int i = 0; i < countDescartadas; i++) {
            printf(" %d", descartadas[i]);
            if (i < countDescartadas - 1) {
                printf(",");
            }
        }
        printf("\n");
        
        printf("Remaining card: %d\n", desenfileirar());
    }
    
    return 0;
}
