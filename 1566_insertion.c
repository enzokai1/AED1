#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

        insertionSort(vetor, N);

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
