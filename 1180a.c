#include <stdio.h>


int vetor[1005];

int main() {
    int n;
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

   
    int menor = vetor[0];
    int posicao = 0;

   
    for (int i = 1; i < n; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
