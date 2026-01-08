#include <stdio.h>

int main() {
    int velocidade, tempo;

    while (scanf("%d %d", &velocidade, &tempo) == 2) {
        
        int deslocamento = velocidade * tempo * 2;
        
        printf("%d\n", deslocamento);
    }

    return 0;
}
