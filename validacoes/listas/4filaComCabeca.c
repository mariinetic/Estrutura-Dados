#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int pessoa;
    struct No* proximo;
} No;

No* frente = NULL;
No* tras = NULL;

void enfileirar(int pessoa) {
    No* novo = malloc(sizeof(No));
    novo->pessoa = pessoa;
    novo->proximo = NULL;
    if (!tras) frente = tras = novo;
    else {
        tras->proximo = novo;
        tras = novo;
    }
}

void desenfileirar() {
    if (frente) {
        No* temp = frente;
        frente = frente->proximo;
        free(temp);
    }
}

void mostrarFila() {
    No* temp = frente;
    while (temp) {
        printf("Pessoa: %d\n", temp->pessoa);
        temp = temp->proximo;
    }
}

int main() {
    enfileirar(1);
    enfileirar(2);
    enfileirar(3);
    mostrarFila();
    desenfileirar();
    mostrarFila();
    return 0;
}
