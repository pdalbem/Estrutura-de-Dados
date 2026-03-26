#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    int valor;
    struct no *prox;
} No;

struct pilha {
    No *topo;
};


Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p)
        p->topo = NULL;
    return p;
}


int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

// Empilhar (O(1))
int push(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo)
        return ERROR;

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;

    return SUCCESS;
}

// Desempilhar (O(1))
int pop(Pilha *p, int *valorRemovido) {
    if (pilhaVazia(p))
        return ERROR;

    No *temp = p->topo;
    *valorRemovido = temp->valor;

    p->topo = temp->prox;
    free(temp);

    return SUCCESS;
}

// Consulta topo (O(1))
int topo(Pilha *p, int *valor) {
    if (pilhaVazia(p))
        return ERROR;

    *valor = p->topo->valor;
    return SUCCESS;
}

// Mostrar pilha
void mostrarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    No *atual = p->topo;

    printf("Topo -> ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar memória
void liberarPilha(Pilha *p) {
    No *atual = p->topo;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(p);
}