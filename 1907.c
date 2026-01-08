#include <stdio.h>
#include <stdlib.h>


struct Coordenada {
    int linha;
    int coluna;
};


char mapa[1025][1025];
int linhas, colunas;


struct Coordenada pilha_trabalho[1050000];
int topo_pilha = 0;



void empilhar(int l, int c) {
    // so insere se nao estourar o limite
    if (topo_pilha < 1050000) {
        pilha_trabalho[topo_pilha].linha = l;
        pilha_trabalho[topo_pilha].coluna = c;
        topo_pilha++;
    }
}

struct Coordenada desempilhar() {
    topo_pilha--;
    return pilha_trabalho[topo_pilha];
}


void preencher_area(int l_inicial, int c_inicial) {
    empilhar(l_inicial, c_inicial);
    mapa[l_inicial][c_inicial] = 'o'; //ja visitei / contei

    while (topo_pilha > 0) {
        struct Coordenada atual = desempilhar();
        
        int l = atual.linha;
        int c = atual.coluna;

        //cima baixo direita e esquerda
        int muda_linha[] = {1, -1, 0, 0};
        int muda_coluna[] = {0, 0, 1, -1};

        //testa as direcoes
        for (int k = 0; k < 4; k++) {
            int nova_l = l + muda_linha[k];
            int nova_c = c + muda_coluna[k];

            // ve se ta dentro e e valido
            if (nova_l >= 0 && nova_l < linhas && 
                nova_c >= 0 && nova_c < colunas && 
                mapa[nova_l][nova_c] == '.') {
                
                mapa[nova_l][nova_c] = 'o'; 
                empilhar(nova_l, nova_c);   
            }
        }
    }
}

int main() {
   
    if (scanf("%d %d", &linhas, &colunas) != 2) return 0;

    
    for (int i = 0; i < linhas; i++) {
        scanf("%s", mapa[i]);
    }

    int total_cliques = 0;

    // procura por pontos nao visitados
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == '.') {
                //achou nova area
                total_cliques++;
                // chama a funcao pra pintar a area
                preencher_area(i, j);
            }
        }
    }

    printf("%d\n", total_cliques);

    return 0;
}
