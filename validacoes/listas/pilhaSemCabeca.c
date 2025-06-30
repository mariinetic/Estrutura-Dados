#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int prato;
    struct No* prox;
} No;

No* topoPratos = NULL;

void empilharPrato(int p) {
    No* novoPrato = malloc(sizeof(No));
    novoPrato->prato = p;
    novoPrato->prox = topoPratos;
    topoPratos = novoPrato;
}

void desempilharPrato() {
    if (!topoPratos) return;
    No* temp = topoPratos;
    topoPratos = temp->prox;
    free(temp);
}

void mostrarPilhaDePratos() {
    printf("Pilha de pratos:\n");
    for (No* atual = topoPratos; atual; atual = atual->prox) {
        printf("Prato %d\n", atual->prato);
    }
}
