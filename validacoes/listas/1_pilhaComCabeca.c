#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int prato;
    struct No* proximo;
} No;

void empilhar(No** topo, int prato) {
    No* novo = malloc(sizeof(No));
    novo->prato = prato;
    novo->proximo = *topo;
    *topo = novo;
}

void desempilhar(No** topo) {
    if (*topo) {
        No* temp = *topo;
        *topo = (*topo)->proximo;
        free(temp);
    }
}

void mostrarPilha(No* topo) {
    No* temp = topo;
    while (temp) {
        printf("Prato: %d\n", temp->prato);
        temp = temp->proximo;
    }
}

int main() {
    No* topo = NULL; 

    empilhar(&topo, 1);
    empilhar(&topo, 2);
    empilhar(&topo, 3);

    mostrarPilha(topo);

    desempilhar(&topo);

    mostrarPilha(topo);

    return 0;
}
