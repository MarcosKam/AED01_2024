#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No* proximo;
} No;

No* criarNo(char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoFim(No** cabeca, char* nome) {
    No* novoNo = criarNo(nome);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

void inserirAntes(No** cabeca, char* alvo, No* novosAmigos) {
    if (*cabeca == NULL) return;

    if (strcmp((*cabeca)->nome, alvo) == 0) {
        No* ultimoNovoAmigo = novosAmigos;
        while (ultimoNovoAmigo->proximo != NULL) {
            ultimoNovoAmigo = ultimoNovoAmigo->proximo;
        }
        ultimoNovoAmigo->proximo = *cabeca;
        *cabeca = novosAmigos;
        return;
    }

    No* temp = *cabeca;
    while (temp->proximo != NULL && strcmp(temp->proximo->nome, alvo) != 0) {
        temp = temp->proximo;
    }

    if (temp->proximo != NULL) {
        No* ultimoNovoAmigo = novosAmigos;
        while (ultimoNovoAmigo->proximo != NULL) {
            ultimoNovoAmigo = ultimoNovoAmigo->proximo;
        }
        ultimoNovoAmigo->proximo = temp->proximo;
        temp->proximo = novosAmigos;
    }
}

void imprimirLista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%s", temp->nome);
        if (temp->proximo != NULL) printf(" ");
        temp = temp->proximo;
    }
    printf("\n");
}

void liberarLista(No* cabeca) {
    while (cabeca != NULL) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }
}

int main() {
    char amigosAtuais[1000];
    char novosAmigos[1000];
    char amigoAlvo[50];

    fgets(amigosAtuais, sizeof(amigosAtuais), stdin);
    fgets(novosAmigos, sizeof(novosAmigos), stdin);
    fgets(amigoAlvo, sizeof(amigoAlvo), stdin);

    amigosAtuais[strcspn(amigosAtuais, "\n")] = 0;
    novosAmigos[strcspn(novosAmigos, "\n")] = 0;
    amigoAlvo[strcspn(amigoAlvo, "\n")] = 0;

    No* listaPrincipal = NULL;
    char* token = strtok(amigosAtuais, " ");
    while (token != NULL) {
        inserirNoFim(&listaPrincipal, token);
        token = strtok(NULL, " ");
    }

    No* listaNovosAmigos = NULL;
    token = strtok(novosAmigos, " ");
    while (token != NULL) {
        inserirNoFim(&listaNovosAmigos, token);
        token = strtok(NULL, " ");
    }

    if (strcmp(amigoAlvo, "nao") == 0) {
        No* temp = listaPrincipal;
        if (temp == NULL) {
            listaPrincipal = listaNovosAmigos;
        } else {
            while (temp->proximo != NULL) {
                temp = temp->proximo;
            }
            temp->proximo = listaNovosAmigos;
        }
    } else {
        inserirAntes(&listaPrincipal, amigoAlvo, listaNovosAmigos);
    }

    imprimirLista(listaPrincipal);
    liberarLista(listaPrincipal);

    return 0;
}
