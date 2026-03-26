#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
    int valor;
    struct no *prox;
} No;

struct fila {
    No *inicio;
    No *fim;
};

// Criação
Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

// Verifica vazia (interna)
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Enfileirar (O(1))
int enfileirar(Fila *f, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo)
        return ERROR;

    novo->valor = valor;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
    return SUCCESS;
}

// Desenfileirar (O(1))
int desenfileirar(Fila *f, int *valorRemovido) {
    if (filaVazia(f))
        return ERROR;

    No *temp = f->inicio;
    *valorRemovido = temp->valor;

    f->inicio = temp->prox;

    // Se ficou vazia, atualiza o fim também
    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return SUCCESS;
}

// Consultar frente (O(1))
int frente(Fila *f, int *valor) {
    if (filaVazia(f))
        return ERROR;

    *valor = f->inicio->valor;
    return SUCCESS;
}

// Mostrar fila
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    No *atual = f->inicio;

    printf("Inicio -> ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL <- Fim\n");
}

// Liberar memória
void liberarFila(Fila *f) {
    No *atual = f->inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(f);
}