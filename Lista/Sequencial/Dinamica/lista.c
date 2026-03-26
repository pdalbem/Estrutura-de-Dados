#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define CAPACIDADE_INICIAL 2

struct lista {
    int *item;
    int quantidade;
    int capacidade;
};

// Criação
Lista *criarLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (!lista) return NULL;

    lista->item = (int*) malloc(CAPACIDADE_INICIAL * sizeof(int));
    if (!lista->item) {
        free(lista);
        return NULL;
    }

    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;

    return lista;
}

// Internas
int listaCheia(Lista *lista) {
    return lista->quantidade == lista->capacidade;
}

int listaVazia(Lista *lista) {
    return lista->quantidade == 0;
}

// Redimensionar (dobra capacidade)
int redimensionar(Lista *lista) {
    int novaCapacidade = lista->capacidade * 2;

    int *novo = (int*) realloc(lista->item, novaCapacidade * sizeof(int));
    if (!novo)
        return ERROR;

    lista->item = novo;
    lista->capacidade = novaCapacidade;

    return SUCCESS;
}

// Inserir (O(n))
int inserir(Lista *lista, int valor, int pos) {
    if (pos < 0 || pos > lista->quantidade)
        return ERROR;

    if (listaCheia(lista)) {
        if (redimensionar(lista) == ERROR)
            return ERROR;
    }

    for (int i = lista->quantidade; i > pos; i--)
        lista->item[i] = lista->item[i - 1];

    lista->item[pos] = valor;
    lista->quantidade++;

    return SUCCESS;
}

// Remover (O(n))
int remover(Lista *lista, int pos, int *valorRemovido) {
    if (listaVazia(lista))
        return ERROR;

    if (pos < 0 || pos >= lista->quantidade)
        return ERROR;

    *valorRemovido = lista->item[pos];

    for (int i = pos; i < lista->quantidade - 1; i++)
        lista->item[i] = lista->item[i + 1];

    lista->quantidade--;

    return SUCCESS;
}

// Buscar (O(n))
int buscar(Lista *lista, int valorProcurado, int *pos) {
    if (listaVazia(lista))
        return ERROR;

    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->item[i] == valorProcurado) {
            *pos = i;
            return SUCCESS;
        }
    }

    return ERROR;
}

// Mostrar
void mostrarLista(Lista *lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    for (int i = 0; i < lista->quantidade; i++)
        printf("\n %d ", lista->item[i]);
}

// Liberar
void liberarLista(Lista *lista) {
    free(lista->item);
    free(lista);
}