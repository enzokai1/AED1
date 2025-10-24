#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    return int_b - int_a;
}

int main() {
    int N; 
    scanf("%d", &N);

    while (N > 0) {
        int M; 
        scanf("%d", &M);

        int chegada[M];
        int ordenado[M];

        for (int i = 0; i < M; i++) {
            scanf("%d", &chegada[i]);
            ordenado[i] = chegada[i];
        }

        qsort(ordenado, M, sizeof(int), comparar);

        int nao_trocaram = 0;
        for (int i = 0; i < M; i++) {
            if (chegada[i] == ordenado[i]) {
                nao_trocaram++;
            }
        }

        printf("%d\n", nao_trocaram);

        N--; 
    }

    return 0;
}
