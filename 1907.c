#include <stdio.h>

#define MAX 1025
#define STACK_SIZE 1050000

typedef struct {
    int x, y;
} Ponto;

char imagem[MAX][MAX];
int N, M;

Ponto pilha[STACK_SIZE];
int topo = 0;

void push(int x, int y) {
    if (topo < STACK_SIZE) {
        pilha[topo].x = x;
        pilha[topo].y = y;
        topo++;
    }
}

Ponto pop() {
    topo--;
    return pilha[topo];
}

void floodFillIterativo(int i, int j) {
    push(i, j);
    imagem[i][j] = 'o'; 

    while (topo > 0) {
        Ponto p = pop();
        int x = p.x;
        int y = p.y;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && imagem[nx][ny] == '.') {
                imagem[nx][ny] = 'o'; 
                push(nx, ny);
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (imagem[i][j] == '.') {
                cliques++;
                floodFillIterativo(i, j);
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
