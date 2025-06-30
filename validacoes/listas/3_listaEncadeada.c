#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int candidato;
    struct No* proximo;
} No;

No* lista = NULL;

void inserirLista(int candidato) {
    No* novo = malloc(sizeof(No));
    novo->candidato = candidato;
    novo->proximo = lista;
    lista = novo;
}

void mostrarLista() {
    No* temp = lista;
    while (temp) {
        printf("Candidato: %d\n", temp->candidato);
        temp = temp->proximo;
    }
}

int main() {
    inserirLista(101);
    inserirLista(102);
    inserirLista(103);
    mostrarLista();
    return 0;
}
