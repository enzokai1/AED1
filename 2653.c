#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarei como matrizes globais porque tava estourando a memoria da pilha dentro do main
int arvore[1000005][2];   
int terminou[1000005];    
int contador_nos = 1;     

//percorre a arvore e retorna 1 se for nova e 0 se for repetido
int inserir_na_trie(char palavra[]) {
    int no_atual = 0; 
    int i = 0;
    
    
    while (palavra[i] != '\0') {
        int caminho;

        //decide o lado
        if (palavra[i] == ')') {
            caminho = 1;
        } else {
            caminho = 0;
        }

        // se o caminho nao existe, cria um no    
        if (arvore[no_atual][caminho] == 0) {
            arvore[no_atual][caminho] = contador_nos;
            contador_nos++;
        }

       
        no_atual = arvore[no_atual][caminho];
        i++; 
    }

    // usei pra ver se ja foi usada antes
    if (terminou[no_atual] == 0) {
        terminou[no_atual] = 1; 
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char palavra[100005];
    int total = 0;

    
    while (scanf("%s", palavra) != EOF) {
        int resultado = inserir_na_trie(palavra);
        total = total + resultado;
    }

    printf("%d\n", total);

    return 0;
}
