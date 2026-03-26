#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha
{
    int *item;
    int topo;
    int capacidade;
};

Pilha* criarPilha(int capacidadeInicial)
{
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));

    if (pilha)
    {
        pilha->item = (int*) malloc(capacidadeInicial * sizeof(int));

        if (pilha->item == NULL)
        {
            free(pilha);
            return NULL;
        }

        pilha->topo = -1;
        pilha->capacidade = capacidadeInicial;
    }

    return pilha;
}

int pilhaCheia(Pilha *pilha)
{
    return pilha->topo == pilha->capacidade - 1;
}

int pilhaVazia(Pilha *pilha)
{
    return pilha->topo == -1;
}

int aumentarCapacidade(Pilha *pilha)
{
    int novaCapacidade = pilha->capacidade * 2;

    int *novoVetor = realloc(pilha->item, novaCapacidade * sizeof(int));

    if (novoVetor == NULL)
        return ERROR;

    pilha->item = novoVetor;
    pilha->capacidade = novaCapacidade;

    return SUCCESS;
}

// Complexidade O(1)
int push(Pilha *pilha, int valor)
{
    if (pilhaCheia(pilha))
        if (aumentarCapacidade(pilha) == ERROR)
            return ERROR;

    pilha->topo++;
    pilha->item[pilha->topo] = valor;

    return SUCCESS;
}

// Complexidade O(1)
int pop(Pilha *pilha, int *valorRemovido)
{
    if (pilhaVazia(pilha))
        return ERROR;

    *valorRemovido = pilha->item[pilha->topo];
    pilha->topo--;

    return SUCCESS;
}

// Complexidade O(1)
int peek(Pilha *pilha, int *valorTopo)
{
    if (pilhaVazia(pilha))
        return ERROR;

    *valorTopo = pilha->item[pilha->topo];
    return SUCCESS;
}

void mostrarPilha(Pilha *pilha)
{
    if (pilhaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("\nTopo ->\n");

    for (int i = pilha->topo; i >= 0; i--)
        printf("%d\n", pilha->item[i]);
}

void liberarPilha(Pilha *pilha)
{
    free(pilha->item);
    free(pilha);
}