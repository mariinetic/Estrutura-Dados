#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int pessoa;
    struct No *proximo;
} No;

void enfileirar(No **frente, No **tras, int pessoa)
{
    No *novo = malloc(sizeof(No));
    novo->pessoa = pessoa;
    novo->proximo = NULL;

    if (*tras == NULL)
    {
        *tras = novo; 
        *frente = *tras;
    }
    else
    {
        (*tras)->proximo = novo;
        *tras = novo;
    }
}

void desenfileirar(No **frente, No **tras)
{
    if (*frente)
    {
        No *temp = *frente;
        *frente = (*frente)->proximo;
        if (*frente == NULL)
            *tras = NULL;
        free(temp);
    }
}

void mostrarFila(No *frente)
{
    No *temp = frente;
    while (temp)
    {
        printf("Pessoa: %d\n", temp->pessoa);
        temp = temp->proximo;
    }
}

int main()
{
    No *frente = NULL;
    No *tras = NULL;

    enfileirar(&frente, &tras, 1);
    enfileirar(&frente, &tras, 2);
    enfileirar(&frente, &tras, 3);
    mostrarFila(frente);
    desenfileirar(&frente, &tras);
    mostrarFila(frente);

    return 0;
}
