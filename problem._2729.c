#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compararItens(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void removerDuplicadosEOrdenar(char* linha) {
    char* itens[1000]; // Limite máximo de itens por lista
    int quantidadeItens = 0;
    char* token = strtok(linha, " ");

    while (token != NULL) {
        int duplicado = 0;
        for (int i = 0; i < quantidadeItens; i++) {
            if (strcmp(itens[i], token) == 0) {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado) {
            itens[quantidadeItens] = token;
            quantidadeItens++;
        }
        token = strtok(NULL, " ");
    }

    qsort(itens, quantidadeItens, sizeof(char*), compararItens);

    for (int i = 0; i < quantidadeItens; i++) {
        printf("%s", itens[i]);
        if (i < quantidadeItens - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int numeroCasos;
    scanf("%d\n", &numeroCasos);

    for (int i = 0; i < numeroCasos; i++) {
        char linha[1000 * 21]; // Limite de caracteres para cada linha de itens
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = 0;
        removerDuplicadosEOrdenar(linha);
    }

    return 0;
}
