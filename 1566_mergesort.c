#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int l, int m, int r) {
    int i, j, k;
    
    i = l; 
    j = m + 1; 
    k = l; 

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m + 1, r);

        merge(arr, temp, l, m, r);
    }
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC > 0) {
        int N;
        scanf("%d", &N);

        int* vetor = (int*) malloc(N * sizeof(int));
        int* temp = (int*) malloc(N * sizeof(int));

        if (vetor == NULL || temp == NULL) {
            return 1; 
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &vetor[i]);
        }

        mergeSort(vetor, temp, 0, N - 1);

        for (int i = 0; i < N; i++) {
            printf("%d", vetor[i]);
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n");

        free(vetor);
        free(temp); 
        
        NC--;
    }
    return 0;
}
