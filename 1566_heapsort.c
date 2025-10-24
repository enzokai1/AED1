#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;     
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

        heapSort(vetor, N);

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
