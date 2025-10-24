#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC > 0) {
        int N;
        scanf("%d", &N);

        int* vetor = (int*) malloc(N * sizeof(int));

        if (vetor == NULL) {
            return 1; 
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &vetor[i]);
        }

        selectionSort(vetor, N);

        for (int i = 0; i < N; i++) {
            printf("%d", vetor[i]);
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n");

        free(vetor); 
        NC--;
    }
    return 0;
}
