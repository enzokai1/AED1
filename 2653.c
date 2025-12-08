#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trie[1000005][2];
int fim[1000005];
int nos = 1;

void inserir(char *s, int *contagem) {
    int atual = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int id = (s[i] == ')') ? 1 : 0;
        if (trie[atual][id] == 0) {
            trie[atual][id] = nos++;
        }
        atual = trie[atual][id];
    }
    if (!fim[atual]) {
        fim[atual] = 1;
        (*contagem)++;
    }
}

int main() {
    char s[100005];
    int contagem = 0;

    memset(trie, 0, sizeof(trie));
    memset(fim, 0, sizeof(fim));

    while (scanf("%s", s) != EOF) {
        inserir(s, &contagem);
    }

    printf("%d\n", contagem);

    return 0;
}
