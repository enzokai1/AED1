#include <stdio.h>

#define MAX 100000

int inverter(int n) {
    int inv = 0;
    while (n > 0) {
        inv = inv * 10 + n % 10;
        n /= 10;
    }
    return inv;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        static int dist[MAX];
        static int fila[MAX];
        
        for(int i = 0; i < MAX; i++) dist[i] = -1;
        
        int frente = 0, tras = 0;
        
        fila[tras++] = A;
        dist[A] = 0;
        
        while (frente < tras) {
            int atual = fila[frente++];
            
            if (atual == B) {
                printf("%d\n", dist[atual]);
                break;
            }
            
            int prox1 = atual + 1;
            if (prox1 < MAX && dist[prox1] == -1) {
                dist[prox1] = dist[atual] + 1;
                fila[tras++] = prox1;
            }
            
            int prox2 = inverter(atual);
            if (prox2 < MAX && dist[prox2] == -1) {
                dist[prox2] = dist[atual] + 1;
                fila[tras++] = prox2;
            }
        }
    }
    return 0;
}
