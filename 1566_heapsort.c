#include <stdio.h>
#include <stdlib.h>


int vetor[3000005];

// funcao pra trocar dois valores
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void peneira(int arr[], int n, int i) {
    int maior = i;
    
    while (1) {
        int esquerda = 2 * i + 1;
        int direita = 2 * i + 2;
        maior = i;

        // ve se o filho da esquerda é maior que o pai
        if (esquerda < n && arr[esquerda] > arr[maior]) {
            maior = esquerda;
        }

        // ve se o filho da direita é maior
        if (direita < n && arr[direita] > arr[maior]) {
            maior = direita;
        }

        
        if (maior != i) {
            trocar(&arr[i], &arr[maior]);
            i = maior; 
        } else {
            break; 
        }
    }
}

void heap_sort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        peneira(arr, n, i);
    }

   
    for (int i = n - 1; i > 0; i--) {
       
        trocar(&arr[0], &arr[i]);
        
        
        peneira(arr, i, 0);
    }
}

int main() {
    int nc;
    if (scanf("%d", &nc) != 1) return 0;

    while (nc > 0) {
        int n;
        if (scanf("%d", &n) != 1) break;

        
        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        
        heap_sort(vetor, n);

        
        for (int i = 0; i < n; i++) {
            printf("%d", vetor[i]);
            
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        nc--;
    }
    return 0;
}
