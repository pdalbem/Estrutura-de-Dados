#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX_SIZE 5

struct lista
{
    int item[MAX_SIZE];
    int quantidade;
};

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista)
        lista->quantidade = 0;

    return lista;
}

int listaCheia(Lista *lista)
{
    return lista->quantidade == MAX_SIZE;
}

int listaVazia(Lista *lista)
{
    return lista->quantidade == 0;
}

// Complexidade linear O(n)
int inserir(Lista *lista, int valor, int pos)
{
    if (listaCheia(lista))
        return ERROR;

    if (pos < 0 || pos > lista->quantidade)
        return ERROR;

    // Move os elementos para a direita, se necessário, para abrir espaço para o novo valor
    for (int i = lista->quantidade; i > pos; i--)
        lista->item[i] = lista->item[i - 1];

    // Insere o valor na posição desejada
    lista->item[pos] = valor;
    lista->quantidade++;
    return SUCCESS;
}

// Complexidade linear O(n)
int remover(Lista *lista, int pos, int *valorRemovido)
{
    if (listaVazia(lista))
        return ERROR;

    if (pos < 0 || pos >= lista->quantidade)
        return ERROR;

    *valorRemovido = lista->item[pos];

    // Move os elementos para a esquerda, se necessário
    for (int i = pos; i < lista->quantidade - 1; i++)
        lista->item[i] = lista->item[i + 1];

    lista->quantidade--;
    return SUCCESS;
}

// Complexidade linear O(n)
int buscar(Lista *lista, int valorProcurado, int *pos)
{
    if (listaVazia(lista))
        return ERROR;

    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->item[i] == valorProcurado)
        {
            *pos = i;
            return SUCCESS;
        }
    }

    return ERROR;
}

// Complexidade linear O(n)
void mostrarLista(Lista *lista)
{
    if (listaVazia(lista))
        printf("Lista vazia.\n");
    else
        for (int i = 0; i < lista->quantidade; i++)
            printf("\n %d ", lista->item[i]);
}

void liberarLista(Lista *lista)
{
    free(lista);
}
